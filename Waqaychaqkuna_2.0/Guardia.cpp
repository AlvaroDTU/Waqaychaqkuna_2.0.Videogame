#include "pch.h"
#include "Guardia.h"
Guardia::Guardia( int posX, int posY, int dirX, int dirY,
	int tpAccion, bool Accio) : Entidad(posX,posY,dirX,dirY)
{
	this->fila = 0;
	this->columna = 0;
	this->accion = Accio;
	this->tipoAccion = tpAccion;
}
Guardia::~Guardia(){}
bool Guardia::getAccion() { return this->accion; }
int Guardia::getTipoAccion() { return this->tipoAccion; }
void Guardia::setVelocidad(int dx, int dy) { dirX = dx; dirY = dy; }
int Guardia::getDirX() { return dirX; }
int Guardia::getDirY() { return dirY; }
void Guardia::setAccion(bool acc) { this->accion = acc; }
void Guardia::setTipoAccion(int tAcc) { this->tipoAccion = tAcc; }
Bitmap^ Guardia::getBitmap() {
	return Recursos::guardia;
}

std::string Guardia::getNombre() { return "guardia"; }
void Guardia::dibujar(Graphics^ g) {
	Entidad::dibujar(g);
}

// void ayudar()

void Guardia::mover(int idx, int ancho, int alto) 
{
	posX += dirX;
	posY += dirY;
}
void Guardia::mover(int ancho, int alto) {}