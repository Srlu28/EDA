#ifndef ArbolGenealogico_h
#define ArbolGenealogico_h
#include "bin_tree_eda.h"
#include <string>
#include <iostream>
using namespace std;

template <class T>
class ArbolGenealogico : public bintree<T> {

	using Link = typename bintree<T> ::Link;
	typedef struct {
		int edad;
		bool ok;
	}tInfo;

public :
	ArbolGenealogico() :bintree<T>() {  }
	ArbolGenealogico(ArbolGenealogico<T> const& l, T const& e, ArbolGenealogico<T> const& r) : bintree<T>(l, e, r) {}

	void esGenealogico(bintree<int> const& t)
	{
		if (this->empty())cout << "SI 0\n";
		else
		{
			tInfo h = func(t);
			bool good = h.ok;
			string name = (good ? "SI" : "NO");
			cout << name << " ";
			if (good)cout << altura(this->raiz);
			cout<< endl;
		}
	}
private:
	tInfo func(bintree<int> const & t)
	{
		if (t.empty())return { -1,true };

		bool ok = true;
		tInfo infoLeft = func(t.left());
		tInfo infoRight = func(t.right());
		if (infoLeft.edad != -1)
			ok &= (t.root() - infoLeft.edad >= 18);
		if (infoRight.edad != -1)
			ok &= (t.root() - infoRight.edad >= 18, infoLeft.edad-infoRight.edad >= 2);
		ok = ok && infoRight.ok && infoLeft.ok && !(infoLeft.edad == -1 && infoRight.edad != -1);
		return{ t.root(),ok };
	}
	int altura(Link node)
	{
		if (node == nullptr)return 0;
		else
		{
			return 1 + max(altura(node->left), altura(node->right));
		}
	}
};
template <typename T>
inline ArbolGenealogico<T> readTree(T vacio) {
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