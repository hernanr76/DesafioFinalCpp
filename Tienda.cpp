#include "Tienda.h"
#include "PantalonChupin.h"
#include "PantalonComun.h"
#include "CamisaMangaCorta.h"
#include "CamisaMangaLarga.h"

const std::string DEFAULT_NAME = "Pilcheria 1987";
const std::string DEFAULT_ADDRESS = "Callefalsa 123";

Tienda::Tienda()
{
	nombre = DEFAULT_NAME;
	direccion = DEFAULT_ADDRESS;
	vendedor = new Vendedor;
	vendedor->setTrabajaEn(this);
	CreateStock();
}

Tienda::~Tienda()
{
	delete vendedor;

	for (Stock* s : *stock)
	{
		delete s->prenda;
		delete s;
	}

	delete stock;
}

void Tienda::setNombre(string nombre)
{
	this->nombre = nombre;
}

string Tienda::GetNombre()
{
	return nombre;
}

void Tienda::setDireccion(string direccion)
{
	this->direccion = direccion;
}

string Tienda::GetDireccion()
{
	return direccion;
}

Vendedor* Tienda::getVendedor()
{
	return vendedor;
}

void Tienda::CreateStock()
{
	Stock* item;
	PantalonChupin* chupin;
	PantalonComun* comun;
	CamisaMangaCorta* mangaCorta;
	CamisaMangaLarga* mangaLarga;

	stock = new vector<Stock*>();

	chupin = new PantalonChupin();
	chupin->setCalidad(Prenda::standard);
	chupin->setPrecio(1000);
	item = new Stock();
	item->stock = 750;
	item->prenda = chupin;
	stock->push_back(item);

	chupin = new PantalonChupin();
	chupin->setCalidad(Prenda::premium);
	chupin->setPrecio(2000);
	item = new Stock();
	item->stock = 750;
	item->prenda = chupin;
	stock->push_back(item);

	comun = new PantalonComun();
	comun->setCalidad(Prenda::standard);
	comun->setPrecio(1000);
	item = new Stock();
	item->stock = 250;
	item->prenda = comun;
	stock->push_back(item);

	comun = new PantalonComun();
	comun->setCalidad(Prenda::premium);
	comun->setPrecio(2000);
	item = new Stock();
	item->stock = 250;
	item->prenda = comun;
	stock->push_back(item);

	mangaCorta = new CamisaMangaCorta();
	mangaCorta->setCalidad(Prenda::standard);
	mangaCorta->setCuello(Camisa::mao);
	mangaCorta->setPrecio(1000);
	item = new Stock();
	item->stock = 100;
	item->prenda = mangaCorta;
	stock->push_back(item);

	mangaCorta = new CamisaMangaCorta();
	mangaCorta->setCalidad(Prenda::standard);
	mangaCorta->setCuello(Camisa::comun);
	mangaCorta->setPrecio(1000);
	item = new Stock();
	item->stock = 150;
	item->prenda = mangaCorta;
	stock->push_back(item);

	mangaCorta = new CamisaMangaCorta();
	mangaCorta->setCalidad(Prenda::premium);
	mangaCorta->setCuello(Camisa::mao);
	mangaCorta->setPrecio(2000);
	item = new Stock();
	item->stock = 100;
	item->prenda = mangaCorta;
	stock->push_back(item);

	mangaCorta = new CamisaMangaCorta();
	mangaCorta->setCalidad(Prenda::premium);
	mangaCorta->setCuello(Camisa::comun);
	mangaCorta->setPrecio(2000);
	item = new Stock();
	item->stock = 150;
	item->prenda = mangaCorta;
	stock->push_back(item);

	mangaLarga = new CamisaMangaLarga();
	mangaLarga->setCalidad(Prenda::standard);
	mangaLarga->setCuello(Camisa::mao);
	mangaLarga->setPrecio(1000);
	item = new Stock();
	item->stock = 75;
	item->prenda = mangaLarga;
	stock->push_back(item);

	mangaLarga = new CamisaMangaLarga();
	mangaLarga->setCalidad(Prenda::standard);
	mangaLarga->setCuello(Camisa::comun);
	mangaLarga->setPrecio(1000);
	item = new Stock();
	item->stock = 175;
	item->prenda = mangaLarga;
	stock->push_back(item);

	mangaLarga = new CamisaMangaLarga();
	mangaLarga->setCalidad(Prenda::premium);
	mangaLarga->setCuello(Camisa::mao);
	mangaLarga->setPrecio(2000);
	item = new Stock();
	item->stock = 75;
	item->prenda = mangaLarga;
	stock->push_back(item);

	mangaLarga = new CamisaMangaLarga();
	mangaLarga->setCalidad(Prenda::premium);
	mangaLarga->setCuello(Camisa::comun);
	mangaLarga->setPrecio(2000);
	item = new Stock();
	item->stock = 175;
	item->prenda = mangaLarga;
	stock->push_back(item);

}