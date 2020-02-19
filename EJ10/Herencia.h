#ifndef Herencia_h
#define Herencia_h

#include "queue_eda.h"

template <class T>
class ListaEnlazada :public queue<T> {
	using Nodo = typename queue<T> ::Nodo;
public:
	void print(std::ostream& o = std::cout)const {
		Nodo* aux = this->prim;
		while (aux != nullptr) {
			o << aux->elem << " ";
			aux = aux->sig;
		}
		o << endl;
	}
	void inserta(ListaEnlazada& l2, int pos) {
		Nodo* aux = this->prim;
		for (int i = 0; i < pos-1; i++) {
			aux = aux->sig;
		}
		Nodo* aux2 = aux->sig;
		cout << "Insercion a partir de " << aux->elem;
		int numIter = l2.size();
		for (int i = 0; i < numIter; i++)
		{
			Nodo* dev = l2.prim;
			aux->sig = dev;
			this->nelems++;
			aux = aux->sig;
		}
		aux->sig = aux2;
	}
};

#endif
