#pragma once
#include <iostream>
#include <vector>
#include "Prenda.h"
#include "Vendedor.h"

using namespace std;

class Vendedor;

class Tienda
{
public:
	class Stock
	{
	public:
		Prenda* prenda;
		int stock;
	private:

	};

	Tienda();
	~Tienda();
	void setNombre(string nombre);
	string GetNombre();
	void setDireccion(string direccion);
	string GetDireccion();
	Vendedor* getVendedor();
	vector<Stock*>* stock;
private:
	string nombre;
	string direccion;
	Vendedor* vendedor;
	void CreateStock();
};

