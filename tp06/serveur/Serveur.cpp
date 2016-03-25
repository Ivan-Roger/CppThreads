#include <iostream>
#include <thread>

#include "Serveur.hpp"
#include "EnvoiReception.hpp"

using namespace std;
using boost::asio::ip::tcp;

// TODO Bonus : déclarer une constante N pour le nombre maximal de clients connectés

Serveur::Serveur(unsigned short n_port) :
  socket_ecoute(service_es,
		tcp::endpoint(tcp::v4(), n_port)),
	clients()
{}


[[noreturn]] void Serveur::attend_clients(void)
{
  cout<<"Adresse IP et n° de port côté serveur : "<<socket_ecoute.local_endpoint()<<endl;
  cout<<"En attente d'un client..."<<endl;

  // boucle infinie pour attendre les nouveaux clients
  while(true) {

    // TODO: à compléter
    //  - créer un objet ClientConnecte
    //  - attendre une connexion TCP
    //  - stocker l'objet ClientConnecte dans la map
    //  - démarrer le thread associé
		ClientConnecte c(next_client_id,*this);
		socket_ecoute.accept(c.sock);

		unique_lock<mutex> ul(m_clients);
		clients.emplace(next_client_id,move(c));
		ClientConnecte& cl = clients.at(next_client_id);
		ul.unlock();

		thread t(ThreadClient(cl,next_client_id));
		t.detach();

    // TODO: à compléter : afficher les paramètres IP du client
		{
			lock_guard<mutex> lg(m_cout);
			cout<<"Nouveau client("<<next_client_id<<"): "<<cl.sock.remote_endpoint()<<endl;
		}

    // TODO: à compléter: envoyer au client son numéro
		EnvoiReception::envoyer_entier(cl.sock,next_client_id);

    // TODO V2: à compléter: annoncer à tous les clients l'arrivée d'un nouveau client
		broadcast_message(0,"Connexion client("+to_string(next_client_id)+")");

    // TODO: à compléter: lancer le thread ThreadClient
		{
			lock_guard<mutex> lg(m_cout);
    	cout<<"Nombre de clients : "<<nb_clients()<<endl;
		}
		next_client_id++;
  }
}

// pas const car on modifie un mutex
unsigned long Serveur::nb_clients(void)
{
  // TODO: à compléter en pensant à l'exclusion mutuelle
	lock_guard<mutex> lg(m_clients);
  return clients.size();
}

void Serveur::broadcast_message(unsigned long numero_client, const std::string& chaine)
{
  // TODO V2: à compléter: exclusion mutuelle
	lock_guard<mutex> lg(m_clients);
  // TODO V2: à remplacer: parcourir la map et envoyer la chaîne à tous les *autres* clients
	for (auto& i: clients) {
		if (i.first!=numero_client) {
			EnvoiReception::envoyer_entier(i.second.sock,numero_client);
			EnvoiReception::envoyer_chaine(i.second.sock,chaine);
		}
	}
}
