#ifndef MONTHREAD_HPP_
#define MONTHREAD_HPP_

// Classe avec opérateur parenthèses défini
class MonThread
{
public :
  MonThread(unsigned long numero);
  void operator()();

private :
  unsigned long m_numero;
};

#endif // MONTHREAD_HPP_
