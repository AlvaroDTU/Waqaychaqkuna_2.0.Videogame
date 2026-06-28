#include "pch.h"
#include "Guardia.h"
Guardia::Guardia(int posX, int posY, int an, int al, int anF, int alF)
	: Entidad(posX, posY, an, al, anF, alF, 0, 0)
{
	accion = false;
	tipoAccion = 0;
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

void Guardia::mover(int ancho, int alto, vector<Objeto*> objetos, vector<Bien*> bienes)
{
	bool colision = false;
	Rectangle hbGuardia = getRectangle();
	hbGuardia.X += dirX;
	hbGuardia.Y += dirY;
	for (int i = 0; i < (int)objetos.size(); i++)
	{
		if (hbGuardia.IntersectsWith(objetos[i]->getRectangle()))
			colision = true;
	}
	for (int i = 0; i < (int)bienes.size(); i++)
	{
		if (hbGuardia.IntersectsWith(bienes[i]->getRectangle()) && bienes[i]->estaActivo())
			colision = true;
	}
	if (dirY > 0) fila = 0;
	else if (dirY < 0) fila = 3;
	else if (dirX < 0) fila = 1;
	else if (dirX > 0) fila = 2;

	if (!colision) {
		posX += dirX;
		posY += dirY;
	}

	if (dirX != 0 || dirY != 0) avanzarEscena();
	else columna = 0;
}

void Guardia::mover(int ancho, int alto) {}