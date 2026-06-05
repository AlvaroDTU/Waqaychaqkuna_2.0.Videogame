#include "pch.h"
#include "Enemigo.h"

Enemigo::Enemigo(int posX, int posY,
	int dirX, int dirY, bool at, int obj)
	: Entidad(posX, posY,dirX, dirY)
{

	this->atacando = at;
	this->objetivo = obj;
}
Enemigo::~Enemigo(){}

bool Enemigo::getAtacando() { return this->atacando; }
int Enemigo::getObjetivo() { return this->objetivo; }
void Enemigo::setAtacando(bool at) { this->atacando = at; }
void Enemigo::setObjetivo(int obj) { this->objetivo = obj; }