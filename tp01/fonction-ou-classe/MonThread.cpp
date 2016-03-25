#include <iostream>
#include "MonThread.hpp"

using namespace std;

MonThread::MonThread(unsigned long numero) : m_numero(numero) {}

void MonThread::operator()(){
	cout << m_numero;
}
