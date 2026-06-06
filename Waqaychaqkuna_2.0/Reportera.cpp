#include "pch.h"
#include "Reportera.h"
Reportera::Reportera(int posX, int posY, int dirX, int dirY, bool ayuda, 
	int TipPis) : Aliado (posX,posY,dirX,dirY,ayuda)
{
	this->tipoPista = TipPis;
}
Reportera::~Reportera(){}

int Reportera::getTipoPista() { return this->tipoPista; }
void Reportera::setTipoPista(int Tp) { this->tipoPista = Tp; }

std::string Reportera::getNombre() { return "reportera"; }
void Reportera::mover(Direccion direccion, int ancho, int alto) {
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
void Reportera::dibujar(Graphics^ g) {
	// CAMBIAR LUEGO A :
	// Bitmap^ img = Recursos::reportera;

	Bitmap^ img = Recursos::guardia;

	ancho = img->Width / 2;
	alto = img->Height / 2;
	
	Rectangle model = Rectangle(columna * ancho, fila * ancho, ancho, alto);

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

// 	void ayudar() override