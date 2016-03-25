#include <iostream>
#include <thread>
#include <chrono>

#include "Androide.hpp"
#include "Ecran.hpp"
#include "SequenceEntiere.hpp"

using namespace std;
using namespace std::chrono;

int const Androide::COTE_ESPACE = 20; // l'espace à inspecter est un carré de 20 unités de côté

Androide::Androide(SequenceEntiere& seq_, Ecran& ecran_) :
  numero(0), // valeur arbitraire en attendant le démarrage du thread
  seq(seq_),
  ecran(ecran_)
{}

static void maj_coord(int& coord)
{
  coord += rand()%3 - 1;
}

void Androide::marche_aleatoire(void)
{
  int x = 5 + rand()%COTE_ESPACE;
  int y = 5 + rand()%COTE_ESPACE;

  for (int i = 0; i < 20; i++)
  {
    ecran.efface_car(x,y);
    maj_coord(x);
    maj_coord(y);
    ecran.affiche_car(static_cast<char>(numero+'0'),x,y);
    this_thread::sleep_for(milliseconds(500));
  }
  ecran.affiche_car('*',x+1,y);
}

void Androide::operator()()
{
  // récupération d'un numéro unique parmi 0,1,...
  numero = seq.nouveau_numero();

  // mis en action de l'androïde
  marche_aleatoire();
}
