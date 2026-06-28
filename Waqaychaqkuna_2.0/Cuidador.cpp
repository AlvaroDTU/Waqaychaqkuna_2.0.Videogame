#include "pch.h"
#include "Cuidador.h"
Cuidador::Cuidador(int posX, int posY, int an, int al, int anF, int alF)
	: Aliado(posX, posY, an, al, anF, alF), duracion(3)
{
}
Cuidador::~Cuidador() {}

int Cuidador::getDuracion() { return this->duracion; }
void Cuidador::RestarDuracion(int d) { this->duracion = d; }
void Cuidador::sinMover() {
	contadorAnimacion--;
	if (contadorAnimacion == 0) {
		if (ayudando == false) {
			fila++;
			if (fila == 4) {
				fila = 0;
			}
		}
		contadorAnimacion = 40;
	}
}
Bitmap^ Cuidador::getBitmap() {
	return Recursos::cuidador;
}
std::string Cuidador::getNombre() { return "cuidador"; }