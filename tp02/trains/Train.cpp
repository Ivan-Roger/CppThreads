#include <thread>
#include <chrono>

#include "Trajet.hpp"
#include "Positions.hpp"

#include "Train.hpp"

using namespace std;
using namespace std::chrono;

Train::Train(const unsigned long numero_, Positions& positions_) :
  numero(numero_),
  trajet(positions_.getTrajet(numero_)),
  positions(positions_)
{}


void Train::operator()()
{
  ///// NE PAS MODIFIER LES DEUX  LIGNES SUIVANTES //////////////////////////////
  this_thread::sleep_for(numero*milliseconds(250));
  positions.sePreparer(numero);
  ///////////////////////////////////////////////////////////////////////////////

	if (trajet.departAvantArrivee()) {
		trajet.reserverDepart();
	} else {
	  trajet.reserverArrivee();
		trajet.reserverDepart();
	}

  ///// NE PAS MODIFIER LES TROIS LIGNES SUIVANTES //////////////////////////////
  positions.partir(numero);
  this_thread::sleep_for(seconds(1)); // le temps de circuler sur la 1ère voie
  positions.arriverJonction(numero);

  trajet.libererDepart();
	if (trajet.departAvantArrivee())
		trajet.reserverArrivee();
	
  ///////////////////////////////////////////////////////////////////////////////
  ///// NE PAS MODIFIER LES TROIS LIGNES SUIVANTES //////////////////////////////
  positions.partirJonction(numero);
  this_thread::sleep_for(seconds(1)); // le temps de circuler sur la 2ème voie
  positions.arriver(numero);
  ////////////////////////////////////////////////////////////////////////////////
  trajet.libererArrivee();

}
