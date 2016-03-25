#include <iostream>

#include "TamponCond.hpp"
#include "Element.hpp"

using namespace std;

TamponCond::TamponCond(const unsigned long taille_, EcranManchots& ecran_) :
  Tampon(ecran_), taille(taille_), mon_mutex(), depot(), retrait()
{}

void TamponCond::deposer_element(Element e)
{
  ecran.dessiner_creer_manchot(e);

	unique_lock<mutex> verrou(mon_mutex);
	while (tampon.size() == taille) {
		depot.wait(verrou);
	}


  if (tampon.size() == taille)
  {
    ecran.~EcranManchots();
    cerr << "Tentative de dépôt alors que le tampon est plein." << endl;
    throw;
  }

  tampon.push_front(e);

  ecran.dessiner_deposer_manchot(e);

	retrait.notify_one();

}

Element TamponCond::retirer_element(const unsigned long numcons, const unsigned long nummanchot) {
  ecran.dessiner_demander_manchot(static_cast<int>(numcons),static_cast<int>(nummanchot));
  Element e = 0;

	unique_lock<mutex> verrou(mon_mutex);
	while (tampon.empty()) {
		retrait.wait(verrou);
	}
	
  if (tampon.empty())
  {
    ecran.~EcranManchots();
    cerr << "Tentative de retrait alors que le tampon est vide." << endl;
    throw;
  }

  e = tampon.back();
  tampon.pop_back();

  e.setNumCons(numcons);

  ecran.dessiner_retirer_manchot(e,static_cast<int>(nummanchot));

	depot.notify_one();

  return e;
}
