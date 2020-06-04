
// Luis Ariza L�pez

/* 
Procedo a comentar la soluci�n sobre el problema A:

Tras pensar el problema llegu� a la conclusi�n de que 
lo que nos piden es que a medida que iteramos la doble cola si encontramos un elemento mayor que el pivote debemos 
reasignar su posicion para mandarlo al final de la cola.Ser�a como quitar una persona de una fila para enviarla atr�s del 
todo, para ello los elementos situados entre medias deben quedar actualizados y el �ltimo de la lista tambi�n.

Lo que realizamos principalmente es iterar sobre la doble cola, si encontramos un elemento a desplazar, nos quedamos
con el nodo anterior y el siguiente del elemento a insertar(vease NodoAInsertar,NodoSiguiente,NodoAnterior) y hacemos 
que el siguiente del anterior sea el anterior y el anterior del siguiente sea el siguiente,con eso el elemento que va a ir
fondo est� fuera de la lista y solo queda insertarlo al final, para ello trabajamos con el fantasma y el �ltimo nodo(anterior al fantasma)
y lo que hacemos es que el siguiente del �ltimo nodo ser� el nodo a insertar y el anterior del fantasma ser� ahora el nodo
insertado, por �ltimo queda actualizar el �ltimo y siguiente del nodo, para ello hacemos que el anterior del nodo insertado
sea NodoUltimo y el siguiente el fantasma

Respecto al coste:
    ->En el bucle for se realizan n iteraciones donde n es el tama�o de la cola
    ->Dentro de cada iteraci�n simplemente actualizamos el sigiente y el anterior de los nodos asi que el coste es constante
    ->Por ultimo el m�todo mostrar tambi�n realiza n iteraciones
Por tanto el coste de este algoritmo es lineal.
*/

#include <iostream>               
#include <fstream>               
#include <algorithm>

#include "deque_eda.h"
using namespace std;

class ListaParticion : public deque<int> {
public:
    void print(std::ostream& o = std::cout) const {
        Nodo* aux = this->fantasma->sig;
        while (aux != this->fantasma)
        {
            cout << aux->elem << " ";
            aux = aux->sig;
        }
    }

    // produce la partici�n de la lista respecto al privote
    void particion(int pivote) {
        // rellenar
        int numIter = this->nelems;
        Nodo* aux = this->fantasma->sig;
        for (int i = 0; i < numIter; i++)
        {
            Nodo* next=aux->sig;
            if (aux->elem > pivote)
            {
                //Corresponde a "quitar" el nodo de su posici�n actual
                Nodo* nodoAinsertar = aux;
                Nodo* nodoAnterior = aux->ant;
                Nodo* nodoSiguiente = aux->sig;
                nodoAnterior->sig = nodoSiguiente;
                nodoSiguiente->ant = nodoAnterior;

                //Corresponde a a�adir el nodo quitado en la ultima posici�n
                Nodo* nodoUltimo = this->fantasma->ant;
                nodoUltimo->sig = nodoAinsertar;
                nodoAinsertar->ant = nodoUltimo;
                nodoAinsertar->sig = this->fantasma;
                this->fantasma->ant = nodoAinsertar;
            }
            aux = next;
        }
    }
};



/////////////////////////////////////////////////////////
// de aqu� hacia abajo NO se puede modificar nada

inline std::ostream& operator<<(std::ostream& o, ListaParticion const& a) {
    a.print(o);
    return o;
}

bool resuelveCaso() {
    int N, pivote;
    cin >> N >> pivote;
    if (!cin)
        return 0;

    ListaParticion lista;
    // leemos la lista de la entrada
    int elem;
    for (int i = 0; i < N; ++i) {
        cin >> elem;
        lista.push_back(elem);
    }


    lista.particion(pivote);

    cout << lista << '\n';

    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    // system("PAUSE");
#endif
    return 0;
}