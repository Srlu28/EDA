#ifndef Herencia_h
#define Herencia_h
#include "queue_eda_h.h"
#include<iostream>
using namespace std;
template <class T>
class ListaInvierte :public queue<T> {
	using Nodo = typename queue<T> ::Nodo;
public:
	void print(std::ostream& o = std::cout)const {
		Nodo *aux = this->prim;
		while (aux != nullptr)
		{
			o << aux->elem << " ";
			aux = aux->sig;
		}
		o << endl;
	}
	void invierte(ListaInvierte & lista)
	{
		if (this->size() >= 1)
		{
			T elem = this->front();
			this->pop();
			invierte(lista);
			lista.push(elem);
		}
	}
};

#endif
