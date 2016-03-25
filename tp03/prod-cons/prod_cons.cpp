#include <iostream>
#include <thread>
#include <vector>

#include "EcranManchots.hpp"
#include "Tampon.hpp"
#include "Producteur.hpp"
#include "Consommateur.hpp"

using namespace std;

int main(int argc, char*argv[])
{

  if (argc-1 != 5)
  {
    cerr << "Usage : " << argv[0] << " nb_producteurs nb_elem_prod nb_consommateurs nb_elem_cons nb_cases_tampon" << endl;
    throw;
  }

  unsigned long nb_prod = stoul(argv[1]);
  unsigned long nb_elem_prod = stoul(argv[2]);
  unsigned long nb_cons = stoul(argv[3]);
  unsigned long nb_elem_cons = stoul(argv[4]);
  unsigned int taille = static_cast<unsigned int>(stoul(argv[5])); //cast nec. pour utilisation avec sémaphore

  EcranManchots ecran(nb_prod,taille,nb_cons,nb_elem_cons);

  Tampon tampon(taille,ecran);

  // création des threads
  vector<thread> mes_threads;
  for (unsigned long i=0; i < nb_cons; i++)
    mes_threads.push_back(thread(Consommateur(i+1, nb_elem_cons, tampon)));

  for (unsigned long i=0; i < nb_prod; i++)
    mes_threads.push_back(thread(Producteur(i+1, nb_elem_prod, tampon)));

  // attente de la terminaison des threads
  for (unsigned long i=0; i < nb_cons+nb_prod; i++)
    mes_threads.at(i).join();

  getchar();

  return EXIT_SUCCESS;
}
