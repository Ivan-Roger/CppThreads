#ifndef TABLEAU_COND_HPP_
#define TABLEAU_COND_HPP_

//--TODO-- à compléter --TODO--/
//-----------------------------/

#include "Tableau.hpp"

class TableauCond : public Tableau
{
public :
  TableauCond();
  void reserver(const unsigned long numero, const unsigned long iter,
                int& poids_somme, int& poids_multiplication);
  void liberer(const unsigned long numero);

private :
  //--TODO-- à compléter --TODO--/
  //-----------------------------/
};

#endif // TABLEAU_COND_HPP_
