#include "pch.h"
#include "Linterna.h"

Linterna::Linterna(bool encendida){
	this->ancho = 72;
	this->alto = 114;
	this->anchoFrame = 72;
	this->altoFrame = 114;
	this->posX =0;
	this->posY = 0;
	this->encendida = encendida;
	this->fila = 0;
	this->columna = 0;
}

Linterna::~Linterna(){
	encendida = false;
}

int Linterna::getPosX(){ return posX;}
int Linterna::getPosY(){ return posY; }
int Linterna::getDirX(){ return dirX; }
int Linterna::getDirY(){ return dirY; }
int Linterna::getAlto(){ return alto; }
int Linterna::getAncho(){ return ancho; }
int Linterna::getColumna() { return columna; }
bool Linterna::getEncendida(){ return encendida; }


void Linterna::setColumna(int c){ columna = c;}

void Linterna::setPos(int x, int y) {
	this->posX = x;
	this->posY = y;
}
void Linterna::setEncendida(bool e){ 
	encendida = e;
}

void Linterna::dibujar(Graphics^ g){
	Bitmap^ img = getBitmap();

	Rectangle origen = Rectangle(columna * anchoFrame, fila * altoFrame, anchoFrame, altoFrame);
	Rectangle destino(posX, posY, ancho, alto);

	g->DrawImage(img, destino, origen, GraphicsUnit::Pixel);
}

Bitmap^ Linterna::getBitmap(){ return Recursos::linterna; }

Rectangle Linterna::getRectangle(int extra){ return Rectangle(posX - extra, posY - extra, ancho + extra * 2, alto + extra * 2); }