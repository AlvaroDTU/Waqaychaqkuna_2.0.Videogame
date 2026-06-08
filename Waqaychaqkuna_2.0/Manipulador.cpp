#include "pch.h"
#include "Manipulador.h"
Manipulador::Manipulador(int x, int y, int dx, int dy,
	bool at, int obj, int vid, int tM) : Enemigo(posX, posY,
		 dirX, dirY, at, obj)
{
	this->tiempoMovimiento = tM;

}
Manipulador::~Manipulador(){}

int Manipulador::getTemMov() { return this->tiempoMovimiento; }
void Manipulador::setTemMov(int TM) { tiempoMovimiento = TM; }

std::string Manipulador::getNombre() { return "manipulador"; }

void Manipulador::mover(int anchoLienzo, int altoLienzo)
{
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
void Manipulador::dibujar(Graphics^ g) {
	Bitmap^ img = Recursos::guardia;
	// CAMBIAR LUEGO A :
	// Bitmap^ img = Recursos::manipulador;

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

// virtual void atacar(Bien* bien) override
