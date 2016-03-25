#ifndef AUTO_HPP_
#define AUTO_HPP_
#include <random>

#include "Carrefour.hpp"

// Classe avec opérateur parenthèses défini
class Auto
{
public :
  Auto(const unsigned long numero_, const int voie_, Carrefour &carrefour_, const bool alea);
  void operator()();

private :
  const unsigned long numero;
  const int voie;
  Carrefour& carrefour;
  static std::chrono::duration<double> const dureeAvantArrivee;
  static std::chrono::duration<double> const dureeAvantFeu;
  static std::chrono::duration<double> const dureeTraversee;

  // générateur aléatoire
  static std::default_random_engine gen;
};

#endif // AUTO_HPP_
