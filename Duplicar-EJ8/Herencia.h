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
	void duplica()
	{
		int num = this->size();
		for (int i=0; i < num; i++)
		{
			T elem = this->front();
			this->pop();
			this->push(elem);
			this->push(elem);
		}
	}
};
#endif