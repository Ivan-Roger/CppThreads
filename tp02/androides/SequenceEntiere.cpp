#include <thread>
#include <chrono>
//--TODO-- à compléter --TODO--/
//-----------------------------/

#include "SequenceEntiere.hpp"

using namespace std;

SequenceEntiere::SequenceEntiere(unsigned int numero_initial) :
  numero(numero_initial), mon_mutex()
{}

unsigned int SequenceEntiere::nouveau_numero(void)
{
  //--TODO-- à compléter --TODO--/
	mon_mutex.lock();
  unsigned int resultat = numero++;
	mon_mutex.unlock();
	// ne pas enlever cette temporisation
  this_thread::sleep_for(chrono::milliseconds(100));
  //-----------------------------/
  return resultat;
}
