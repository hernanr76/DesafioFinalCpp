#include "Cotizacion.h"

Cotizacion::Cotizacion()
{

}

Cotizacion::~Cotizacion()
{

}

void Cotizacion::setId(int id)
{
	this->id = id;
}

void Cotizacion::setFecha(time_t fecha)
{
	this->fecha = fecha;
}

void Cotizacion::setCodigo(string codigo)
{
	this->codigo = codigo;
}

void Cotizacion::setVendedor(Vendedor* vendedor)
{
	this->vendedor = vendedor;
}

void Cotizacion::setPrenda(Prenda* prenda)
{
	this->prenda = prenda;
}

void Cotizacion::setCantidad(int cantidad)
{
	this->cantidad = cantidad;
}

void Cotizacion::setResultado(double resultado)
{
	this->resultado = resultado;
}

int Cotizacion::getId()
{
	return id;
}

time_t Cotizacion::getFecha()
{
	return fecha;
}

string Cotizacion::getCodigo()
{
	return codigo;
}

Vendedor* Cotizacion::getVendedor()
{
	return vendedor;
}

Prenda* Cotizacion::getPrenda()
{
	return prenda;
}

int Cotizacion::getCantidad()
{
	return cantidad;
}

double Cotizacion::getResultado()
{
	return resultado;
}
