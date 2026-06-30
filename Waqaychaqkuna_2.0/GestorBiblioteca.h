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
	double tiempoRecarga;
	int intentos;

	public:
		GestorBiblioteca(int enTotales);
		~GestorBiblioteca();
		void crearSprites() override;
		void dibujar(Graphics^ g) override;
		void mover() override;
		void detectarColisiones() override;

		bool victoria() override;
		bool derrota() override;

		void jugar();
		void setearColisionesMapa();

		void generarManipulador();
		void recargaLinterna();
};

