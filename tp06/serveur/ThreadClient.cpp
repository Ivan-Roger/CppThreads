#include <iostream>
#include <mutex>
#include <sys/syscall.h>

#include "ThreadClient.hpp"
#include "Serveur.hpp"
#include "EnvoiReception.hpp"

using namespace std;

ThreadClient::ThreadClient(ClientConnecte& client_, unsigned long numero_client_) :
  client(client_),
  serveur(client_.serveur),
  numero_client(numero_client_)
{ }

void ThreadClient::dialogue_avec_client(void)
{
	{
		lock_guard<mutex> lg(serveur.m_cout);
		cout<<"Démarrage client("<<numero_client<<"): "<<client.sock.remote_endpoint()<<" (TID="<<syscall(SYS_gettid)<<")"<<endl;
	}
  try {
    while(true) {
      // TODO: à compléter: réception d'une chaîne
      string chaine_recue=EnvoiReception::recevoir_chaine(client.sock);

			{
				lock_guard<mutex> lg(serveur.m_cout);
				cout<<"Client "<<numero_client<<" : "<<chaine_recue<<endl;
			}

      serveur.broadcast_message(numero_client,chaine_recue);
    }
  }
  catch(exception& e) {
		lock_guard<mutex> lg(serveur.m_cout);
		cerr<<"Exception dans un thread: "<<e.what()<<endl;
  }
	{
		lock_guard<mutex> lg(serveur.m_cout);
		cout<<"Client("<<numero_client<<") déconnecté : "<<client.sock.remote_endpoint()<<endl;
		cout<<"Suppression ..."<<endl;
	}

  // TODO: à compléter: enlever le client de la map, en exclusion mutuelle
	{
		lock_guard<mutex> lg(serveur.m_clients);
		serveur.clients.erase(numero_client);
	}

  serveur.broadcast_message(0,"Déconnexion du client n°"+to_string(numero_client)); // 0 = n° spécial représentant le serveur
	{
		lock_guard<mutex> lg(serveur.m_cout);
		cout<<"Nombre de clients restants : "<<serveur.nb_clients()<<endl;
  	cout<<"Fin du thread de TID "<<syscall(SYS_gettid)<<" associé au client n°"<<numero_client<<endl;
	}

}

void ThreadClient::operator()(void)
{
  dialogue_avec_client();
}
