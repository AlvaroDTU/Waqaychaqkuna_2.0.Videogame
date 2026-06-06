#include "pch.h"
#include "Cuidador.h"
Cuidador::Cuidador(int posX, int posY, int dirX, int dirY, bool ayuda, int dura)
	: Aliado(posX,posY,dirX,dirY,ayuda)
{
	this->duracion = dura;
}
Cuidador::~Cuidador(){}

int Cuidador::getDuracion() { return this->duracion; }
void Cuidador::RestarDuracion(int d) { this->duracion = d; }


std::string Cuidador::getNombre() { return "cuidador"; }

void Cuidador::dibujar(Graphics^ g) {
	// CAMBIAR LUEGO A :
// Bitmap^ img = Recursos::cuidador;
	Bitmap^ img = Recursos::guardia;

	ancho = img->Width / 4;
	alto = img->Height / 4;

	Rectangle molde = Rectangle(columna * ancho, fila * ancho, ancho, alto);

	if (moviendose == true) {
		columna++;
		if (columna == 4) { columna = 0; }
	}
	else
	{
		columna = 0;
	}
	g->DrawImage(img, posX, posY, molde, GraphicsUnit::Pixel);

	moviendose = false;

}