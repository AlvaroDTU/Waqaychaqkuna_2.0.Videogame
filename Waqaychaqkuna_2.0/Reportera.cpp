#include "pch.h"
#include "Reportera.h"

Reportera::Reportera(int posX, int posY, int an, int al, int anF, int alF)
	: Aliado(posX, posY, an, al, anF, alF), tipoPista(0)
{}

Reportera::~Reportera() {}

int Reportera::getTipoPista() { return this->tipoPista; }
void Reportera::setTipoPista(int Tp) { this->tipoPista = Tp; }

Bitmap^ Reportera::getBitmap() {
	return Recursos::reportera;
}

std::string Reportera::getNombre() { return "reportera"; }

void Reportera::mover(int ancho, int alto)  // animacion de ayudar
{
	if (!activo) return;

	if (ayudando)
	{
		fila = 1;	
	}
	else
		fila = 0;

	avanzarEscena();
}

void Reportera::ayudar() 
{
	if (ayudando == false) 
		tipoPista = rand() % 3 + 1;
	ayudando = true;


}