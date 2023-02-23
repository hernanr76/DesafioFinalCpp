#pragma once
#include <iostream>

using namespace std;

class Tienda
{
public:
	Tienda();
	~Tienda();
	void setNombre(string nombre);
	string GetNombre();
	void setDireccion(string direccion);
	string GetDireccion();
private:
	string nombre;
	string direccion;
};

