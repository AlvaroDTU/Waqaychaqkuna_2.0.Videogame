#include "pch.h"
#include "Huaquero.h"
Huaquero::Huaquero(int x, int y, int dx, int dy, 
	bool at, int obj, int vid, int tM) : Enemigo (posX, posY,
		dirX, dirY, at, obj) 
{
	this->vidas = vid;
	this->tiempoMovimiento = tM;
}
Huaquero::~Huaquero(){}

int Huaquero::getVidas() { return this->vidas; }
void Huaquero::RestarVidas(int v) { this -> vidas -= v; }
int Huaquero::getTemMov() { return this->tiempoMovimiento; }
void Huaquero::setTemMov(int TM) { tiempoMovimiento = TM; }

std::string Huaquero::getNombre() { return "huaquero"; }

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
void Huaquero::dibujar(Graphics^ g) {
	Bitmap^ img = Recursos::guardia;
	// CAMBIAR LUEGO A :
	// Bitmap^ img = Recursos::huaquero;

	this->alto = img->Height / 4;
	this->ancho = img->Width / 4;

	Rectangle molde = Rectangle(columna * ancho, fila * alto, ancho, alto);
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

// void atacar(Bien* bien) 
