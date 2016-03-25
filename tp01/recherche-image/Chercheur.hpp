#ifndef MONTHREAD_HPP_
#define MONTHREAD_HPP_
#include "ImagePPM.hpp"

// Classe avec opérateur parenthèses défini
class Chercheur {
  public :
    Chercheur (const t_image& source_, t_image& query_, int& x_, int& y_, int& match_);
    void operator()();

  private :
	const t_image& source;
	t_image& query;
	int& x;
	int& y;
	int& match;
};

#endif // MONTHREAD_HPP_
