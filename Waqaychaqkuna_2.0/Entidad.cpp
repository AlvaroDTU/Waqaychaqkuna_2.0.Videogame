#include "pch.h"
#include "Entidad.h"
Entidad::Entidad(){}
Entidad::Entidad( int posX, int posY, int dirX, int dirY)
{

	this->posX = posX;
	this->posY = posY;
	this->dirX = dirX;
	this->dirY = dirY;
}
Entidad::~Entidad(){}




int Entidad::getPosX() { return this->posX; }
int Entidad::getPosY(){	return this->posY; }
int Entidad::getDirX(){	return this->dirX; }
int Entidad::getDirY(){ return this->dirY; }
int Entidad::getAlto(){	return this->alto; }
int Entidad::getAncho(){ return this->ancho; }
int Entidad::getFila() { return this->fila; }
int Entidad::getColumna() { return this->columna; }
bool Entidad::getMoviendose() { return this->moviendose; }

void Entidad::setMoviendose(bool a) { moviendose = a; }
void Entidad::setFila(int fil) { this->fila = fil; }
void Entidad::setColumna(int colum) { this->columna = colum; }

void Entidad::setPos(int x, int y){
	this->posX = x;
	this->posY = y;
}
void Entidad::setAlto(int alt) { this->alto = alt; }
void Entidad::setAncho(int anch) { this->ancho = anch; }

System::Drawing::Rectangle Entidad::getRectangle(int extra) {
	return System::Drawing::Rectangle(posX - extra, posY - extra, ancho  + extra * 2, alto+extra * 2);
}
