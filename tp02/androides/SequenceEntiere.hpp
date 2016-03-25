#ifndef SEQUENCE_ENTIERE_HPP_
#define SEQUENCE_ENTIERE_HPP_

//--TODO-- à compléter --TODO--/
#include <mutex>
//-----------------------------/

class SequenceEntiere
{
public :
  SequenceEntiere(unsigned int numero_initial=0);
  unsigned int nouveau_numero(void);

private :
  unsigned int numero;
  //--TODO-- à compléter --TODO--/
	std::mutex mon_mutex;
  //-----------------------------/
};

#endif // SEQUENCE_ENTIERE_HPP_
