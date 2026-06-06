#include "pch.h"
#include "Reportera.h"
Reportera::Reportera(int posX, int posY, int dirX, int dirY, bool ayuda, 
	int TipPis) : Aliado (posX,posY,dirX,dirY,ayuda)
{
	this->tipoPista = TipPis;
}
Reportera::~Reportera(){}

int Reportera::getTipoPista() { return this->tipoPista; }
void Reportera::setTipoPista(int Tp) { this->tipoPista = Tp; }

std::string Reportera::getNombre() { return "reportera"; }
void Reportera::dibujar(Graphics^ g) {
	// CAMBIAR LUEGO A :
	// Bitmap^ img = Recursos::reportera;

	Bitmap^ img = Recursos::guardia;

	ancho = img->Width / 2;
	alto = img->Height / 2;
	
	Rectangle molde = Rectangle(columna * ancho, fila * ancho, ancho, alto);

	if (moviendose == true) {
		columna++;
		fila++;
		if (columna == 2) { columna = 0; }
		if (fila == 2) { fila = 0; }
	}
	else
	{
		columna = 0;
		fila = 0;
	}
	g->DrawImage(img, posX, posY, molde, GraphicsUnit::Pixel);

	moviendose = false;
}

// 	void ayudar() override //