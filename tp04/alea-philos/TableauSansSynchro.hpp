#ifndef TABLEAU_SANS_SYNCHRO_HPP_
#define TABLEAU_SANS_SYNCHRO_HPP_

#include "Tableau.hpp"

class TableauSansSynchro : public Tableau
{
public :
  TableauSansSynchro();

  void reserver(const unsigned long numero, const unsigned long iter,
                int& poids_somme, int& poids_multiplication);
  void liberer(const unsigned long numero);
};

#endif // TABLEAU_SANS_SYNCHRO_HPP_
