#include <vector>
#include <thread>
#include <chrono>

#include "Tableau.hpp"
#include "Calculateur.hpp"

using namespace std;
using namespace std::chrono;

static duration<double> const tempo(milliseconds(500));

Calculateur::Calculateur(const unsigned long nb_iter_, Tableau& tableau_) :
  nb_iter(nb_iter_),
  tableau(tableau_)
{}

Calculateur::~Calculateur() = default;     // nécessaire avec methode virtuelle


void Calculateur::sommer(vector<int>& vecteur, const int poids)
{
  for (unsigned long i=0; i<vecteur.size(); i++)
      vecteur.at(i)+=poids;
}

void Calculateur::multiplier(vector<int>& vecteur, const int poids)
{
  for (unsigned long i=0; i<vecteur.size(); i++)
    vecteur.at(i)*=poids;
}
