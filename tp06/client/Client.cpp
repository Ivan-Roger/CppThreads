#include <iostream>
#include <thread>
#include <boost/asio.hpp>

#include "Client.hpp"
#include "EnvoiReception.hpp"
#include "ThreadReception.hpp"
#include "ThreadLecture.hpp"

using namespace std;

Client::Client(std::string nom, unsigned short n_port) :
  sock(service_es)
{
  // résolution DNS
  boost::asio::ip::tcp::resolver requeteur(service_es);
  boost::asio::ip::tcp::resolver::query requete(nom,to_string(n_port));
  boost::asio::ip::tcp::resolver::iterator iter = requeteur.resolve(requete);
  boost::asio::ip::tcp::endpoint point_distant=*iter; // on prend la 1ère adresse IP (dans le cas où le DNS en donne plusieurs)

  cout<<"Connexion: "<<point_distant<<" ..."<<endl;
  // connexion au serveur
  sock.connect(point_distant);
  cout<<"Lien établi."<<endl;

  cout<<"Adresse IP et n° de port côté client : "<<sock.local_endpoint()<<endl;
}

void Client::dialogue_avec_serveur(void)
{
  // TODO: à compléter : initialisation du n° de client avec le numéro envoyé par le serveur
  cout<<"Réception du numéro de client..."<<endl;
  unsigned long entier_recu=EnvoiReception::recevoir_entier(sock);
  prompt="Client("+to_string(entier_recu)+")> ";

  // TODO: à compléter V1: appel de la méthode ThreadLecture::lire_clavier_et_envoyer_messages()
	/*
	ThreadLecture input(sock);
	input.lire_clavier_et_envoyer_messages();
	*/
  //                   V2: lancer les 2 threads du client
	thread tL( (ThreadLecture(sock,prompt)) );
	thread tR( (ThreadReception(sock,prompt)) );

  // TODO: à compléter V2: attendre la fin du thread de lecture
	tL.join();
  // on fait un join() pour occuper le thread principal
  // mais le programme sera arrêté par un exit() dans l'un des 2 threads secondaires
}
