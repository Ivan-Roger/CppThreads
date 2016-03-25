#include <iostream>
#include <string>
#include <mutex>
#include <semaphore.h>
#include <thread>
#include <chrono>

#include "Carrefour.hpp"


using namespace std;

Carrefour::Carrefour()
{
  //--TODO-- à compléter --TODO--/
	sem_init(&semaphore[0],0,1);
	for(int i=1; i<nb_voies; i++) {
		sem_init(&semaphore[i],0,0);
	}
  //-----------------------------/
}

Carrefour::~Carrefour()
{
  //--TODO-- à compléter --TODO--/
	for(int i=0; i<nb_voies; i++) {
		sem_destroy(&semaphore[i]);
	}
  //-----------------------------/
}

void Carrefour::reserver(const int voie)
{
  //--TODO-- à remplacer --TODO--/
  sem_wait(&semaphore[voie]);
  //-----------------------------/
}

void Carrefour::liberer(const int voie)
{
  //--TODO-- à remplacer --TODO--/
  sem_post(&semaphore[voie]);
  //-----------------------------/
}

void Carrefour::basculer_sur(const int nouvelle_voie_verte)
{
	std::chrono::duration<double> const attente(std::chrono::seconds(1));
  const int ancienne_voie_verte=(nouvelle_voie_verte+1)%2;
  //--TODO-- à compléter --TODO--/
  reserver(ancienne_voie_verte);
  afficherMessageCommutation(ancienne_voie_verte, " FEU ORANGE");
	this_thread::sleep_for(attente);
  afficherMessageCommutation(ancienne_voie_verte, " FEU ROUGE");
	this_thread::sleep_for(attente);
	liberer(nouvelle_voie_verte);
  afficherMessageCommutation(nouvelle_voie_verte, " FEU VERT");
  //-----------------------------/

}

const string nom_voie[Carrefour::nb_voies]={"PRINCIPALE","SECONDAIRE"};

void Carrefour::afficherMessageCommutation(const int voie, const string& message)
{
  lock_guard<mutex> verrou(mutex_flux_sortie);
  cout << nom_voie[voie] << message << endl;
}

void Carrefour::afficherMessageAuto(const int voie, const unsigned long numero, const string& message)
{
  lock_guard<mutex> verrou(mutex_flux_sortie);
  cout << nom_voie[voie] << " " << numero << message << endl;
}
