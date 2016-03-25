#include <iostream>
#include <thread>
#include <chrono>
#include "Chercheur.hpp"
#include "ImagePPM.hpp"

using namespace std;

Chercheur::Chercheur (t_image source_, t_image query_, int& x_, int& y_, int& match_): source(source_), query(query_), x(x_), y(y_), match(match_) {}

void Chercheur::operator()()
{
	search_image(source,query,x,y,match);
}
