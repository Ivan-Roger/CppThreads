#ifndef SERVEUR_HPP_
#define SERVEUR_HPP_

#include <boost/asio.hpp>
#include <mutex>

#include "ThreadClient.hpp"
#include "ClientConnecte.hpp"

class Serveur {
public :
  Serveur(unsigned short n_port);


  [[noreturn]] void attend_clients(void);
  unsigned long nb_clients(void);
  void broadcast_message(unsigned long numero_client, const std::string& chaine_recue);

private :
  boost::asio::io_service service_es;
  boost::asio::ip::tcp::acceptor socket_ecoute;

  // TODO: à compléter: attribut numero_nouveau_client
	unsigned long next_client_id = 1;

  // TODO: à compléter: mutex pour cout
	std::mutex m_cout;

  // TODO: à compléter: std::map et mutex associé
	std::map<unsigned long, ClientConnecte> clients;
	std::mutex m_clients;

  // pour faciliter les accès depuis ces autres classes
  friend class ThreadClient;
  friend class ClientConnecte;
};

#endif // SERVEUR_HPP_
