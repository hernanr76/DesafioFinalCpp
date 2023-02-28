#pragma once
#include "Prenda.h"
class Camisa : public Prenda
{
public:
	enum Cuello { mao, comun };
	Camisa();
	~Camisa();
	virtual string Nombre();
	void setCuello(Cuello cuello);
	Cuello getCuello();
private:
	Cuello cuello;
};

