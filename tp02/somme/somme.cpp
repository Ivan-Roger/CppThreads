#include <iostream>
#include <iomanip>
#include <thread>
#include <vector>

#include "RessourceProtegee.hpp"
#include "MonThread.hpp"

/*-------------------------------------------------------------------------------
 * Macro pour éviter les warnings "unused ..." dans une version intermédiaire.
 * A enlever lorsqu'elle n'est plus utilisée.
 * -----------------------------------------------------------------------------*/
//#define UNUSED(x) (void)(x)

using namespace std;

mutex RessourceProtegee::mon_mutex;

int main(void)
{
  const unsigned long nb_threads = 30;


  // ressource partagée dont les accès doivent être protégés
  RessourceProtegee ressource(0);

  // option d'exécution
  const bool une_sc_par_thread = true;

  // création des threads
  vector<thread> mes_threads;
  //--TODO-- à remplacer --TODO--/
	for (unsigned long i=0; i<nb_threads; i++) {
		mes_threads.push_back(thread(MonThread(i,ressource, une_sc_par_thread)));
	}
  //-----------------------------/

  // attente des threads
  //--TODO-- à compléter --TODO--/
	for (unsigned long i=0; i<nb_threads; i++) {
		mes_threads[i].join();
	}
  //-----------------------------/

  cout << "À la fin,            total = " << setw(9) << ressource.acces_non_protege() << endl;

  return EXIT_SUCCESS;
}
