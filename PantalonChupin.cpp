#include "PantalonChupin.h"

PantalonChupin::PantalonChupin()
{
	
}

string PantalonChupin::Nombre()
{
	string calidad = getCalidad() == Prenda::Calidad::standard ? "Standard" : "Premium";
	return "Pantal�n Chup�n - " + calidad;
}