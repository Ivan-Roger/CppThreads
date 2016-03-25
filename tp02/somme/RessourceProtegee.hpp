#ifndef RESSOURCE_PROTEGEE_HPP_
#define RESSOURCE_PROTEGEE_HPP_

//--TODO-- à compléter --TODO--/
#include <mutex>
//-----------------------------/

class RessourceProtegee
{
public :
  RessourceProtegee(unsigned long total_);

  static unsigned long const NB_INCR = 1000000;

  // méthodes manipulant de façon sûre les variables partagées entre les threads
  void incrementer_avec_une_sc(void);
  void incrementer_avec_pls_sc(void);

  // méthode donnant un accès non protégé à la ressource
  unsigned long acces_non_protege(void);
	static std::mutex mon_mutex;

private :
  // variables partagées entre les threads
  //--TODO-- à compléter --TODO--/
  unsigned long total;
  //-----------------------------/
};

#endif // RESSOURCE_PROTEGEE_HPP_
