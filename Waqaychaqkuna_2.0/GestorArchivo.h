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
		void cargarTodo(int& n1, int& n2, int& n3, int& gx1, int& gy1, int& gx2, int& gy2, int& gx3, int& gy3, int& bat);
		void guardarBinario(Puntaje* p);
		std::vector<Puntaje*> leerBinario();
		vector<Puntaje*> leerTexto();
		void guardarTexto(Puntaje* p);
		string fechaActual();
		void eliminarPuntajeBinario(string nombre);
};

