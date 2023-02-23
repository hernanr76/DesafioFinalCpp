#include "Vendedor.h"

Vendedor::Vendedor()
{

}

Vendedor::~Vendedor()
{

}

void Vendedor::setNombre(string nombre)
{
	this->nombre = nombre;
}

void Vendedor::setApellido(string apellido)
{
	this->apellido = apellido;
}

void Vendedor::setCodigo(string codigo)
{
	this->codigo = codigo;
}

string Vendedor::getNombre()
{
	return nombre;
}

string Vendedor::getApellido()
{
	return apellido;
}

string Vendedor::getCodigo()
{
	return codigo;
}

vector<Cotizacion> Vendedor::getCotizaciones()
{
	return cotizaciones;
}
