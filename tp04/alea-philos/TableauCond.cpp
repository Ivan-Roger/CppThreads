//--TODO-- à compléter --TODO--/
//-----------------------------/

#include "TableauCond.hpp"

using namespace std;

//--TODO-- à compléter --TODO--/
TableauCond::TableauCond()
{}
//-----------------------------/

void TableauCond::reserver(const unsigned long numero, const unsigned long iter,
                           int& poids_somme, int& poids_multiplication)
{
  verifier_une_reservation_par_iteration(numero, iter);
  recuperer_poids(iter,poids_somme,poids_multiplication);
  //--TODO-- à remplacer --TODO--/
  (void)numero;
  //-----------------------------/
}

void TableauCond::liberer(const unsigned long numero)
{
  //--TODO-- à remplacer --TODO--/
  (void)numero;
  //-----------------------------/
}
