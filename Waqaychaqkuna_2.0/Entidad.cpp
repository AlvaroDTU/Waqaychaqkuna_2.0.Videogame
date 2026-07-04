#include "pch.h"
#include "Entidad.h"
Entidad::Entidad() {}
Entidad::Entidad(int posX, int posY, int an, int al, int anF, int alF, int dirX, int dirY,bool acti)
	: posX(posX), posY(posY), ancho(an), alto(al), anchoFrame(anF),altoFrame(alF), dirX(dirX), dirY(dirY), activo(acti)
{
	fila = 0;
	columna = 0;
	contadorTicks = 0;
}
Entidad::~Entidad() {}

int Entidad::getPosX() { return this->posX; }
int Entidad::getPosY() { return this->posY; }
int Entidad::getDirX() { return this->dirX; }
int Entidad::getDirY() { return this->dirY; }
int Entidad::getAlto() { return this->alto; }
int Entidad::getAncho() { return this->ancho; }
int Entidad::getFila() { return this->fila; }
int Entidad::getColumna() { return this->columna; }
bool Entidad::getMoviendose() { return this->moviendose; }

void Entidad::setMoviendose(bool a) { moviendose = a; }
void Entidad::setFila(int fil) { this->fila = fil; }
void Entidad::setColumna(int colum) { this->columna = colum; }

void Entidad::setPos(int x, int y) {
	this->posX = x;
	this->posY = y;
}
void Entidad::setAlto(int alt) { this->alto = alt; }
void Entidad::dibujar(Graphics^ g, float escalaX, float escalaY) {
	Bitmap^ img = getBitmap();

	Rectangle origen = Rectangle(columna * anchoFrame, fila * altoFrame, anchoFrame, altoFrame);
	Rectangle destino(posX * escalaX, posY * escalaY, ancho * escalaX, alto * escalaY);

	g->DrawImage(img, destino, origen, GraphicsUnit::Pixel);
}

void Entidad::avanzarEscena() {
	Bitmap^ img = getBitmap();
	contadorTicks++;
	int n = 0;
	if (img->Width == 240 || img->Width == 160) { n = 4; }
	if (contadorTicks == 4)
	{
		columna++;
		if (columna >= n) { columna = 0; }
		contadorTicks = 0;
	}
}

void Entidad::setAncho(int anch) { this->ancho = anch; }

Rectangle Entidad::getRectangle(int extra) {
	return Rectangle(posX - extra, posY - extra, ancho + extra * 2, alto + extra * 2);
}

bool Entidad::estaActivo() { return activo; }
void Entidad::setActivo(bool a) { activo = a; }