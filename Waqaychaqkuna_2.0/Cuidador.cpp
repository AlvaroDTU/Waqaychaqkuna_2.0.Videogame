#include "pch.h"
#include "Cuidador.h"
Cuidador::Cuidador(int posX, int posY, int dirX, int dirY, bool ayuda, int dura)
	: Aliado(posX,posY,dirX,dirY,ayuda)
{
	this->duracion = dura;
}
Cuidador::~Cuidador(){}

int Cuidador::getDuracion() { return this->duracion; }
void Cuidador::RestarDuracion(int d) { this->duracion = d; }

Bitmap^ Cuidador::getBitmap() {
	return Recursos::cuidador;
}
std::string Cuidador::getNombre() { return "cuidador"; }

void Cuidador::dibujar(Graphics^ g) {
	Entidad::dibujar(g);

}