#include <iostream>
#include <iomanip>
#include <mutex>

#include "MonThread.hpp"

using namespace std;

MonThread::MonThread(const unsigned long numero_, RessourceProtegee& ressource_, bool une_sc_par_thread_) :
  numero(numero_),
  ressource(ressource_),
  une_sc_par_thread(une_sc_par_thread_)
{}

void MonThread::operator()()
{
  if (une_sc_par_thread)
  {
    ressource.incrementer_avec_une_sc();
  }
  else
  {
    ressource.incrementer_avec_pls_sc();
  }

  afficher_message_fin();
}

// pour l'affichage : la sortie standard doit être utilisée en exclusion mutuelle
mutex MonThread::mutex_flux_sortie;

void MonThread::afficher_message_fin(void)
{
  lock_guard<mutex> verrou(mutex_flux_sortie);
  cout << "Thread numéro " << setw(3) << numero ;
  cout << ": j'ai fait "<< setw(9) << RessourceProtegee::NB_INCR << " incrémentations." << endl;
}
