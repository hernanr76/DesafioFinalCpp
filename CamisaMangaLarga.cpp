#include "CamisaMangaLarga.h"

CamisaMangaLarga::CamisaMangaLarga()
{

}

string CamisaMangaLarga::Nombre()
{
	string cuello = getCuello() == mao ? "Mao" : "Com�n";
	return "Camisa Manga Larga - Cuello " + cuello + " - " + (getCalidad() == Prenda::Calidad::standard ? "Standard" : "Premium");

}