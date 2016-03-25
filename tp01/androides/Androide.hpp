#ifndef MONTHREAD_HPP_
#define MONTHREAD_HPP_

#include <random>
#include "Ecran.hpp"

// Classe avec opérateur parenthèses défini
class Androide
{
public :
  Androide(unsigned long numero_,unsigned long& latence_,Ecran& ecran_);
	
  static int const COTE_ESPACE; // l'espace à inspecter est un carré de COTE_ESPACE unités de côté
  static std::default_random_engine gen;  // générateur aléatoire
	void operator()();

private :
	unsigned long numero;
	unsigned long& latence;
  Ecran& ecran;

  void marche_aleatoire(void);
};

#endif // MONTHREAD_HPP_
