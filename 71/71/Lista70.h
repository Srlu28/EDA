#pragma once
#include "queue_eda.h"
#include <iostream>
using namespace std;

template <class T>
class Lista70 : public	queue<T> {
	using Nodo = typename queue<T> ::Nodo;
public : 
	void print(ostream& o = cout)
	{
		Nodo * n1 = this->prim;
		while (n1 != nullptr)
		{
			o << n1->elem<<" ";
			n1 = n1->sig;
		}
		o << endl;
	}
	void intercambios()
	{
		Nodo* n1 = this->prim;
		intercambios(n1);
	}
private :
	void intercambios(Nodo* n1)
	{
		if (n1->sig != nullptr) this->prim = n1->sig;
		while ( n1->sig != nullptr)
		{
			Nodo* n2 = n1->sig;
			Nodo* n3 = n2->sig;
			n1->sig = n3;
			n2->sig = n1;
			if (n3 == nullptr) this->ult = n1;
			else
			{
				if (n3->sig != nullptr)
					n1->sig = n3->sig;
				n1 = n3;
			}

			
		}
	}
};