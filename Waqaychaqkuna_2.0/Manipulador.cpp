#include "pch.h"
#include "Manipulador.h"
Manipulador::Manipulador(int posX, int posY, int an, int al, int anF, int alF, int dirX, int dirY, int obj, int tM, bool iluminado)
	: Enemigo(posX, posY, an, al, anF, alF, dirX, dirY, obj)
{
	this->tipo = tM;
	posFinal= rand() % 240 + 210;
}
Manipulador::~Manipulador() {}

int Manipulador::getTipo() { return this->tipo; }
void Manipulador::setTipo(int TM) { tipo = TM; }

std::string Manipulador::getNombre() { return "manipulador"; }

Bitmap^ Manipulador::getBitmap() {
	return Recursos::chavon;
}

bool Manipulador::getIluminado() {
	return iluminado;
}
void Manipulador::setIluminado(bool i) {
	iluminado = i;
}

void Manipulador::mover(int anchoLienzo, int altoLienzo)
{
	moviendose = true;
	if (dirX < 0) { fila = 1; }
	else if (dirX > 0) { fila = 2; }
	else if (dirY < 0) { fila = 3; }
	else if (dirY > 0) { fila = 0; }

	posX += dirX;
	posY += dirY;

	Rectangle r = getRectangle();
	if (posX < 0) { posX = 0; }
	if (posY < 0) { posY = 0; }
	if (posX + r.Width > anchoLienzo)
		posX = anchoLienzo - r.Width;

	if (posY + r.Height > altoLienzo)
		posY = altoLienzo - r.Height;


	if (posY >= 155 && posY < posFinal) { dirX = -5;dirY = 0;}
	//1era ventana
	if(tipo==1 && posX <= 252) {
		dirY = 5;dirX = 0;
		
		if(posY>=posFinal) { dirX = 5;dirY = 0; }
	}
	//2da ventana
	if (tipo == 2 && posX <= 430) {
		dirY = 5;dirX = 0;

		if (posY >= posFinal) { dirX = 5;dirY = 0; }

	}
	
//3era ventana
	if (tipo == 3 && posX <= 630) {
		dirY = 5;dirX = 0;

		if (posY >= posFinal) { dirX = 5;dirY = 0; }

	}
//4ta ventana
	if (tipo == 4 && posX <= 830) {
		dirY = 5;dirX = 0;
		if (posY >= posFinal) { dirX = 5;dirY = 0; }
	}
	avanzarEscena();
}

void Manipulador::atacar(Bien* bien)
{
	bien->restarPuntajeValor(1);
}
