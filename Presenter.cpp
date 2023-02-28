#include "Presenter.h"

Presenter::Presenter(IView* view) : m_view(view), m_tienda(new Tienda())
{

}

Presenter::~Presenter()
{
	delete m_tienda;
};

void Presenter::getTiendaDetails()
{
	m_view->showText(m_tienda->GetNombre() + " | " + m_tienda->GetDireccion());
}

vector<Cotizacion*>* Presenter::getHistory()
{
	return m_tienda->getVendedor()->Cotizaciones;
}

Cotizacion* Presenter::NewCotizacion()
{
	auto coti = new Cotizacion();
	auto vendedor = m_tienda->getVendedor();
	coti->setVendedor(vendedor);
	auto vectorCoti = vendedor->Cotizaciones;
	vectorCoti->push_back(coti);
	coti->setId(vectorCoti->size());

	return coti;
}

Tienda::Stock* Presenter::GetStock(Cotizacion* coti)
{
	Tienda::Stock* item = nullptr;

	for (Tienda::Stock* item : *m_tienda->stock)
	{
		if (coti->getPrenda()->Nombre() == item->prenda->Nombre())
			return item;
	}

	return nullptr;

}