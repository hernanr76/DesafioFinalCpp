#include "Vendedor.h"

const std::string DEFAULT_FIRST_NAME = "Tino";
const std::string DEFAULT_LAST_NAME = "Travelino";
const std::string DEFAULT_ID = "V001";

Vendedor::Vendedor()
{
	nombre = DEFAULT_FIRST_NAME;
	apellido = DEFAULT_LAST_NAME;
	codigo = DEFAULT_ID;
	trabajaEn = nullptr;
	cantidadCotizaciones = 0;
	Cotizaciones = new vector<Cotizacion*>;
}

Vendedor::~Vendedor()
{
	for (Cotizacion* coti : *Cotizaciones)
		delete coti;

	delete Cotizaciones;
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

Tienda* Vendedor::getTrabajaEn()
{
	return trabajaEn;
}

void Vendedor::setTrabajaEn(Tienda* tienda)
{
	trabajaEn = tienda;
}
