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
		void setCodigo(string codigo);
		void setVendedor(Vendedor* vendedor);
		void setPrenda(Prenda* prenda);
		void setCantidad(int cantidad);
		void setResultado(double resultado);
		int getId();
		time_t getFecha();
		string getCodigo();
		Vendedor* getVendedor();
		Prenda* getPrenda();
		int getCantidad();
		double getResultado();

	private:
		int id;
		time_t fecha;
		string codigo;
		Vendedor* vendedor;
		Prenda* prenda;
		int cantidad;
		double resultado;
};

