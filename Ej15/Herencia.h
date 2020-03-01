#include "queue_eda.h"
#include "stack_eda.h"
template <class T>
class Herencia : public queue<T> {
	using Nodo = typename queue<T>::Nodo;
public:
	stack<T> ej(int num, int num2)
	{
		stack<T> res;
		Nodo* n1 = this->prim;
		for (int i = 0; i < num; i++)
		{
			Nodo* n2 = n1;
			T maxEl = n2->elem;
			for (int j = 0; j < num2 - 1; j++)
			{
				n2 = n2->sig;
				if (n2->elem > maxEl)
				{
					maxEl=n2->elem;
				}
			}
			res.push(maxEl);
			n1 = n1->sig;
		}
		return res;
	}
};

