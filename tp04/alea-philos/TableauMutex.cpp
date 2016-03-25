#include <vector>
#include <mutex>
#include <thread>
#include <chrono>

#include "TableauMutex.hpp"

using namespace std;
using namespace std::chrono;

TableauMutex::TableauMutex() :
  mutex_bande(vector<mutex>(NB_VALEURS))
{}

void TableauMutex::reserver(const unsigned long numero, const unsigned long iter,
                            int& poids_somme, int& poids_multiplication)
{
  verifier_une_reservation_par_iteration(numero, iter);
  recuperer_poids(iter,poids_somme,poids_multiplication);
  //--TODO-- à compléter --TODO--/
  mutex_bande.at(numero).lock();
  this_thread::sleep_for(milliseconds(10)); // temporisation pour mettre en évidence le risque d'interblocage
  mutex_bande.at(droite(numero)).lock();
  //-----------------------------/
}

void TableauMutex::liberer(const unsigned long numero)
{
  mutex_bande.at(numero).unlock();
  mutex_bande.at(droite(numero)).unlock();
}
