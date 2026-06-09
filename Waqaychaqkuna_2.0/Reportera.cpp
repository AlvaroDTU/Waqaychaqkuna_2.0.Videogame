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

Bitmap^ Reportera::getBitmap() {
	return Recursos::reportera;
}

std::string Reportera::getNombre() { return "reportera"; }
void Reportera::dibujar(Graphics^ g) {
	Entidad::dibujar(g);
}

// 	void ayudar() override //