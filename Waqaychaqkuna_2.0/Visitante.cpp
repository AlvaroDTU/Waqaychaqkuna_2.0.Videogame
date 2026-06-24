#include "pch.h"
#include "Visitante.h"

Visitante::Visitante(int posX, int posY, int an, int al, int anF, int alF, int dirX, int dirY)
	: Entidad(posX, posY, an, al, anF, alF, dirX, dirY)
{
	tipo = rand() % 4 + 1;
	if (dirX > 0) { posXFinal = 1299; fila = 2; }
	if (dirX < 0) { posXFinal = 0; fila = 1; }
}
Visitante::~Visitante() {}

std::string Visitante::getNombre() {
	for (int i = 0; i < 4; i++) {
		if (i + 1 == tipo) {
			return "visitante" + std::to_string(i + 1);
		}
	}
}

void Visitante::mover(int ancho, int alto)
{
	posX += dirX;

	if (dirX > 0) fila = 2;
	else if (dirX < 0) fila = 1;
	else fila = 0;

	avanzarEscena();
}

// cambiar de acuerdo a los nuevos tamaños de la ventana
bool Visitante::terminoRecorrido() {
	if (dirX > 0)
	{
		return posX >= posXFinal;
	}
	else
		return posX + ancho <= posXFinal;
}

Bitmap^ Visitante::getBitmap()
{
	Bitmap^ img = nullptr;
	if (tipo == 1) { img = Recursos::visitante1; }
	else if (tipo == 2) { img = Recursos::visitante2; }
	else if (tipo == 3) { img = Recursos::visitante3; }
	else if (tipo == 4) { img = Recursos::visitante4; }
	return img;
}