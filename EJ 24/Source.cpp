#include <iostream>
using namespace std;
#include "Arbol.h"
#include <string>
#include <vector>
#include <sstream>

//Dado este problema nos vamos a centrar en calcular un arbol a partir de la notacion en preorden e inorden, una vez realizado
//mostraremos por pantalla ese arbol pero en postorden

vector<int> leerVector()
{
	vector<int> v;
	int aux;

	stringstream tmp;
	string s;
	getline(cin, s);
	tmp << s;

	tmp >> aux;
	while (tmp) {
		v.push_back(aux);
		tmp >> aux;
	}
	return v;

}
queue<int> vecToQueue(vector<int> v)
{
	queue<int> q;
	for (int n : v)
		q.push(n);
	return q;
}

bintree<int> calcularArbol(queue<int> inor, queue<int> preo)
{
	if (preo.size() == 1)return preo.front();

	int raiz = preo.front();//Sacamos la raiz
	preo.pop();

	queue<int> leftInor, leftPreo;

	while (inor.front() != raiz)
	{
		leftInor.push(preo.front());
		preo.pop();
		leftPreo.push(inor.front());
		inor.pop();
	}
	inor.pop();//Quitamos la raiz en la notacion inor
	
	bintree<int> left = {}, right = {};

	if (leftPreo.size())left = calcularArbol(leftInor, leftPreo);
	if (preo.size())right = calcularArbol( inor,preo);

	return { left,raiz,right };
}
bool resuelveCaso()
{
	vector<int> vectorInorden, vectorPreorden;
	vectorPreorden = leerVector();
	if (vectorPreorden.size()) {

		vectorInorden = leerVector();
		queue<int> inor, preo;
		inor = vecToQueue(vectorInorden);
		preo = vecToQueue(vectorPreorden);

		bintree<int> arbol = calcularArbol(inor,preo);

		for (auto& it : arbol.postorder())cout << it<<" ";
		cout << endl;

		return true;
	}
	return false;
}

int main()
{
	while (resuelveCaso());
	return 0;
}