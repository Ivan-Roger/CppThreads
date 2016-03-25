#include "Tableau.hpp"
#include "Calculateur.hpp"

#include "CalculateurBiVecteur.hpp"

using namespace std;

CalculateurBiVecteur::CalculateurBiVecteur(const unsigned long nb_iter_, Tableau& tableau_) :
  Calculateur(nb_iter_, tableau_)
{}

void CalculateurBiVecteur::calculer(const unsigned long numero)
{
  // chaque calculateur travaille sur deux vecteurs voisins.
  // chaque vecteur est traité par deux calculateurs voisins.
  const unsigned long autre_numero = (numero+1)%Tableau::NB_VALEURS;
  int poids_somme, poids_multiplication;
  for (unsigned long n=0; n<nb_iter; n++)
  {
    tableau.reserver(numero,n,poids_somme,poids_multiplication);
    if (numero%2==0) // additionneur
    {
      sommer(tableau.vecteurs[numero],poids_somme);
      sommer(tableau.vecteurs[autre_numero],poids_somme);
    }
    else // multiplicateur
    {
      multiplier(tableau.vecteurs[autre_numero],poids_multiplication);
      multiplier(tableau.vecteurs[numero],poids_multiplication);
    }
    tableau.liberer(numero);
  }
}
