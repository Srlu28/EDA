#ifndef Herencia_h
#define Herencia_h

#include "queue_eda.h"
#include <iostream>
using namespace std;

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
		Nodo* aux=this->prim;
		//Casos especiales, posicion 0
		if (pos == 0)
		{
			this->prim = l2.prim;
			l2.ult->sig = aux;
		}
		else
		{
			for (int i = 0; i < pos - 1; i++)
			{
				aux = aux->sig;
			}
			//Tenemos el nodo a partir el cual queremos insertar que es aux
			Nodo* aux2 = aux->sig;
			aux->sig = l2.prim;
			l2.ult->sig = aux2;
			if (pos == this->nelems)this->ult = l2.ult;
		}
		this->nelems += l2.nelems;
		l2.nelems = 0;
		l2.prim = nullptr;
		l2.ult = nullptr;
		

	}
};

#endif
