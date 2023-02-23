#pragma once
#include "Cotizacion.h"
class HistorialCotizaciones
{
private:
    class Nodo {
    public:
        Cotizacion cotizacion;
        Nodo* sig;
    };

    Nodo* raiz;
public:
    HistorialCotizaciones();
    ~HistorialCotizaciones();
    int cantidad();
    void insertar(int pos, Cotizacion cotizacion);
    Cotizacion extraer(int pos);
    void borrar(int pos);
    void intercambiar(int pos1, int pos2);
    bool vacia();
    void imprimir();
    int posMayor();
    bool ordenada();
};

