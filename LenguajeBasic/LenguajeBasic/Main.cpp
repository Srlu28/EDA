#include <iostream>
using namespace std;
#include <map>
#include<vector>

typedef struct {
	int nLinea, oldLinea;
}tLinea;
typedef struct {
	string name;
	int lineaOr, lineaDes;
}tInstruccion;
void resolverCaso() {
	tInstruccion ins;
	ins.lineaOr=99;
	int i = 1;

	map<int, int> mapaLineas;
	vector<tInstruccion> colaInst;
	while (ins.lineaOr != 0) {
		cin >> ins.lineaOr;
		if (ins.lineaOr != 0) {
			int nuevaLinea = i * 10;
			cin >> ins.name;
			if (ins.name != "RETURN")
			{
				cin >> ins.lineaDes;
			}
			else ins.lineaDes = 0;
			colaInst.push_back(ins);
			i++;
			mapaLineas[ins.lineaOr] = nuevaLinea;
		}
		
	}
	for (tInstruccion ins : colaInst) {
		cout << mapaLineas[ins.lineaOr] << " " << ins.name << " "; 
		if (mapaLineas[ins.lineaDes])
			cout << mapaLineas[ins.lineaDes];
		cout << endl;
	}
	cout << "---\n";
}

int main() {
	int numC;
	cin >> numC;
	for (int i = 0; i < numC; i++) {
		resolverCaso();
	}
}