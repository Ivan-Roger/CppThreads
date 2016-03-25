#ifndef MON_THREAD_HPP_
#define MON_THREAD_HPP_

#include <vector>

#include "Calculateur.hpp"

class MonThread
{
public :
  MonThread(const unsigned long numero_, Calculateur& calculateur_);
  void operator()();

private :
  const unsigned long numero;
  Calculateur& calculateur;
};

#endif // MON_THREAD_HPP_
