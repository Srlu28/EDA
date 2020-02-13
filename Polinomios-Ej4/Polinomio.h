#ifndef Polinomio_h
#define Polinomio_h
#include "Monomio.h"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <math.h>
using namespace std;

class polinomio
{
public:
	polinomio()
	{
		monomio m;
		cin>> m.coc >> m.exp ;
		if (!cin)  throw std::domain_error("Datos inválidos.");
		else
		{
			if(esValido(m))
			{
				array.push_back(m); 
				cin>> m.coc >> m.exp ;
				//Añadimos elemento de la forma correcta para que quede ordenado y solo haya un exponente por monomio
				while (esValido(m))
				{
					addElem(m);
					cin>> m.coc >> m.exp ;
				}
			}
		}
	}
	~polinomio()
	{
					
	}
	int calcularValor(int valor);
	void addElem(monomio m);
private:
	vector<monomio> array;
};
int polinomio::calcularValor(int valor)
{
	int suma = 0;
	for (long unsigned int i = 0; i < array.size(); i++)
	{
		int elem1=pow(valor, array.at(i).exp);
		int elem2=array.at(i).coc;
		suma +=  elem1*elem2 ;
	}
	return suma;
}
void polinomio::addElem(monomio m)
{
	long unsigned int pos=0;
	while(pos<array.size()&&m.exp>array.at(pos).exp)
	{
		pos++;
	}
	if(pos<array.size() && m.exp==array.at(pos).exp) array.at(pos).coc+=m.coc;
	else
	{
		if(pos != array.size())
			array.insert(array.begin()+pos,m);
		else
		{
			array.push_back(m);
		}
		
	}
}
#endif