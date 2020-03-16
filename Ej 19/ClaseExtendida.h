#pragma once
#include <algorithm>
#include "Bin_tree.h"


template <class T>
class ClaseExtendida : public bintree<T> {
	using Link = typename bintree<T> ::Link;
public :
	ClaseExtendida():bintree<T>(){}
	ClaseExtendida(ClaseExtendida<T> const& c, T const& e, ClaseExtendida<T> const& r) :bintree<T>(c, e, r) {
	}

	int hojas() {
		return  p_hojas(this->raiz);
	}
	int altura()
	{
		return this->p_altura(this->raiz);
	}
	int nodos()
	{
		return this->p_nodos(this->raiz);
	}

private:
	int p_hojas(Link r)
	{
		if (r == nullptr)return 0;
		if (r->left == nullptr && r->right == nullptr)return 1;
		else return p_hojas(r->left) + p_hojas(r->right);
	}

	int p_altura(Link r)
	{
		if (r == nullptr) return 0;
		else return std::max(p_altura(r->left), p_altura(r->right)) + 1;
	}
	int p_nodos(Link r)
	{
		if (r == nullptr) return 0;
		else return p_nodos(r->left)+ p_nodos(r->right) + 1;
	}
};
template <typename T>
ClaseExtendida<T> readTreeData(T vacio) {
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