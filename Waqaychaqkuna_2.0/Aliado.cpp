#include "pch.h"
#include "Aliado.h"
Aliado::Aliado(){}
Aliado::Aliado(int posX, int posY, int dirX, int dirY, bool ayuda) :
	Entidad (posX,posY,dirX,dirY)
{
	this->ayudando = ayuda;
}
Aliado::~Aliado(){}

bool Aliado::getAyudando() { return this->ayudando; }
void Aliado::setAyudando(bool ayuda) { this->ayudando = ayuda; }