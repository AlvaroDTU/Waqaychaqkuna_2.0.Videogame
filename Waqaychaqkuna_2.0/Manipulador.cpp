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

Bitmap^ Manipulador::getBitmap() {
	// Cambiar a manipulador
	return Recursos::guardia;
}


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
	Entidad::dibujar(g); 

}

// virtual void atacar(Bien* bien) override
