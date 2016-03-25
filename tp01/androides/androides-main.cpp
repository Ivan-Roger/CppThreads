#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <thread>

#include "Ecran.hpp"
#include "Androide.hpp"

using namespace std;

int main(int argc, char*argv[])
{
  const unsigned long nb_latences = 2;

  if (argc != 2)
  {
    cerr << "Usage : " << argv[0] << " nb_threads" << endl;
    throw;
  }

  const unsigned long nb_threads = stoul(argv[1]);

  Ecran ecran;

  // initialisation des latences
  unsigned long latences[nb_latences];
  uniform_int_distribution<unsigned long> dis(1,5);
  latences[0] = dis(Androide::gen);
  for (unsigned long i=1; i< nb_latences; i++)
    latences[i] = 3 + latences[i-1];

  // création des threads
  vector<thread> mes_threads;
  for (unsigned long i=0; i < nb_threads; i++)
    mes_threads.push_back(thread(Androide(i,latences[i%nb_latences],ecran)));

  // accélération des explorations après un moment
  this_thread::sleep_for(chrono::seconds(2));
  ecran.affiche_chaine("Accélération!!",10,Androide::COTE_ESPACE+10);
  for (unsigned long i=0; i< nb_latences; i++)
    latences[i] /= 3;

  // attente des threads
  for (unsigned long i=0; i < nb_threads; i++)
    mes_threads.at(i).join();

  // Le programme se termine
  return EXIT_SUCCESS;
}
