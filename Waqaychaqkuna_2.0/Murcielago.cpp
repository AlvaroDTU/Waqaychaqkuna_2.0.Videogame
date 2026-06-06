#include "pch.h"
#include "Murcielago.h"
Murcielago::Murcielago(int posX, int posY, int dirX, int dirY, bool ayuda, 
	int Tr) : Aliado (posX, posY, dirX, dirY,ayuda)
{}
Murcielago::~Murcielago(){}

std::string Murcielago::getNombre() { return "murcielago"; }

void Murcielago::dibujar(Graphics^ g) {
// Luego cambiar a Bitmao^ img = Recursos::murcilago;
	Bitmap^ img = Recursos::bat;
	this->alto = img->Height / 1;
	this->ancho = img->Width / 1;

	Rectangle model = Rectangle(ancho * columna, alto * fila, ancho, alto);
	g->DrawImage(img, posX, posY, model, GraphicsUnit::Pixel);

}