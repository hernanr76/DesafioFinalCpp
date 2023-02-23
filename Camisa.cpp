#include "Camisa.h"

Camisa::Camisa()
{
	this->cuello = comun;
}

Camisa::~Camisa()
{

}

void Camisa::setCuello(Cuello cuello)
{
	this->cuello = cuello;
}

Camisa::Cuello Camisa::getCuello()
{
	return cuello;
}
