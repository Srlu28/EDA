#ifndef HerenciaCola_h
#define HerenciaCola_h
#include<iostream>
using namespace std;
#include "Queue_eda.h"
template<class T>
class Herencia:public queue<T> {
	using Nodo = typename queue<T> ::Nodo;
public:
	void resuelveCaso(int n)
	{
		Nodo* iterador=this->prim;
		Nodo* anterior = this->prim;
		int pos = 0;
		while (this->nelems != 1)
		{
			pos++;
			if (pos % (n+1) == 0) {
				if (iterador == this->prim)
				{
					this->prim = iterador->sig;
				}
				else if (iterador == this->ult)
				{
					iterador = anterior;
					this->ult = iterador;
					this->ult->sig = nullptr;
				}
				if(iterador!= this->prim)
					anterior->sig = iterador->sig;
				this->nelems--;
			}
			if (iterador == this->ult)
			{
				anterior = iterador = this->prim;
			}
			else
			{
				if(iterador != this->ult)
					anterior = iterador;
				iterador = iterador->sig;
			}
			
		}
		
	}
	void print(std::ostream& o = std::cout) const {

		Nodo* aux = this->prim;
		while (aux != nullptr)
		{
			o << aux->elem << " ";
			aux = aux->sig;
		}
		o << endl;
	}
};
#endif
