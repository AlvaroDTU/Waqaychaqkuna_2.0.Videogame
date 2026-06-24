#include "pch.h"
#include "Aliado.h"
Aliado::Aliado(int posX, int posY, int an, int al, int anF, int alF, bool ayuda) :
	Entidad(posX, posY, an, al, anF, alF, 0, 0)
{
	this->ayudando = ayuda;
}
Aliado::~Aliado() {}

bool Aliado::getAyudando() { return this->ayudando; }
void Aliado::setAyudando(bool ayuda) { this->ayudando = ayuda; }