#include "Tableau.hpp"
#include "TableauSansSynchro.hpp"

TableauSansSynchro::TableauSansSynchro()
: Tableau()
{}

void TableauSansSynchro::reserver(const unsigned long numero, const unsigned long iter,
                                  int& poids_somme, int& poids_multiplication)
{
  verifier_une_reservation_par_iteration(numero, iter);
  recuperer_poids(iter,poids_somme,poids_multiplication);
}

void TableauSansSynchro::liberer(const unsigned long) {}
