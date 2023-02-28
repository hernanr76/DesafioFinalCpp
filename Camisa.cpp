#include "Camisa.h"

Camisa::Camisa()
{
	this->cuello = comun;
}

Camisa::~Camisa()
{

}

string Camisa::Nombre()
{
	return "Camisa";
}

void Camisa::setCuello(Cuello cuello)
{
	this->cuello = cuello;
}

Camisa::Cuello Camisa::getCuello()
{
	return cuello;
}
