#pragma once
#include <string>

using std::string;

class Puntaje
{
private:
    string nombre;
    int puntos;
    string fecha;

public:
    Puntaje(string nombre, int puntos, string fecha);
    string getNombre();
    int getPuntos();
    string getFecha();
};
