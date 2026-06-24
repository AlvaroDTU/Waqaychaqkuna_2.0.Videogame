#include "pch.h"
#include "Guardia.h"
Guardia::Guardia(int posX, int posY, int dirX, int dirY,
	int tpAccion, bool ac) : Entidad(posX, posY, dirX, dirY)
{
	this->fila = 0;
	this->columna = 0;
	this->accion = ac;
	this->tipoAccion = tpAccion;
}
Guardia::~Guardia() {}
bool Guardia::getAccion() { return this->accion; }
int Guardia::getTipoAccion() { return this->tipoAccion; }
void Guardia::setVelocidad(int dx, int dy) { dirX = dx; dirY = dy; }
int Guardia::getDirX() { return dirX; }
int Guardia::getDirY() { return dirY; }
void Guardia::setAccion(bool acc) { this->accion = acc; }
void Guardia::setTipoAccion(int tAcc) { this->tipoAccion = tAcc; }
void Guardia::setMoviendose(bool mov) { moviendose = mov; }
Bitmap^ Guardia::getBitmap() { return Recursos::guardia; }

std::string Guardia::getNombre() { return "guardia"; }
void Guardia::dibujar(Graphics^ g) {
	Entidad::dibujar(g);
}

void Guardia::mover(int idx, int ancho, int alto)
{
	moviendose = true;
	if (dirY > 0) fila = 0;
	else if (dirY < 0) fila = 3;
	else if (dirX < 0) fila = 1;
	else if (dirX > 0) fila = 2;

	posX += dirX;
	posY += dirY;

	if (dirX != 0 || dirY != 0) avanzarEscena();
	else columna = 0;
}

void Guardia::mover(int ancho, int alto) {}