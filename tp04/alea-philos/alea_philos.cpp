#include <iostream>
#include <vector>
#include <thread>

#include "Tableau.hpp"
#include "TableauSansSynchro.hpp"
#include "TableauMutex.hpp"
#include "TableauCond.hpp"
#include "Calculateur.hpp"
#include "CalculateurMonoVecteur.hpp"
#include "CalculateurBiVecteur.hpp"
#include "MonThread.hpp"

using namespace std;

static void usage(const char* nom)
{
  cerr << "Usage : " << nom << "{mono|bimutex|bicond} nb_iter/2" << endl;
}

int main(int argc, char* argv[])
{
  if (argc != 3)
  {
    usage(argv[0]);
    throw;
  }

  const unsigned long nb_iter = 2*stoul(argv[2]);

  // pointeur vers le tableau aléatoire partagé avec ou sans outils de synchronisation
  Tableau* tableau;

  // pointeur vers un calculateur-type avec sa méthode de calcul sur un ou deux Vecteur
  Calculateur* calculateur;

  // création du tableau et du calculateur-type
  if (string(argv[1])=="mono")
  {
    tableau = new TableauSansSynchro();
    calculateur = new CalculateurMonoVecteur(nb_iter,*tableau);
  }
  else if (string(argv[1])=="bimutex")
  {
    tableau = new TableauMutex();
    calculateur = new CalculateurBiVecteur(nb_iter,*tableau);
  }
  else if (string(argv[1])=="bicond")
  {
    tableau = new TableauCond();
    calculateur = new CalculateurBiVecteur(nb_iter,*tableau);
  }
  else
  {
      usage(argv[0]);
      throw;
  }

  // création des threads
  vector<thread> mes_threads;
  for (unsigned long i=0; i < Tableau::NB_VALEURS; i++)
    mes_threads.push_back(thread(MonThread(i,*calculateur)));

  // attente des threads
  for (unsigned long i=0; i < Tableau::NB_VALEURS; i++)
    mes_threads.at(i).join();

  // vérification de l'état final du tableau
  tableau->afficher_etat_final();

  delete tableau;
  delete calculateur;

  return EXIT_SUCCESS;
}
