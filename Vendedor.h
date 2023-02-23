#pragma once
#include <iostream>
#include <vector>
#include "Cotizacion.h"
using namespace std;

class Cotizacion;

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
		vector<Cotizacion> getCotizaciones();

	private:
		string nombre;
		string apellido;
		string codigo;
		int cantidadCotizaciones;
		vector<Cotizacion> cotizaciones; 

};

