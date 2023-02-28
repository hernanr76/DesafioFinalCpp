#pragma once
#include "IView.h"
#include <string>
#include "Presenter.h"
#include "PrendaFactory.h"

class View : public IView
{
private:
	Presenter* m_presenter;
	void showMainMenu();
	void runOption(const char* option, bool& exitCondition);
	void showCotizacion(Cotizacion* coti);
	void showHistorial();
	bool yesNoQuestion(string question, bool& exitCondition);
	void showCotizar_Paso1();
	void showCotizar_Paso2(int optPaso1);
	void showCotizar_Paso3(Prenda* prenda, bool& exitCondition);
	void showCotizar_Paso4(Prenda* prenda, bool& exitCondition);
	void showCotizar_Paso5(Cotizacion* cotizacion, bool& exitCondition);
	void showCotizar_Resultados(Cotizacion* cotizacion);

public:
	View();
	~View() override;
	void showText(const char* text);
	void showText(const std::string& text);

};

