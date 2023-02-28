#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include "View.h"
#include <stdlib.h>
#include <Windows.h>
#include <clocale>

const std::string ANY_KEY_MESSAGE = "Escribe cualquier tecla para continuar.";
const std::string INVALID_OPTION_MESSAGE = "La opción ingresada es inválida, por favor reintente.";
const std::string PRESIONE_3_PARA_VOLVER = "---------------------------------------------------------\nPresiona 3 para volver al menú principal\n---------------------------------------------------------";
const std::string PRESIONE_X_PARA_VOLVER = "---------------------------------------------------------\nPresiona X para volver al menú principal\n---------------------------------------------------------";

View::View()
{
	SetConsoleTitleW(L"Desafío final CPP");
	setlocale(LC_ALL, "es_Es");
	m_presenter = new Presenter(this);
	showMainMenu();
}

View::~View()
{
	delete m_presenter;
}

void View::showText(const char* text)
{
	std::cout << text << std::endl;
}

void View::showText(const std::string& text)
{
	std::cout << text << std::endl;
}

bool View::yesNoQuestion(string question, bool& exitCondition)
{
	string option;

	showText(PRESIONE_3_PARA_VOLVER);
	showText(question);
	showText("");
	showText("1) Si");
	showText("2) No");
	showText(PRESIONE_3_PARA_VOLVER);
	std::cin >> option;

	exitCondition = false;
	auto opt = option[0] - 48;

	switch (opt)
	{
	case 1:
		return true;
	case 2:
		break;
	default:
		exitCondition = true;
		break;
	}

	return false;
}

void View::showMainMenu()
{
	std::string option;
	bool exitCondition = false;

	do
	{
		std::system("cls");
		showText("COTIZADOR EXPRESS - MENÚ PRINCIPAL");
		showText("---------------------------------------------------------");
		m_presenter->getTiendaDetails();
		showText("---------------------------------------------------------");
		showText("");
		showText("SELECCIONE UNA OPCIÓN DEL MENÚ");
		showText("");
		showText("1) Historial de Cotizaciones");
		showText("2) Realizar Cotización");
		showText("3) Salir");
		std::cin >> option;
		std::system("cls");
		runOption(option.c_str(), exitCondition);

		if (!exitCondition)
		{
			showText("");
			showText(ANY_KEY_MESSAGE);
			std::cin.get();
			std::cin.get();
		}

	} while (!exitCondition);
}

void View::showCotizacion(Cotizacion* coti)
{
	auto prenda = coti->getPrenda();

	struct tm newtime;
	char buffer[32];

	auto fecha = coti->getFecha();
	std::strftime(buffer, 32, "%a, %d-%m-%Y %H:%M:%S", localtime(&fecha));
	string f = buffer;
	Camisa* esCamisa = nullptr;

	try
	{
		esCamisa = dynamic_cast<Camisa*>(prenda);
	}
	catch (const std::exception&)
	{

	}
	
	string cuello = "";

	if (esCamisa != nullptr)
		cuello = esCamisa->getCuello() == Camisa::mao ? " Cuello mao" : " Cuello común";

	showText("Número de identificación: " + std::to_string(coti->getId()));
	showText("Fecha y Hora de la cotización: " + f);
	showText("Código del vendedor: " + coti->getVendedor()->getCodigo());
	showText("Prenda cotizada: " + prenda->Nombre());
	showText("Precio unitario: $" + std::to_string(prenda->getPrecio()));
	showText("Cantidad de unidades cotizadas: " + std::to_string(coti->getCantidad()));
	showText("Precio final: $" + std::to_string(coti->getResultado()));
	showText("\n");

}

void View::showHistorial()
{
	std::string option;
	bool exitCondition = false;

	std::system("cls");
	showText("COTIZADOR EXPRESS - HISTORIAL DE COTIZACIONES");
	showText(PRESIONE_3_PARA_VOLVER);

	auto history = m_presenter->getHistory();

	for (Cotizacion* coti : *history)
	{
		showCotizacion(coti);
	}

	showText(PRESIONE_3_PARA_VOLVER);
	std::cin >> option;

}

void View::showCotizar_Paso1()
{
	std::string option;

	std::system("cls");
	showText("COTIZADOR EXPRESS - COTIZAR");
	showText(PRESIONE_3_PARA_VOLVER);
	showText("PASO 1: Selecciona la prenda a cotizar:");
	showText("");
	showText("1) Camisa");
	showText("2) Pantalón");
	showText(PRESIONE_3_PARA_VOLVER);
	std::cin >> option;

	auto opt = option[0] - 48;

	switch (opt)
	{
	case 1:
	case 2:
		showCotizar_Paso2(opt);
		break;
	default:
		break;
	}

}

