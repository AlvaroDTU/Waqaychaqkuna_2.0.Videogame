#include "pch.h"
#include "Puntaje.h"
using namespace std;

Puntaje::Puntaje(string nombre, int puntos, string fecha)
{
    this->nombre = nombre;
    this->puntos = puntos;
    this->fecha = fecha;
}

string Puntaje::getNombre()
{
    return nombre;
}

int Puntaje::getPuntos()
{
    return puntos;
}

string Puntaje::getFecha()
{
    return fecha;
}
