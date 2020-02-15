#ifndef pila_h
#define pila_h

#include <stdexcept>
#include <utility>

template<class T>
class pila
{
protected:
	static const int TAM_INI = 10;// tamaño inicial del array dinámico
    
    // número de elementos en la pila
	int nelems;

	// tamaño del array
	int capacidad;

	// puntero al array que contiene los datos (redimensionable)
	T* array;
public:
	//Constructor: pila vacía 
	pila() : nelems(0), capacidad(TAM_INI), array(new T[capacidad]) {

	}
	//destructor
	~pila()
	{
		libera();
	}
	//constructor por copia
	pila(pila < T const& >other)
	{
		copia(other);
	}
	//operador de asignacion
	pila<T>& operator =(pila<T> const& other)
	{
		if (this != &other)
		{
			libera();
			copia(other);
		}
		return *this;
	}
	//apilar un elemento
	void push(T const& elem)
	{
		array[nelems] = elem;
		++nelems;
		if (nelems == capacidad) amplia();
	}
	//consultar la cima
	T const& top() const {
		if (empty())
			throw std::domain_error("la pila vacia no tiene cima");
		return array[nelems - 1];
	}
	//desapilar el elemento en la cima
	void pop()
	{
		if (empty())
			throw std::domain_error("desapilando de la pila vacia");
		--nelems;
	}
	//consultar si la pila está vacia
	bool empty() const
	{
		return nelems == 0;
	}
	//consultar el tamaño de la pila
	int size()const
	{
		return nelems;
	}
protected:
	void libera()
	{
		delete[]array;
	}
	//this está sin inicializar
	void copia(pila const& other)
	{
		capacidad = other.nelems + TAM_INI;
		nelems = other.nelems;
		array = new T[capacidad];
		for (int i = 0; i < nelems; ++i)
			array[i] = other.array[i];
	}
	void amplia()
	{
		T* viejo = array;
		capacidad *= 2;
		array = new T[capacidad];
		for (int i = 0; i < nelems; ++i)array[i] = std::move(viejo[i]);
		delete[] viejo;
	}
};

#endif