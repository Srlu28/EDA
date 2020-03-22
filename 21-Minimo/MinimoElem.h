#ifndef MinimoElem_h
#define MinimoElem_h

#include "bintree_eda.h"
#include <iostream>
using namespace std;
#include<algorithm>

template <class T>
class minim : public bintree<T> {
	using Link = typename bintree<T>::Link;
public : 
	minim():bintree<T>(){}
	minim(minim<T> const& c,T const& e, minim<T> const& r):bintree<T>(c,e,r){}

	void minimElem()
	{
		cout << p_metodo(this->raiz)<<endl;
	}
private:
	T p_metodo(Link r)
	{
		T minder=r->elem, minright=r->elem;
		if (r->left != nullptr)minder = min(p_metodo(r->left), minder);
		if (r->right != nullptr)minright = min(p_metodo(r->right), minder);

		return min(minder, minright);
	}
};
template <typename T>
inline minim<T> readTree(T vacio) {
	T raiz;
	cin >> raiz;
	if (raiz == vacio) { // es un árbol vacío
		return {};
	}
	else { // leer recursivamente los hijos
		auto iz = readTree(vacio);
		auto dr = readTree(vacio);
		return { iz, raiz, dr };
	}
}

#endif