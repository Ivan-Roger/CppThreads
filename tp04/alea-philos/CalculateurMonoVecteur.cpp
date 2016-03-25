#include <random>

#include "Tableau.hpp"
#include "Calculateur.hpp"

#include "CalculateurMonoVecteur.hpp"

using namespace std;

CalculateurMonoVecteur::CalculateurMonoVecteur(const unsigned long nb_iter_, Tableau& tableau_) :
  Calculateur(nb_iter_, tableau_)
{}

void CalculateurMonoVecteur::calculer(const unsigned long numero)
{
  uniform_int_distribution<int> dis(0,1);
  int poids_somme,poids_multiplication;
  for (unsigned long n=0; n<nb_iter; n++)
  {
    tableau.reserver(numero,n,poids_somme,poids_multiplication);
    if (dis(tableau.gen)==0) // tableau aléatoire pour varier l'ordre des opérations
    {
      sommer(tableau.vecteurs[numero], poids_somme);
      multiplier(tableau.vecteurs[numero], poids_multiplication);
    }
    else
    {
      multiplier(tableau.vecteurs[numero], poids_multiplication);
      sommer(tableau.vecteurs[numero], poids_somme);
    }
    tableau.liberer(numero);
  }
}
