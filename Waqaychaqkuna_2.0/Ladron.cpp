#include "pch.h"
#include "Ladron.h"

Ladron::Ladron(int posX, int posY, int dirX, int dirY, bool atack,int obj,int t, int tPista)
	: Enemigo (posX,posY,dirX,dirY,atack,obj)
{
	this->tipo = t;
	this->tipoPista = tPista;
}
Ladron::~Ladron(){}

std::string Ladron::getNombre() {
	for (int i = 0;i < 4;i++) {
		if (i == tipo) {
			return "ladron" + std::to_string(i+1);
		}
	}
}
void Ladron::mover(int ancho, int alto) {
	moviendose = true;
	switch (direccion) {
	case Direccion::Arriba:
		posY += dirY;
		fila = 3;
		break;
	case Direccion::Abajo:
		posY -= dirY;
		fila = 0;
		break;
	case Direccion::Derecha:
		posX += dirX;
		fila = 2;
		break;
	case Direccion::Izquierda:
		posX -= dirX;
		fila = 1;
		break;
	}
}
void Ladron::dibujar(Graphics^ g) {
	Bitmap^ img;
	// LUEGO CAMBIAR POR EL DISEÑO DE CADA UNO YAP :V
	if (tipo == 1) {
		if (tipoPista == 1) { img = Recursos::guardia; }
		else if (tipoPista == 2) {img = Recursos::guardia; }
		else if (tipoPista == 3) {img = Recursos::guardia; }
		else if (tipoPista == 4) {img = Recursos::guardia; }
	}
	else if (tipo == 2) {
		if (tipoPista == 1) { img = Recursos::guardia; }
		else if (tipoPista == 2) { img = Recursos::guardia; }
		else if (tipoPista == 3) { img = Recursos::guardia; }
		else if (tipoPista == 4) { img = Recursos::guardia; }
	}
	else if (tipo == 3) {
		if (tipoPista == 1) { img = Recursos::guardia; }
		else if (tipoPista == 2) { img = Recursos::guardia; }
		else if (tipoPista == 3) { img = Recursos::guardia; }
		else if (tipoPista == 4) { img = Recursos::guardia; }
	}
	else if (tipo == 4) {
		if (tipoPista == 1) { img = Recursos::guardia; }
		else if (tipoPista == 2) { img = Recursos::guardia; }
		else if (tipoPista == 3) { img = Recursos::guardia; }
		else if (tipoPista == 4) { img = Recursos::guardia; }
	}
	this->alto = img->Height / 4;
	this->ancho = img->Width / 4;

	Rectangle molde = Rectangle(ancho * columna, fila * alto, ancho, alto);
	if (moviendose == true) {
		columna++;
		if (columna == 4) { columna = 0; }
	}
	else
	{
		columna = 0;
	}
	moviendose = false;
}