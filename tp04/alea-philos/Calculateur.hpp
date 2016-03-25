#ifndef CALCULATEUR_HPP_
#define CALCULATEUR_HPP_

#include <vector>

#include "Tableau.hpp"

class Calculateur
{
public :
  Calculateur(const unsigned long nb_iter_, Tableau& tableau_);
  virtual ~Calculateur(); // nécessaire avec méthode virtuelle

  virtual void calculer(const unsigned long) = 0;

protected :
  const unsigned long nb_iter;
  Tableau& tableau;

  void sommer(std::vector<int>& vecteur, const int poids);
  void multiplier(std::vector<int>& vecteur, const int poids);
};

#endif // CALCULATEUR_HPP_
