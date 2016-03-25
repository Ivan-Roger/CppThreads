#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include <boost/asio.hpp>
#include <string>


class Client {
public :
  Client(std::string nom, unsigned short n_port);
  void dialogue_avec_serveur(void);
	std::string prompt="Client> ";

private :
  boost::asio::io_service service_es;
  boost::asio::ip::tcp::socket sock;
};

#endif // CLIENT_HPP_
