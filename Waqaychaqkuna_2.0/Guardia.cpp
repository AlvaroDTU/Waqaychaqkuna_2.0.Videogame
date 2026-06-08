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
void Guardia::setAccion(bool acc) { this->accion = acc; }
void Guardia::setTipoAccion(int tAcc) { this->tipoAccion = tAcc; }
Bitmap^ Guardia::getBitmap() {
	return Recursos::guardia;
}

std::string Guardia::getNombre() { return "guardia"; }
void Guardia::mover(Direccion direccion, int anchoLienzo, int altoLienzo) {
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
		break;          }

	Rectangle r = getRectangle(0);
	if (posX < 0) { posX = 0; }
	if (posY < 0) { posY = 0; }
	if (posX + r.Width > anchoLienzo)
		posX = anchoLienzo - r.Width;

	if (posY + r.Height > altoLienzo)
		posY = altoLienzo - r.Height;
}
void Guardia::dibujar(Graphics^ g) {
	Entidad::dibujar(g);
}

// void ayudar()

void Guardia::mover(int ancho, int alto) {}