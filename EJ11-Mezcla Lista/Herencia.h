#ifndef Herencia_h
#define Herencia_h

#include "queue_eda.h"
#include<iostream>
using namespace std;

template <class T>
class ListaOrdenada : public queue <T> {
	using Nodo = typename queue<T>::Nodo;
public:
	void print(std::ostream & o=std::cout)
	{
		Nodo* aux = this->prim;
		while (aux != nullptr)
		{
			o << aux->elem<<" ";
			aux = aux->sig;
		}
		o << endl;
	}
	void mezclar_orden(ListaOrdenada& l2)
	{
		if (!l2.empty())
		{
			if (this->empty()) //Si la lista original esta vacia pero la segunda no
			{
				//Ponemos la lista "original" como la segunda lista
				this->prim = l2.prim;
				this->ult = l2.ult;
				this->nelems = l2.nelems;
			}
			else
			{
				Nodo* uno = this->prim;
				Nodo* dos = l2.prim;
				//Vemos cual es el primer elemento de la lista que queremos ver
				if (uno->elem < dos->elem)
				{
					uno = uno->sig;
				}
				else
				{
					this->prim = dos;
					dos = dos->sig;
				}
				Nodo* ult = this->prim;
				while (uno != nullptr && dos != nullptr)
				{
					if (uno->elem < dos->elem)
					{
						ult->sig = uno;
						uno = uno->sig;
					}
					else
					{
						ult->sig = dos;
						dos = dos->sig;
					}
					ult = ult->sig;
				}
				if (uno == nullptr)
				{
					ult->sig = dos;
					this->ult = l2.ult;
				}
				else
				{
					ult->sig = uno;
				}
				this->nelems += l2.nelems;
			}
			l2.nelems = 0;
			l2.prim = nullptr;
			l2.ult = nullptr;
		}
	}
};
#endif