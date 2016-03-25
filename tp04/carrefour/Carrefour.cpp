#include <iostream>
#include <string>
#include <mutex>
#include <condition_variable>

#include "Carrefour.hpp"

using namespace std;

Carrefour::Carrefour() :
  voie_verte(voie_principale),
  automobile_engagee(false)
{}

void Carrefour::reserver(int voie)
{
	unique_lock<mutex> verrou(mon_mutex);
	while (automobile_engagee || voie!=voie_verte) {
  	files[voie].wait(verrou);
	}
	automobile_engagee = true;
}

void Carrefour::liberer(int) // on n'utilise pas le paramètre dans cette version
{
	unique_lock<mutex> verrou(mon_mutex);
	automobile_engagee = false;
	files[voie_verte].notify_one();
}

void Carrefour::basculer_sur(int nouvelle_voie_verte)
{
	unique_lock<mutex> verrou(mon_mutex);
	afficherMessageCommutation(voie_verte, " FEU ORANGE");
  afficherMessageCommutation(voie_verte, " FEU ROUGE");
	voie_verte=nouvelle_voie_verte;
  afficherMessageCommutation(voie_verte, " FEU VERT");
	files[voie_verte].notify_one();
}

const string nom_voie[Carrefour::nb_voies]={"PRINCIPALE","SECONDAIRE"};

void Carrefour::afficherMessageCommutation(int voie, string message)
{
  lock_guard<mutex> verrou(mutex_affichage);
  cout << nom_voie[voie] << message << endl;
}

void Carrefour::afficherMessageAuto(int voie, unsigned long numero, string message)
{
  lock_guard<mutex> verrou(mutex_affichage);
  cout << nom_voie[voie] << " " << numero << message << endl;
}
