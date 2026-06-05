#include "pch.h"
#include "Guardia.h"
Guardia::Guardia(std::string nombre, int posX, int posY, int alto, int ancho, 
	int dirX, int dirY, int tpAccion, bool Accio) : Entidad(nombre,posX,posY,
		alto,ancho,dirX,dirY)
{
	this->accion = Accio;
	this->tipoAccion = tpAccion;
}
Guardia::~Guardia(){}
bool Guardia::getAccion(){}
int Guardia::getTipoAccion(){}
void Guardia::setAccion(bool acc){}
void Guardia::setTipoAccion(int tAcc){}

std::string Guardia::getNombre(){}
void Guardia::mover(Direccion direccion) {
	switch (direccion) {
	case Direccion::Arriba:
		posY -= dirY;
		break;
	case Direccion::Abajo:
		posY += dirY;
		break;
	case Direccion::Derecha:
		posX += dirX;
		break;
	case Direccion::Izquierda:
		posX -= dirX;
		break;          }

}
void Guardia::dibujar(Graphics^ g, Bitmap^ img) {

	this->alto = img->Height/4;
	this->ancho = img->Width/4;

}
