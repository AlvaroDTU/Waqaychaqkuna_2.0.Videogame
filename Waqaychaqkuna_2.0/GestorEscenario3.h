#pragma once
#include "Guardia.h"
#include "Manipulador.h"
#include "Archivo.h"
#include <vector>

using std::vector;

class GestorEscenario3
{
	private:
	Guardia * guardia;
	vector<Enemigo*> manipuladores;
	vector<Bien*> archivos;
	int anchoLienzo;
	int altoLienzo;
	int enemigosTotales;
	int enemigosDerrotados;
	int temporizador;
	int puntajeNivel;
	int tiempoRecarga;

	public:
		GestorEscenario3(Guardia* guardia, int anchoLienzo, int altoLienzo, int enemigosTotales);
		~GestorEscenario3();
		void mover();
		void moverGuardia(Direccion direccion);
		void dibujar(Graphics^ g);
		void detectarColisiones();
		bool victoria();
		int getTotalManipulador();

		void jugar();
		void agregarManipulador(Manipulador* nuevo);
		void eliminarManipulador(int i);
		void recargaLinterna();
};

