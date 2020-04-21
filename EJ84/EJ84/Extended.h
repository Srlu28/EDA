#include "Tree.h"
#include <iostream>
using namespace std;

template <class T>
class extended : bintree<T> {

	using Link = typename bintree<T>::Link;
	typedef enum { COMPLETO, SEMICOMPLETO, NADA } status;
	typedef struct
	{
		status _status;
		int height;
	}tInfo;
	
public:

	extended() :bintree<T>() {}
	extended(extended<T> const& c, T const& e, extended<T> const& r) :bintree<T>(c, e, r) {}

	void res(extended<T> const& tree)
	{
		string type[] = { "COMPLETO","SEMICOMPLETO","NADA" };
		tInfo info = setStatus(tree);
		cout << type[info._status] << endl;
	}
private:
	tInfo setStatus(bintree<T> const& tree)
	{
		if (tree.empty())return{ COMPLETO,0 };

		tInfo left = setStatus(tree.left()), right = setStatus(tree.right()), ret;

		if (left.height == right.height && left._status == COMPLETO && right._status == COMPLETO)
		{
			ret.height = 1 + left.height;
			ret._status = COMPLETO;
			return ret;
		}
		bool a = (left._status != NADA && right._status != NADA), b = (left._status == COMPLETO && left.height == right.height + 1) || (left._status == SEMICOMPLETO && right._status == COMPLETO && left.height == right.height);
		if (b && a)
		{
			ret.height = 1 + right.height;
			ret._status = SEMICOMPLETO;
			return ret;
		}
		else return{ NADA,0 };
	}

};
template <typename T>
inline extended<T> readTree(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un árbol vacío
		return {};
	}
	else { // leer recursivamente los hijos
		auto iz = readTree(vacio);
		auto dr = readTree(vacio);
		return { iz, raiz, dr };
	}
}