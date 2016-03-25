#include <thread>
#include <chrono>

#include "Auto.hpp"
#include "Carrefour.hpp"

using namespace std;
using namespace std::chrono;

duration<double> const Auto::dureeAvantArrivee(milliseconds(900));
duration<double> const Auto::dureeAvantFeu(milliseconds(100));
duration<double> const Auto::dureeTraversee(milliseconds(100)); // 100 ou 2000 selon la question

default_random_engine Auto::gen;

Auto::Auto(const unsigned long numero_, const int voie_, Carrefour& carrefour_, const bool alea) :
  numero(numero_),
  voie(voie_),
  carrefour(carrefour_)
{
  if(alea) {
    uniform_int_distribution<int> dis(1,3);
    this_thread::sleep_for(dis(gen)*dureeAvantArrivee);
  }
  else {
    this_thread::sleep_for(dureeAvantArrivee);
  }
}

void Auto::operator()() {
  carrefour.afficherMessageAuto(voie, numero, " ARRIVE");
  this_thread::sleep_for(dureeAvantFeu); // le temps d'arriver au feu

  carrefour.reserver(voie);

  carrefour.afficherMessageAuto(voie, numero, " TRAVERSE");
  this_thread::sleep_for(dureeTraversee); // le temps de traverser
  carrefour.afficherMessageAuto(voie, numero, " QUITTE");

  carrefour.liberer(voie);
}
