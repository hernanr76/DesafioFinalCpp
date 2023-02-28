#include "CamisaMangaCorta.h"

CamisaMangaCorta::CamisaMangaCorta()
{

}

string CamisaMangaCorta::Nombre()
{
	string cuello = getCuello() == mao ? "Mao" : "Común";
	return "Camisa Manga Corta - Cuello " + cuello + " - " + (getCalidad() == Prenda::Calidad::standard ? "Standard" : "Premium");
}