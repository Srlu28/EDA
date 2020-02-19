def Herencia_h
#define Herencia_h

#include "Queue.h"
template <class T>
class ListaInvierte :public queue<T> {
	using Nodo = typename queue<T>::Nodo;
public:
	void print(std::ostream& o = std::cout) const {

		Nodo* aux = this->prim;
		while (aux != nullptr)
		{
			o << aux->elem << " ";
			aux = aux->sig;
		}
		o << endl;
	}
	void invertir()
	{
		Nodo *tmp = this->prim, *t2 = tmp;
		Nodo* current = this->prim->sig;
		this->prim->sig = nullptr;
		while (current != nullptr) {
			t2 = current->sig;
			current->sig = tmp;
			tmp = current;
			current = t2;
		}
	}
	void invierte()
	{
		if (!this->empty())
		{
			invertir();
			Nodo* tmp = this->ult;
			this->ult = this->prim;
			this->prim = tmp;
		}
	}
};
#endif
