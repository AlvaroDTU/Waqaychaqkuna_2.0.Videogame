#include "pch.h"
#include "Murcielago.h"
Murcielago::Murcielago(int posX, int posY, int an, int al, int anF, int alF, bool ayuda)
	: Aliado(posX, posY, an, al, anF, alF, ayuda)
{}

Murcielago::~Murcielago() {}

std::string Murcielago::getNombre() { return "murcielago"; }

void Murcielago::dibujar(Graphics^ g) {
	// Luego cambiar a Bitmao^ img = Recursos::murcilago;
	Bitmap^ img = Recursos::guardia;

	this->alto = img->Height / 1;
	this->ancho = img->Width / 1;

	Rectangle model = Rectangle(ancho * columna, alto * fila, ancho, alto);
	g->DrawImage(img, posX, posY, model, GraphicsUnit::Pixel);

}