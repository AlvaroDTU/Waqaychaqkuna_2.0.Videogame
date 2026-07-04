#pragma once
#include "Guardia.h"
#include "Escenario.h"
#include "Murcielago.h"
#include "Manipulador.h"
#include "Archivo.h"
#include "Linterna.h"
#include <vector>

using std::vector;

class GestorBiblioteca : public Escenario
{
	private:
	int contador;
	double tiempoRecarga;
	double vidas;
	Linterna* linterna;

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
		double getTiempoRecarga();
		double getVidas();
		Linterna* getLinterna();
		bool encenderLinterna();
		Bitmap^ getBitmap();
		void dibujarLibros(Graphics^ g);

};

