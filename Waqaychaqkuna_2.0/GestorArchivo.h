#pragma once
#include <vector>
#include <string>
#include "Puntaje.h"
#include <fstream>
#include <ctime>

using std::vector;
using std::string;

class GestorArchivo
{
	public:
		void cargarTodo(int& n1, int& n2, int& n3, int& gx, int& gy, int& bat);
		void guardarBinario(Puntaje* p);
		std::vector<Puntaje*> leerBinario();
		vector<Puntaje*> leerTexto();
		void guardarTexto(Puntaje* p);
		int ultimoPuntaje();
		string fechaActual();
		int leerRecord();
		void guardarRecord(int puntos);
};

