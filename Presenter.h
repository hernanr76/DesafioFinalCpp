#pragma once
#include "IView.h"
#include "Tienda.h"
#include "Cotizacion.h"

class Presenter
{
private:
	IView* m_view = nullptr;
	Tienda* m_tienda = nullptr;
public:
	explicit Presenter(IView* view);
	~Presenter();
	void getTiendaDetails();
	vector<Cotizacion*>* getHistory();
	Cotizacion* NewCotizacion();
	Tienda::Stock* GetStock(Cotizacion* coti);
};
