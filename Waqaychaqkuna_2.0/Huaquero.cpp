#include "pch.h"
#include "Huaquero.h"
Huaquero::Huaquero(int posX, int posY, int an, int al, int anF, int alF, int dirX, int dirY, int obj,int tp)
	: Enemigo(posX, posY, an, al, anF, alF, dirX, dirY, obj)
{
	this->vidas = 3;
	this->tiempoMovimiento = 40;
	tipo = tp;
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
	else if (dirY < 0) { fila = 3; }
	else if (dirY > 0) { fila = 0; }

	posX += dirX;
	posY += dirY;

	Rectangle r = getRectangle(0);
	if (posX < 0) { posX = 0; }
	if (posY < 0) { posY = 0; }
	if (posX + r.Width > anchoLienzo)
		posX = anchoLienzo - r.Width;

	if (posY + r.Height > altoLienzo)
		posY = altoLienzo - r.Height;


	/*Aparecen a la izquierda*/
		if (tipo == 1) {
			if (posX >= 370) { dirX = 0;dirY = -5;}
		}
	if (tipo == 2) {
		if (posX >= 370) { dirX = 0;dirY = 5;}
	}
	if (tipo == 3) {
		if (posX >= 924) { dirX = 0;dirY = -5;}
	}
	if (tipo == 4) {
		if (posX >= 924) { dirX = 0;dirY = 5;}
	}

	//Aparición a la derecha
		if (tipo == 5) {
			if (posX <= 924) { dirX = 0;dirY = 5;}
		}
	if (tipo == 6) {
		if (posX <= 924) { dirX = 0;dirY = -5;}
	}
	if (tipo == 7) {
		if (posX <= 370) { dirX = 0;dirY = -5;}
	}
	if (tipo == 8) {
		if (posX <= 370) { dirX = 0;dirY = 5;}
	}
//Arriba:

	if (tipo == 9) {
		if (posY >= 160) { dirX = -5;dirY = 0;}
	}
	if (tipo == 10) {
		if (posY >= 160) { dirX = 5;dirY = 0;}
	}
	if (tipo == 11) {
		if (posY >= 564) { dirX = 5;dirY = 0;}
	}
	if (tipo == 12) {
		if (posY >= 564) { dirX = -5;dirY = 0;}
	}
//
//Abajo:
	if (tipo == 13) {
		if (posY <= 160) { dirX = -5;dirY = 0;}
	}
	if (tipo == 14) {
		if (posY <= 160) { dirX = 5;dirY = 0;}
	}
	if (tipo == 15) {
		if (posY <= 564) { dirX = -5;dirY = 0;}
	}
	if (tipo == 16) {
		if (posY <= 564) { dirX = 5;dirY = 0;}
	}
	if(atacando==false) avanzarEscena();
}
 void Huaquero::atacar(Bien* bien) {}
