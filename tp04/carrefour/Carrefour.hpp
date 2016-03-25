#ifndef CARREFOUR_HPP_
#define CARREFOUR_HPP_

#include <string>
//--TODO-- à compléter --TODO--/
#include <mutex>
#include <vector>
#include <condition_variable>
//-----------------------------/

class Carrefour
{
public :
  Carrefour();
  void reserver(int voie);
  void liberer(int voie);
  void basculer_sur(int nouvelle_voie_verte);

  // constantes pour les voies
  static const int nb_voies = 2;
  static const int voie_principale = 0;
  static const int voie_secondaire = 1;

private :
  // outils de synchronisation
  //--TODO-- à compléter --TODO--/
	std::condition_variable files[nb_voies];
	std::mutex mon_mutex;
  //-----------------------------/

  // variables partagées pour la synchronisation
  int voie_verte;           // voie dont le feu est vert
  bool automobile_engagee;  // == true si une automobile est engagée sur le carrefour

  // pour l'affichage
  std::mutex mutex_affichage;
public :
  void afficherMessageCommutation(int voie, std::string message);
  void afficherMessageAuto(int voie, unsigned long numero, std::string message);
};

#endif // CARREFOUR_HPP_
