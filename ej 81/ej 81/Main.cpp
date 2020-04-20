#include <iostream>
using namespace std;
#include "bin_tree_eda.h"

bool isSim(bintree<char> const& left, bintree<char> const & right)
{
	if (left.empty() && right.empty())return true;
	if (!left.empty() && !right.empty())
		return isSim(left.left(), right.right()) && isSim(left.right(), right.left());
	else return false;
}
void resuelveCaso()
{
	bintree<char> t;
	t = leerArbol('.');

	bool sim = (t.empty() || isSim(t.left(), t.right()));
	cout << (sim ? "SI" : "NO") << endl;
}
int main()
{
	int numC;
	cin >> numC;
	for (int i = 0; i < numC; i++)
		resuelveCaso();
	return 0;
}