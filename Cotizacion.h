#pragma once
#include <iostream>
#include <ctime>
#include "Vendedor.h"
#include "Prenda.h"

using namespace std;

class Vendedor;
class Prenda;

class Cotizacion
{
	public:
		Cotizacion();
		~Cotizacion();
		void setId(int id);
		void setFecha(time_t fecha);
		void setVendedor(Vendedor* vendedor);
		void setPrenda(Prenda* prenda);
		void setCantidad(int cantidad);
		void setResultado(double resultado);
		int getId();
		time_t getFecha();
		Vendedor* getVendedor();
		Prenda* getPrenda();
		int getCantidad();
		double getResultado();
		void Calcular();

	private:
		int id;
		time_t fecha;
		Vendedor* vendedor;
		Prenda* prenda;
		int cantidad;
		double resultado;
};

