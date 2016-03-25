#ifndef MONTHREAD_HPP_
#define MONTHREAD_HPP_

#include <mutex>
#include "RessourceProtegee.hpp"

// Classe avec opérateur parenthèses défini
class MonThread
{
public :
  MonThread(const unsigned long numero_, RessourceProtegee& ressource_, const bool une_sc_par_thread_);
  void operator()();

private :
  const unsigned long numero;
  RessourceProtegee& ressource;
  const bool une_sc_par_thread;

  // pour l'affichage : la sortie standard doit être utilisée en exclusion mutuelle
  static std::mutex mutex_flux_sortie;

public :
  void afficher_message_fin(void);
};

#endif // MONTHREAD_HPP_
