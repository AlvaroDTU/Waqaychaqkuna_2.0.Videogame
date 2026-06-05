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

void Huaquero::mover(Direccion direccion, int ancho, int alto) {
	moviendose = true;

	switch (direccion) {
	case Direccion::Arriba:
		posY -= dirY;
		this->fila = 3;
		break;
	case Direccion::Abajo:
		posY += dirY;
		this->fila = 0;

		break;
	case Direccion::Derecha:
		posX += dirX;
		this->fila = 2;

		break;
	case Direccion::Izquierda:
		posX -= dirX;
		this->fila = 1;
		break;
	}

	Rectangle r = getRectangle(0);
	if (posX < 0) { posX = 0; }
	if (posY < 0) { posY = 0; }
	if (posX + r.Width > ancho)
		posX = ancho - r.Width;

	if (posY + r.Height > alto)
		posY = alto - r.Height;

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
