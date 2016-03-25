#ifndef TAMPON_HPP_
#define TAMPON_HPP_

#include <deque>

#include "Element.hpp"
#include "EcranManchots.hpp"

class Tampon
{
public :
  Tampon(const unsigned int taille_, EcranManchots& ecran_);
  ~Tampon();

  void deposer_element(Element e);
  Element retirer_element(const unsigned long numcons, const unsigned long nummanchot);

private :
  const unsigned int taille;
  std::deque<Element> tampon;


private :
  EcranManchots& ecran; // pour affichage
};

#endif // TAMPON_HPP_
