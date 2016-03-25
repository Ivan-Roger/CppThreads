#ifndef MONTHREAD_HPP_
#define MONTHREAD_HPP_

#include "SequenceEntiere.hpp"
#include "Ecran.hpp"

// Classe avec opérateur parenthèses défini
class Androide
{
public :
  Androide(SequenceEntiere& seq_, Ecran& ecran_);
  void operator()();

private :
  unsigned long numero;
  SequenceEntiere& seq;
  Ecran& ecran;

  static int const COTE_ESPACE; // l'espace à inspecter est un carré de COTE_ESPACE unités de côté

  void marche_aleatoire(void);
};

#endif // MONTHREAD_HPP_
