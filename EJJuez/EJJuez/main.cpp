// Luis Ariza LÛpez

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#include "bintree_eda.h"

typedef struct
{
    int height, diameter;
}tInformacion;

tInformacion recurS(bintree<int> const& arbol,int & maxDiam)
{
    if (arbol.empty())return{ 0,0 };
    else
    {
         tInformacion left = recurS(arbol.left(),maxDiam), right = recurS(arbol.right(),maxDiam);
         if (arbol.root() % 2 == 0)
         {
             int height = max(left.height, right.height) + 1;
             int diam = max(max(left.diameter, right.diameter), left.height + right.height + 1);
             maxDiam = max(diam, maxDiam);
             return{ height,diam  };
         }
         else return { 0,0 };
        
    }
}

int caminoPares(bintree<int> arbol) {
    // completar (posiblemente definiendo tambi√©n otras funciones)
    int maxDiam = 0;
    tInformacion info = recurS(arbol,maxDiam);
    return maxDiam;
}

void resuelveCaso() {
    bintree<int> arbol = leerArbol(-1);
    cout << caminoPares(arbol) << '\n';
}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
