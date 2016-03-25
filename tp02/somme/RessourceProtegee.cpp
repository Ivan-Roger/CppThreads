//--TODO-- à compléter --TODO--/
//-----------------------------/

#include "RessourceProtegee.hpp"

RessourceProtegee::RessourceProtegee(unsigned long total_) :
  total(total_)
{}

void RessourceProtegee::incrementer_avec_une_sc(void)
{
  //--TODO-- à compléter --TODO--/
	mon_mutex.lock();
  for (unsigned long i=0; i<NB_INCR; i++)
  {
    total++;
  }
	mon_mutex.unlock();
  //-----------------------------/
}

void RessourceProtegee::incrementer_avec_pls_sc(void)
{
  //--TODO-- à compléter --TODO--/
  for (unsigned long i=0; i<NB_INCR; i++)
  {
		mon_mutex.lock();
    total++;
		mon_mutex.unlock();
  }
  //-----------------------------/
}

// méthode donnant un accès non protégé à la ressource :
// le thread appelant cette méthode doit être seul à s'exécuter
unsigned long RessourceProtegee::acces_non_protege(void)
{
  return total;
}
