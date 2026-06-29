#pragma once
#include "Escenario.h"
#include "Guardia.h"
#include "Manipulador.h"
#include "Archivo.h"
#include <vector>

using std::vector;

class GestorBiblioteca : public Escenario
{
	private:
	int tiempoRecarga;

	public:
		GestorBiblioteca(int enTotal);
		~GestorBiblioteca();
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

