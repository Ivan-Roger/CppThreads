#include <iostream>
#include <sstream>
#include <thread>
#include <vector>
#include <limits.h>
#include "ImagePPM.hpp"
#include "Chercheur.hpp"

using namespace std;

// Classe pour stocker le résultat des recherches effectuées par chaque thread
class SearchImageData {
	public :
	int match;     // meilleure correspondance trouvée dans l'image
	int x;         // position de cette meilleure correspondance
	int y;
	SearchImageData() : match(0), x(0), y(0) {}
};

int main(int argc, char* argv[]) {

	if (argc != 4) {
		cerr << "Usage : " << argv[0] << " image_source image_requete nb_threads" << endl;
		throw;
	}

	unsigned long const nb_threads = stoul(argv[3]);
	if (nb_threads != 2 && nb_threads != 4)
	{
		cerr << "nb_threads doit être égal à 2 ou 4" << endl;
		throw;
	}

	t_image source = read_image(argv[1]);
	t_image query = read_image(argv[2]);

	t_image* subImg = new t_image[nb_threads];

	// Découpage de l'image en deux ou en quatre
	split_image(source,subImg[0],subImg[1],query.height);

	if (nb_threads == 4)
	{
		split_image(subImg[0],subImg[0],subImg[2],query.height);
		split_image(subImg[1],subImg[1],subImg[3],query.height);
	}

	// Création des objets contenant les résultats des recherches
	vector<SearchImageData> data (nb_threads);

	// Création des threads
	vector<thread> mes_threads;
	for (unsigned long i=0; i < nb_threads; i++) {
		mes_threads.push_back(thread(Chercheur(subImg[i],query,data.at(i).x,data.at(i).y,data.at(i).match)));
		cout << "New thread " << i << ", zone : " <<  << endl;
	}

	cout << "Recherche de l'image ..." << endl;
	cout << "Attente des threads ..." << endl;
  for (unsigned long i=0; i < nb_threads; i++)
    mes_threads.at(i).join();


	// Recherche du thread qui a trouvé la meilleure solution
	unsigned long bestThread = nb_threads+1;
	int bestMatch = INT_MAX;
	for (unsigned long i = 0; i < nb_threads; i++) {
		if (data[i].match < bestMatch) {
			bestMatch = data[i].match;
			bestThread = i;
		}
	}
	if (bestThread == nb_threads+1) {
		cerr <<  "Erreur : la meilleure correspondance n'a pas été trouvée" << endl;
		delete_image(source); delete_image(query); delete[] subImg;
		throw;
	}

	cout << endl << "Meilleure correspondance "<< bestMatch << " trouvée par le thread " << bestThread;
	cout <<  " en (" << data[bestThread].x << "," << data[bestThread].y << ")."<<endl;

	// Dessine un rectangle rouge à l'emplacement trouvé relativement à la sous image
	// où la meilleure solution est trouvée
	t_pixel red = {255,0,0};
	draw_rect(subImg[bestThread],red,data[bestThread].x,data[bestThread].y,query.width,query.height);

	// Création du fichier résultat contenant votre login dans son nom
	ostringstream oss;
	oss << "/tmp/resultat-" << getenv("LOGNAME") << ".ppm";
	cout << "Résultat dans le fichier '"<< oss.str() << "'." << endl;
	write_image(source, oss.str().c_str());

	delete_image(source);
	delete_image(query);
	delete[] subImg;
	return EXIT_SUCCESS;
}
