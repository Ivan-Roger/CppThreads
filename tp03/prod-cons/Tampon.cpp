#include <iostream>

#include "Tampon.hpp"
#include "Element.hpp"

using namespace std;

Tampon::Tampon(const unsigned int taille_, EcranManchots& ecran_) :
  taille(taille_),
  ecran(ecran_)
{
}

Tampon::~Tampon()
{
}

void Tampon::deposer_element(Element e)
{
  ecran.dessiner_creer_manchot(e);

    if (tampon.size() == taille)
    {
      ecran.~EcranManchots();
      cerr << "Tentative de dépôt alors que le tampon est plein." << endl;
      throw;
    }

    ecran.dessiner_deposer_manchot(e);

    tampon.push_front(e);

}

Element Tampon::retirer_element(const unsigned long numcons, const unsigned long nummanchot)
{
  ecran.dessiner_demander_manchot(static_cast<int>(numcons),static_cast<int>(nummanchot));
  Element e(0);

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


  return e;
}
