#pragma once
#include<iostream>
using namespace std;
#include "List.h"
template<class T>
class Herencia :public list<T> {
	using Nodo = typename list<T> ::Nodo;
public:
	template<class Predicate>
	void remove_if(Predicate pred) {
		auto it = this->begin();
		while (it != this->end())
			if (pred(*it)) it = this->erase(it);
			else ++it;
	}
	void mostrar()
	{
		for (auto it = this->begin(); it != this->end(); ++it)cout << *it << endl;
	}

};
