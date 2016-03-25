#ifndef CARREFOUR_HPP_
#define CARREFOUR_HPP_

#include <string>
#include <mutex>
#include <semaphore.h>

class Carrefour {
public :
  Carrefour();
  ~Carrefour();
  Carrefour(const Carrefour &) = delete;
  Carrefour& operator=(const Carrefour &) = delete;
  void reserver(const int voie);
  void liberer(const int voie);
  void basculer_sur(const int nouvelle_voie_verte);

  // constantes pour les voies
  static const int nb_voies = 2;
  static const int voie_principale = 0;
  static const int voie_secondaire = 1;

private :
  // outils de synchronisation
	sem_t semaphore[2];
  // pour l'affichage
  std::mutex mutex_flux_sortie;
public :
  void afficherMessageCommutation(const int voie, const std::string& message);
  void afficherMessageAuto(const int voie, const unsigned long numero, const std::string& message);
};

#endif // CARREFOUR_HPP_
