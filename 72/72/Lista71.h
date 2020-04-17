#include "queue_eda.h"
#include <iostream>
using namespace std;

template <class T>
class Lista71 : public queue<T> {
	using Nodo = typename queue<T>::Nodo;
public:
	void print(ostream& o = cout)
	{
		Nodo* n1 = this->prim;
		while (n1 != nullptr)
		{
			o << n1->elem << " ";
			n1 = n1->sig;
		}
		o << endl;
	}
	void eliminarPares()
	{
		Nodo* n1 = this->prim;
		eliminar(n1);
	}
private:
	void eliminar(Nodo* n1)
	{
		int it = 1;
		Nodo* nAnt = n1;
		while (it <=this->size())
		{
			if (it % 2 == 0)
			{
				nAnt->sig = n1->sig;
			}
			else
			{
				nAnt = n1;
			}
			it++;
			n1 = n1->sig;
		}
		if (this->size() % 2 == 0)this->ult = nAnt;
	}
};