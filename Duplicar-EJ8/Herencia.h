#pragma once
#ifndef Herencia_h
#define Herencia_h

#include "Queue.h"
template <class T>
class ListaDuplica :public queue<T> {
	using Nodo = typename queue<T>::Nodo;
public:
	void print(std::ostream& o = std::cout) const{
		
		Nodo* aux = this->prim;
		while (aux != nullptr)
		{
			o << aux->elem<<" ";
			aux = aux->sig;
		}
		o << endl;
	}
	void duplica(Nodo * n)
	{
		//Fin de la recursion
		if (n == this->ult) {
			Nodo* nuevo = new Nodo(n->elem, n->sig);
			n->sig = nuevo;
			this->ult = nuevo;
			this->nelems++;
		}
		else {
			//El siguiente del duplicado es el mismo que el anterior
			Nodo* nuevo = new Nodo(n->elem, n->sig);
			n->sig = nuevo;
			this->nelems++;
			duplica(nuevo->sig);
		}
	}
	void funct()
	{
		Nodo* n = this->prim;
		if(!this->empty())
			duplica(n);
	}
};
#endif