#include "PrendaFactory.h"

PrendaFactory::PrendaFactory()
{

}

PrendaFactory::~PrendaFactory()
{

}

Prenda* PrendaFactory::GetPrenda(Tipo tipo)
{
	switch (tipo)
	{
	case PrendaFactory::MangaCorta:
		return new CamisaMangaCorta();
	case PrendaFactory::MangaLarga:
		return new CamisaMangaLarga();
	case PrendaFactory::Comun:
		return new PantalonComun();
	case PrendaFactory::Chupin:
		return new PantalonChupin();
	default:
		break;
	}

	return nullptr;
}