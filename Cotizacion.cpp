#include "Cotizacion.h"
#include "Camisa.h"
#include "CamisaMangaCorta.h"
#include "CamisaMangaLarga.h"
#include "PantalonChupin.h"

Cotizacion::Cotizacion()
{
	cantidad = 0;
	fecha = std::time(0);
	id = 0;
	prenda = nullptr;
	vendedor = nullptr;
	resultado = 0;
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

void Cotizacion::Calcular()
{

	if (prenda == nullptr)
		throw new exception("La cotización no tiene prenda");

	if (vendedor == nullptr)
		throw new exception("La cotización no tiene vendedor");

	resultado = prenda->getPrecio() * cantidad;

	auto esCamisa = dynamic_cast<Camisa*>(prenda);
	auto esCamisaMC = dynamic_cast<CamisaMangaCorta*>(prenda);
	auto esCamisaML = dynamic_cast<CamisaMangaLarga*>(prenda);
	auto esPantalonChupin = dynamic_cast<PantalonChupin*>(prenda);

	if (esCamisaMC != nullptr)
	{
		resultado -= resultado * .1;
	}

	if (esCamisa != nullptr && esCamisa->getCuello() == Camisa::mao)
	{
		resultado += resultado * .03;
	}

	if (esPantalonChupin != nullptr)
	{
		resultado -= resultado * .12;
	}

	if (prenda->getCalidad() == Prenda::premium)
	{
		resultado += .3;
	}

}