#include <iostream>
using namespace std;
#include "Libro.h"
#include <string>

bool res() {
	string orden, name;
	int num, n;

	cin >> n;
	if (cin.fail()) return false;

	Libreria v;

	for (int i = 0; i < n; i++)
	{
		cin >> orden;
		try {
			if (orden == "nuevoLibro") {
				cin >> num;
				cin.get();
				getline(std::cin, name);
				v.nuevoLibro(num, name);
			}
			else if (orden == "comprar") {
				cin.get();
				getline(cin, name);
				v.comprar(name);
			}
			else if (orden == "numEjemplares") {
				cin.get();
				getline(cin, name);
				int i = v.numEjemplares(name);
				cout << "Existen " << i << " ejemplares del libro " << name << '\n';
			}
			else if (orden == "estaLibro") {
				cin.get();
				getline(cin, name);
				cout << (v.estaLibro(name) ? "El libro " + name + " esta en el sistema\n" : "No existe el libro " + name + " en el sistema\n");
			}
			else if (orden == "elimLibro") {
				cin.get();
				getline(cin, name);
				v.elimLibro(name);
			}
			else if (orden == "top10") {
				list<string> l = v.top10();
				cout << "TOP10\n";
				for (string s : l) cout << "    " << s << '\n';
			}
		}
		catch (exception& e) {
			cout << e.what() << '\n';
		}
	}
	cout << "---\n";
	return true;
}

int main() {
	while (res());
	return 0;
}