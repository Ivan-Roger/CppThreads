#ifndef TAMPON_COND_HPP_
#define TAMPON_COND_HPP_

#include <deque>
#include <mutex>
#include <condition_variable>

#include "Tampon.hpp"
#include "TamponCond.hpp"
#include "Element.hpp"
#include "EcranManchots.hpp"

class TamponCond : public Tampon
{
public :
  TamponCond(const unsigned long taille_, EcranManchots& ecran_);

  void deposer_element(Element e);
  Element retirer_element(const unsigned long numcons, const unsigned long nummanchot);

private :
  const unsigned long taille;
  std::deque<Element> tampon;
	std::mutex mon_mutex;
	std::condition_variable depot;
	std::condition_variable retrait;
};

#endif // TAMPON_COND_HPP_
