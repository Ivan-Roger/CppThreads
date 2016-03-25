#ifndef TAMPON_SBQ_HPP_
#define TAMPON_SBQ_HPP_


#include "Tampon.hpp"
#include "TamponSBQ.hpp"
#include "Element.hpp"
#include "EcranManchots.hpp"

class TamponSBQ : public Tampon
{
public :
  TamponSBQ(const unsigned long taille_, EcranManchots& ecran_);

  void deposer_element(Element e);
  Element retirer_element(const unsigned long numcons, const unsigned long nummanchot);

private :
};

#endif // TAMPON_SBQ_HPP_
