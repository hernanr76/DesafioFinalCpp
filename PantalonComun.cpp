#include "PantalonComun.h"

PantalonComun::PantalonComun()
{

}

string PantalonComun::Nombre()
{
	string calidad = getCalidad() == Prenda::Calidad::standard ? "Standard" : "Premium";
	return "Pantal�n Com�n - " + calidad;
}