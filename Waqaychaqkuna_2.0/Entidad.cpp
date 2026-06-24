#include "pch.h"
#include "Entidad.h"
Entidad::Entidad(){}
Entidad::Entidad( int posX, int posY, int dirX, int dirY)
{
	this->alto = 80;
	this->ancho = 60;
	this->posX = posX;
	this->posY = posY;
	this->dirX = dirX;
	this->dirY = dirY;
	fila = 0;
	columna = 0;
	contadorTicks = 0;
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
void Entidad::dibujar(Graphics^ g) {
	Bitmap^ img = getBitmap();

	Rectangle origen = Rectangle(columna * ancho, fila * alto, ancho, alto);
	Rectangle destino(posX, posY, (ancho-20), (alto-15));

	g->DrawImage(img, destino, origen, GraphicsUnit::Pixel);
	moviendose = false;
}

void Entidad::avanzarEscena() {
	Bitmap^ img = getBitmap();
	contadorTicks++;
	int n = 0;
	if (img->Width == 240 || img->Width == 160) { n = 4; }
	if (contadorTicks == 5)
	{
		columna++;
		if (columna >= n) { columna = 0; }
		contadorTicks = 0;
	}
}

void Entidad::setAncho(int anch) { this->ancho = anch; }

Rectangle Entidad::getRectangle(int extra) {
	return Rectangle(posX - extra, posY - extra, ancho  + extra * 2, alto+extra * 2);
}

bool Entidad::estaActivo() { return activo; }
void Entidad::setActivo(bool a) { activo = a; }