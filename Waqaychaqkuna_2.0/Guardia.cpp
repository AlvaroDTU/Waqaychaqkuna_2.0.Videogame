#include "pch.h"
#include "Guardia.h"
Guardia::Guardia(std::string nombre, int posX, int posY, int ancho, int alto, 
	int dirX, int dirY, int tpAccion, bool Accio) : Entidad(nombre,posX,posY,
		alto,ancho,dirX,dirY)
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

std::string Guardia::getNombre() { return this->nombre; }
void Guardia::mover(Direccion direccion) {
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
		this->fila = 3;
		break;          }

}
void Guardia::dibujar(Graphics^ g, Bitmap^ img) {

	this->alto = img->Height/4;
	this->ancho = img->Width/4;

	Rectangle molde = Rectangle(columna * ancho, fila * alto, ancho,alto);
	g->DrawImage(img, posX, posY, molde, GraphicsUnit::Pixel);
	columna++;
	if (columna == 4) { columna = 0; }

}
