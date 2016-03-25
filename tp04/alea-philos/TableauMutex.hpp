#ifndef TABLEAU_MUTEX_HPP_
#define TABLEAU_MUTEX_HPP_

#include <vector>
#include <mutex>

#include "Tableau.hpp"

class TableauMutex : public Tableau
{
public :
  TableauMutex();

  void reserver(const unsigned long numero, const unsigned long iter,
                int& poids_somme, int& poids_multiplication);
  void liberer(const unsigned long numero);

private :
  std::vector<std::mutex> mutex_bande;
};

#endif // TABLEAU_MUTEX_HPP_
