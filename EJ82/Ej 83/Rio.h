#pragma once
#include "Tree_Eda.h"
#include <iostream>
using namespace std;
#include <algorithm>

template<class T>
class Rio : bintree<T> {
	using Link = typename bintree<T>::Link;
	typedef struct
	{
		int cauce, rutas;
	}tRio;
public :
	Rio():bintree<T>(){}
	Rio(Rio<T> const& c, T const& e, Rio<T> const& r) :bintree<T>(c, e, r) {}

	void ejercicio(Rio<T> const& tree)
	{
		tRio rio = func(tree);
		if (rio.cauce > 2)rio.rutas=rio.rutas - 1;
		cout << rio.rutas << endl;
	}
	tRio func(bintree<T> const & tree)
	{
		if (tree.empty())return { 0,0 };
		if (tree.left().empty() && tree.right().empty())return{ 1,0 };

		tRio afluenteIz=func(tree.left()), afluenteDer=func(tree.right()), ret;
		ret.rutas = afluenteIz.rutas + afluenteDer.rutas;
		ret.cauce = max((afluenteIz.cauce + afluenteDer.cauce-tree.root()),0);

		if (ret.cauce > 2)ret.rutas++;
		return ret;
	}
};
template <typename T>
Rio<T> readTreeData(T vacio) {
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