void View::showCotizar_Paso2(int optPaso1)
{
	std::string option;
	bool exitCondition = false;
	auto coti = m_presenter->NewCotizacion();
	Prenda* prenda = nullptr;

	std::system("cls");

	switch (optPaso1)
	{
	case 1:
	{
		showText("COTIZADOR EXPRESS - COTIZAR");
		auto mangaCorta = yesNoQuestion("PASO 2.a: La camisa a cotizar, ¿Es manga corta?", exitCondition);

		std::system("cls");
		showText("COTIZADOR EXPRESS - COTIZAR");
		auto cuelloMao = yesNoQuestion("PASO 2.b: La camisa a cotizar, ¿Es cuello Mao?", exitCondition);

		if (mangaCorta)
			prenda = PrendaFactory::GetPrenda(PrendaFactory::MangaCorta);
		else
			prenda = PrendaFactory::GetPrenda(PrendaFactory::MangaLarga);

		if (cuelloMao)
			dynamic_cast<Camisa*>(prenda)->setCuello(Camisa::mao);
		else
			dynamic_cast<Camisa*>(prenda)->setCuello(Camisa::comun);


		break;
	}
	case 2:
	{
		showText("COTIZADOR EXPRESS - COTIZAR");
		auto chupin = yesNoQuestion("PASO 2: El pantalón a cotizar, ¿Es chupín?", exitCondition);

		if (chupin)
			prenda = PrendaFactory::GetPrenda(PrendaFactory::Chupin);
		else
			prenda = PrendaFactory::GetPrenda(PrendaFactory::Comun);

		break;
	}
	default:
		break;
	}

	if (!exitCondition && prenda != nullptr)
	{
		showCotizar_Paso3(prenda, exitCondition);
	}

	if (!exitCondition && prenda != nullptr)
	{
		showCotizar_Paso4(prenda, exitCondition);
	}

	if (!exitCondition && prenda != nullptr)
	{
		coti->setPrenda(prenda);
		showCotizar_Paso5(coti, exitCondition);
	}

	if (!exitCondition && prenda != nullptr)
	{
		coti->Calcular();
		showCotizar_Resultados(coti);
		
	}
	else if (prenda != nullptr)
		delete prenda;


}

void View::showCotizar_Paso3(Prenda* prenda, bool& exitCondition)
{
	std::system("cls");
	string option;

	showText("COTIZADOR EXPRESS - COTIZAR");
	showText(PRESIONE_3_PARA_VOLVER);
	showText("PASO 3: seleccione la calidad de la prenda");
	showText("1) Standard");
	showText("2) Premium");
	showText(PRESIONE_3_PARA_VOLVER);
	std::cin >> option;

	auto opt = option[0] - 48;
	exitCondition = false;

	switch (opt)
	{
	case 1:
		prenda->setCalidad(Prenda::standard);
		break;
	case 2:
		prenda->setCalidad(Prenda::premium);
		break;
	default:
		exitCondition = true;
		break;
	}
	
}

void View::showCotizar_Paso4(Prenda* prenda, bool& exitCondition)
{
	std::system("cls");
	string option;

	showText("COTIZADOR EXPRESS - COTIZAR");
	showText(PRESIONE_X_PARA_VOLVER);
	showText("PASO 4: Ingrese el precio unitario de la prenda a cotizar");
	showText(PRESIONE_X_PARA_VOLVER);
	std::cin >> option;

	auto unitPrice = atof(option.c_str());
	exitCondition = false;

	if (option[0] == 'X')
		exitCondition = true;
	else
	{
		prenda->setPrecio(unitPrice);
	}

}

void View::showCotizar_Paso5(Cotizacion* cotizacion, bool& exitCondition)
{
	string option;
	auto stock = m_presenter->GetStock(cotizacion);

	std::system("cls");
	showText("COTIZADOR EXPRESS - COTIZAR");
	showText(PRESIONE_X_PARA_VOLVER);

	showText("\nINFORMACIÓN:");
	if (stock == nullptr)
	{
		showText("NO SE ENCUENTRA STOCK PARA " + cotizacion->getPrenda()->Nombre());
		exitCondition = true;
	}
	else
	{
		showText("EXISTE " + std::to_string(stock->stock) + " DE UNIDADES EN STOCK DE LA PRENDA " + cotizacion->getPrenda()->Nombre());

		showText("\nPASO 5: Ingrese la cantidad de unidades a cotizar");
		showText(PRESIONE_X_PARA_VOLVER);
		std::cin >> option;

		auto quantity = atoi(option.c_str());
		exitCondition = false;

		if (option[0] == 'X')
			exitCondition = true;
		else
		{
			if (stock->stock >= quantity)
			{
				cotizacion->setCantidad(quantity);
				stock->stock -= quantity;
			}
			else
			{
				showText("\nNO SE PUEDE COTIZAR UNA CANTIDAD MAYOR AL STOCK\n");
				exitCondition = true;
			}
		}
	}
}

void View::showCotizar_Resultados(Cotizacion* cotizacion)
{
	std::system("cls");
	showText("COTIZADOR EXPRESS - COTIZAR");
	showText(PRESIONE_3_PARA_VOLVER);
	showCotizacion(cotizacion);
	showText(PRESIONE_3_PARA_VOLVER);

}

void View::runOption(const char* option, bool& exitCondition)
{
	exitCondition = false;
	auto opt = option[0] - 48;

	switch (opt)
	{
	case 1:
		showHistorial();

		break;
	case 2:
		showCotizar_Paso1();

		break;
	case 3:
		exitCondition = true;
		break;
	default:
		showText(INVALID_OPTION_MESSAGE);
		break;
	}
}