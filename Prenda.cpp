#include "Prenda.h"

Prenda::Prenda()
{
	precio = 0;
	calidad = standard;
}

Prenda::~Prenda()
{

}

void Prenda::setPrecio(double precio)
{
	this->precio = precio;
}

double Prenda::getPrecio()
{
	return precio;
}

void Prenda::setCalidad(Calidad calidad)
{
	this->calidad = calidad;
}

Prenda::Calidad Prenda::getCalidad()
{
	return calidad;
}
