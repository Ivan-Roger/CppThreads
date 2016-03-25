#include <iostream>
#include <iomanip>
#include <vector>
#include <stdlib.h>

#include "Tableau.hpp"

using namespace std;

Tableau::Tableau() :
  vecteurs(vector<vector<int>>(NB_VALEURS,
                               vector<int>(1000000,0))),
  tickets(vector<int>(NB_VALEURS,-1))
{}

Tableau::~Tableau() = default; // nécessaire avec méthode virtuelle

// Pour chaque vecteur du tableau, un nombre d'étoiles correspondant à la valeur
// commune des entrées est affiché.
// Si, à la fin des traitements, toutes les entrées d'un vecteur ne sont pas égales
// une exception est levée.
void Tableau::afficher_etat_final(void)
{
  int valeur_commune;
  unsigned long j;
  for (unsigned long i=0; i<vecteurs.size(); i++)
  {
    cout << "vecteur n°" << setfill(' ') << setw(2) << i << " : ";
    valeur_commune=vecteurs.at(i).at(0);
    for (j=1; j<vecteurs.at(i).size() && valeur_commune == vecteurs.at(i).at(j); j++)
      ;
    if (j != vecteurs.at(i).size())
    {
      cout << "non homogène" << endl;
      throw;
    }
    cout << setfill('*') << setw(abs(valeur_commune)+1) << " " << endl;
  }
}

// On impose la contrainte suivante : chaque calculateur ne peut faire qu'une réservation par itération
// pour traiter le ou les vecteurs sur lesquelles il travaille.
void Tableau::verifier_une_reservation_par_iteration(const unsigned long numero, const unsigned long iter)
{
  const int iter_i = static_cast<int>(iter);
  if (tickets.at(numero)==iter_i-1)
    tickets.at(numero)=iter_i;
  else if (tickets.at(numero)>=iter_i)
  {
    cerr << "Le thread n°" << numero << " a déjà retiré son ticket de réservation pour l'itération " << iter << endl;
    throw;
  }
  else
  {
    cerr << "Le thread n°" << numero << " ne retire pas ses tickets de réservation dans l'ordre." << endl;
    throw;
  }
}

// récupération des poids pour l'itération
void Tableau::recuperer_poids(const unsigned long iter, int& poids_somme, int& poids_multiplication)
{
  poids_somme = 2-3*(iter%2);
  poids_multiplication =  3-3*(iter%2);
}

// Le tableau est cylindrique : la suite des vecteurs est circulaire.
unsigned long Tableau::gauche(const unsigned long numero)
{
  return (numero+NB_VALEURS-1)%NB_VALEURS;
}

unsigned long Tableau::droite(const unsigned long numero)
{
  return (numero+1)%NB_VALEURS;
}
