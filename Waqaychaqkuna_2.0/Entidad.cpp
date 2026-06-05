#include "pch.h"
#include "Entidad.h"
Entidad::Entidad(){}
Entidad::Entidad(std::string nombre, int posX, int posY, int alto, int ancho, int dirX, int dirY){}
Entidad::~Entidad(){}




int Entidad::getPosX() { return this->posX; }
int Entidad::getPosY(){	return this->posY; }
int Entidad::getDirX(){	return this->dirX; }
int Entidad::getDirY(){ return this->dirY; }
int Entidad::getAlto(){	return this->alto; }
int Entidad::getAncho(){ return this->ancho; }


void Entidad::setPos(int x, int y){
	this->posX = x;
	this->posY = y;
}
void Entidad::setAlto(int alt) { this->alto = alt; }
void Entidad::setAncho(int anch) { this->ancho = anch; }
