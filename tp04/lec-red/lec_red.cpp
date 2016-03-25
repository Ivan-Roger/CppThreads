#include <iostream>
#include <vector>
#include <thread>

#include "Lecteur.hpp"
#include "Redacteur.hpp"
#include "Outils.hpp"
#include "OutilsShared.hpp"
#include "OutilsCond.hpp"

using namespace std;

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    cerr << "Usage : " << argv[0] << " {shared|cond}" << endl;
    throw;
  }

  // outils partagés pour la synchronisation
  Outils* outils_synchro;

  // affichage de l'en-tête
  for (unsigned long i=0; i < Lecteur::nb_lec; i++)
    cout << "  Lec." << i+1 << "  ";
  for (unsigned long i=0; i < Redacteur::nb_red; i++)
    cout << "  Red." << i+1 << "  ";
  cout << endl;

  if (string(argv[1])=="shared")
  {
    outils_synchro=new OutilsShared();
  }
  else if (string(argv[1])=="cond")
  {
    outils_synchro=new OutilsCond();
  }
  else
  {
    cerr << "Usage : " << argv[0] << " {shared|cond}" << endl;
    throw;
  }

  // création des threads
  vector<thread> mes_threads;

  for (unsigned long i=0; i < Lecteur::nb_lec; i++)
    mes_threads.push_back(thread(Lecteur(i,*outils_synchro)));

  for (unsigned long i=0; i < Redacteur::nb_red; i++)
    mes_threads.push_back(thread(Redacteur(i,*outils_synchro)));

  // attente des threads
  for (unsigned long i=0; i < Lecteur::nb_lec+Redacteur::nb_red; i++)
    mes_threads.at(i).join();

  delete outils_synchro;

  return EXIT_SUCCESS;
}
