#include <iostream>
#include <string>

#include "ThreadReception.hpp"
#include "EnvoiReception.hpp"
#include "Client.hpp"

using namespace std;

ThreadReception::ThreadReception(boost::asio::ip::tcp::socket& sock_, std::string prompt_) :
  sock(sock_),
	prompt(prompt_)
{ }

[[noreturn]] void ThreadReception::recevoir_et_afficher_messages(void)
{
  try {
    while(true) {
      // Réception d'un message (émetteur,texte)
      // TODO: à compléter/remplacer
      unsigned long numero=EnvoiReception::recevoir_entier(sock);
      string chaine_recue=EnvoiReception::recevoir_chaine(sock);

      // Affichage de l'émetteur et du texte
      cout<<"\r"; // fin de ligne pour afficher en dessous du prompt
      if(numero==0)
				cout<<"Serveur> "<<chaine_recue<<endl;
      else
				cout<<"Client("+to_string(numero)+")> "+chaine_recue<<endl;
      cout<<prompt<<flush; // on ré-affiche le "prompt"
    }
  }
  catch(exception& e) {
    cerr<<"Exception dans le thread de réception : "<<e.what()<<endl;
  }
  cout<<"Connexion au serveur perdue.  Fin du programme."<<endl;
  exit(0); // évite un vilain message d'erreur du thread principal
}

[[noreturn]] void ThreadReception::operator()(void) {
  recevoir_et_afficher_messages();
}
