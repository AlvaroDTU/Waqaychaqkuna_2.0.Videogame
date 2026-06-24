#include "pch.h"
#include "Reportera.h"

Reportera::Reportera(int posX, int posY, int an, int al, int anF, int alF, bool ayuda, int TipPis)
	: Aliado(posX, posY, an, al, anF, alF, ayuda)
{
	this->tipoPista = TipPis;
}
Reportera::~Reportera() {}

int Reportera::getTipoPista() { return this->tipoPista; }
void Reportera::setTipoPista(int Tp) { this->tipoPista = Tp; }

Bitmap^ Reportera::getBitmap() {
	return Recursos::reportera;
}

std::string Reportera::getNombre() { return "reportera"; }
void Reportera::dibujar(Graphics^ g) {
	Bitmap^ img = getBitmap();

	this->alto = img->Height / 2;
	this->ancho = img->Width / 4;

	Rectangle molde = Rectangle(columna * ancho, fila * alto, ancho, alto);

	avanzarEscena();
	g->DrawImage(img, posX, posY, molde, GraphicsUnit::Pixel);
	fila++;
	if (fila == 2) { fila = 1; }
	moviendose = true;
}

void Reportera::mover(int ancho, int alto) {}

void Reportera::ayudar() {}