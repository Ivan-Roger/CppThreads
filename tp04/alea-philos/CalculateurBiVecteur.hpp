#ifndef CALCULATEUR_BI_VECTEUR_HPP_
#define CALCULATEUR_BI_VECTEUR_HPP_

#include "Tableau.hpp"
#include "Calculateur.hpp"

class CalculateurBiVecteur : public Calculateur
{
public :
  CalculateurBiVecteur(const unsigned long nb_iter_, Tableau& tableau_);

  void calculer(const unsigned long numero);
};

#endif // CALCULATEUR_BI_VECTEUR_HPP_
