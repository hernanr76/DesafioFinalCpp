#include "Tienda.h"

Tienda::Tienda()
{

}

Tienda::~Tienda()
{

}

void Tienda::setNombre(string nombre)
{
	this->nombre = nombre;
}

string Tienda::GetNombre()
{
	return nombre;
}

void Tienda::setDireccion(string direccion)
{
	this->direccion = direccion;
}

string Tienda::GetDireccion()
{
	return direccion;
}
