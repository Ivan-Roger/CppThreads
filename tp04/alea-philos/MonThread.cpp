#include <vector>

#include "Calculateur.hpp"
#include "MonThread.hpp"

using namespace std;

MonThread::MonThread(const unsigned long numero_, Calculateur& calculateur_) :
  numero(numero_),
  calculateur(calculateur_)
{}

void MonThread::operator()()
{
  calculateur.calculer(numero);
}
