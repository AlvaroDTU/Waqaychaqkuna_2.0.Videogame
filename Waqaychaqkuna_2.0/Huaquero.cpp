#include "pch.h"
#include "Huaquero.h"
Huaquero::Huaquero(int posX, int posY, int an, int al, int anF, int alF, int dirX, int dirY, int obj, int vid, int tM)
	: Enemigo(posX, posY, an, al, anF, alF, dirX, dirY, obj)
{
	this->vidas = vid;
	this->tiempoMovimiento = tM;
}
Huaquero::~Huaquero() {}

int Huaquero::getVidas() { return this->vidas; }
void Huaquero::RestarVidas(int v) { this->vidas -= v; }
int Huaquero::getTemMov() { return this->tiempoMovimiento; }
void Huaquero::setTemMov(int TM) { tiempoMovimiento = TM; }

std::string Huaquero::getNombre() { return "huaquero"; }
Bitmap^ Huaquero::getBitmap() {
	return Recursos::huaquero;
}


void Huaquero::mover(int anchoLienzo, int altoLienzo) {
	moviendose = true;
	if (dirX < 0) { fila = 1; }
	else if (dirX > 0) { fila = 2; }
	else if (dirY < 0) { fila = 0; }
	else if (dirY > 0) { fila = 3; }

	posX += dirX;
	posY += dirY;

	Rectangle r = getRectangle(0);
	if (posX < 0) { posX = 0; }
	if (posY < 0) { posY = 0; }
	if (posX + r.Width > anchoLienzo)
		posX = anchoLienzo - r.Width;

	if (posY + r.Height > altoLienzo)
		posY = altoLienzo - r.Height;

}

// void atacar(Bien* bien) 
