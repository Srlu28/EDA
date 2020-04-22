#pragma once
#include "Arbol.h"
#include <iostream>
using namespace std;
#include <algorithm>
template <class T> 
class arbol : bintree<T> {
	using Link = typename bintree<T>::Link;
	typedef struct {
		int altura, maxAl;
	}tInfo;

public:
	arbol():bintree<T>(){}
	arbol(arbol<T> const & c , T const & e ,arbol<T> const & r): bintree<T>(c,e,r){}

	void ej(arbol<T> const& tree)
	{
		tInfo res = resolverEj(tree);
		cout << res.maxAl<<endl;
	}
private :
	tInfo resolverEj(bintree<T> const& tree)
	{
		if (tree.empty())return { 0,0 };
		
		tInfo left=resolverEj(tree.left()), right= resolverEj(tree.right());
		int altura = min(left.altura, right.altura) + 1;
		int maxAl = max(max(left.maxAl, right.maxAl), altura);
		return { altura,maxAl };
	}
};
template <typename T>
arbol<T> readTreeData(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio)
		return {};

	else {
		auto iz = readTreeData(vacio);
		auto dr = readTreeData(vacio);
		return { iz, raiz, dr };
	}
}