#pragma once
#include "Prenda.h"
#include "Camisa.h"
#include "Pantalon.h"
#include "CamisaMangaCorta.h"
#include "CamisaMangaLarga.h"
#include "PantalonChupin.h"
#include "PantalonComun.h"

class PrendaFactory
{
public:
	enum Tipo {	MangaCorta, MangaLarga, Comun, Chupin };
	PrendaFactory();
	~PrendaFactory();
	static Prenda* GetPrenda(Tipo tipo);
};

