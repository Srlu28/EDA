#ifndef ClaseExtendida_h
#define ClaseExtendida_h
#include "Arbol.h"
#include <string>
#include <iostream>
using namespace std;

template <class T>
class ArbolBusqueda : public bintree<T> {

	using Link = typename bintree<T>::Link;
	typedef struct {
		bool ok;
		int mayor, menor;
	}tInfo;

public:
	ArbolBusqueda() :bintree<T>() {  }
	ArbolBusqueda(ArbolBusqueda<T> const & l, T const& e, ArbolBusqueda<T> const & r) : bintree<T>(l,e,r){}

	void esBusqueda()
	{
		
		if (this->empty())cout << "SI\n";
		else {
			tInfo h = binarioBusqueda(this->raiz);
			bool good = h.ok;
			string nom = (good ? "SI\n" : "NO\n");
			cout << nom;
		}
		
	}
private:
	tInfo  binarioBusqueda(Link r)
	{
		tInfo ret = { true,r->elem,r->elem };

		if (r->left != nullptr)
		{
			tInfo left = binarioBusqueda(r->left);
			ret.ok = left.ok && left.mayor < r->elem;
			ret.menor = left.menor;
		}
		if (r->right != nullptr)
		{
			tInfo right = binarioBusqueda(r->right);
			ret.ok = right.ok && ret.ok && right.menor > r->elem;
			ret.mayor = right.mayor;
		}
		return ret;
	}
};

template <typename T>
inline ArbolBusqueda<T> readTree(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio)
		return {};

	else {
		auto iz = readTree(vacio);
		auto dr = readTree(vacio);
		return { iz, raiz, dr };
	}
};

#endif