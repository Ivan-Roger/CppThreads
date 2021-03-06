#ifndef THREAD_LECTURE_HPP_
#define THREAD_LECTURE_HPP_

#include <boost/asio.hpp>

class ThreadLecture
{
public :
  ThreadLecture(boost::asio::ip::tcp::socket& sock_, std::string prompt_);
  [[noreturn]] void lire_clavier_et_envoyer_messages(void);
  [[noreturn]] void operator()(void);

private :
  boost::asio::ip::tcp::socket& sock;
	std::string prompt;
};

#endif // THREAD_LECTURE_HPP_
