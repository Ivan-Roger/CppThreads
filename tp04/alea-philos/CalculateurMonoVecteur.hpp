#ifndef CALCULATEUR_MONO_VECTEUR_HPP_
#define CALCULATEUR_MONO_VECTEUR_HPP_

#include "Tableau.hpp"
#include "Calculateur.hpp"

class CalculateurMonoVecteur : public Calculateur
{
public :
  CalculateurMonoVecteur(const unsigned long nb_iter_, Tableau& tableau_);

  void calculer(const unsigned long numero);
};

#endif // CALCULATEUR_MONO_VECTEUR_HPP_
