#pragma once
#include <vector>
#include <string>

using std::vector;
using std::string;

class GestorArchivo
{
	public:
		void leerEnemigosMuseo(int& i);
		void leerEnemigosHuaca(int& i);
		void leerEnemigosBiblioteca(int& i);
		void leerGuardia(int& x, int& y);
		void leerBateria(int& i);
};

