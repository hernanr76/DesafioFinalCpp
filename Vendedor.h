#pragma once
#include <iostream>
#include <vector>
#include "Cotizacion.h"
#include "Tienda.h"

using namespace std;

class Cotizacion;
class Tienda;

class Vendedor
{
	public:
		Vendedor();
		~Vendedor();
		void setNombre(string nombre);
		void setApellido(string apellido);
		void setCodigo(string codigo);
		string getNombre();
		string getApellido();
		string getCodigo();
		Tienda* getTrabajaEn();
		void setTrabajaEn(Tienda* tienda);
		vector<Cotizacion*>* Cotizaciones;

	private:
		string nombre;
		string apellido;
		string codigo;
		int cantidadCotizaciones;
		Tienda* trabajaEn;

};

