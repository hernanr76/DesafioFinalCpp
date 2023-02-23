#pragma once
#include <iostream>

using namespace std;

class Prenda
{
public:
	enum Calidad { standard, premium };
	Prenda();
	~Prenda();
	virtual string Nombre() = 0;
	void setPrecio(double precio);
	double getPrecio();
	void setCalidad(Calidad calidad);
	Calidad getCalidad();
private:
	double precio;
	Calidad calidad;
};

