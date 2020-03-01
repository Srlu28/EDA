#pragma once
#include <iostream>
using namespace std;
#include <string>

class Persona {
private:
	string nombre;
	int age;
public:
	Persona() {};
	Persona(string name, int edad)
	{
		this->nombre = name;
		this->age = edad;
	}
	int edad() const { return age; }
	string name() const { return nombre;}
	void establish(string nom, int age)
	{
		this->nombre = nom;
		this->age = age;
	}
};
inline ostream& operator<<(ostream& out, const Persona& p) {
	out << p.name();
	return out;
}

inline istream& operator>>(istream& in, Persona& p) {
	int edad;
	string name;
	string nombre;
	cin >> edad;
	cin.ignore();
	getline(cin, nombre);
	p.establish(nombre, edad);
	return in;
}
