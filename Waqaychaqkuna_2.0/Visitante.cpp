#include "pch.h"
#include "Visitante.h"

Visitante::Visitante(int posX, int posY, int dirX, int dirY)
	: Entidad(posX, posY, dirX, dirY)
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
	moviendose = true;
	posX += dirX;
	if (posX < 0) posX == 0;
	if (posX + ancho >= 1299) posX == 1299-ancho;
}
void Visitante::dibujar(Graphics^ g) {
	Bitmap^ img = getBitmap();
	this->alto = img->Height / 4;
	this->ancho = img->Width / 4;

	Rectangle molde = Rectangle(columna * ancho, fila * alto, ancho, alto);
	avanzarEscena();
	g->DrawImage(img, posX, posY, molde, GraphicsUnit::Pixel);
}
// cambiar d e acuerdo a los nuevos tamaños de la ventada
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
	Bitmap^ img;
	if (tipo == 1) { img = Recursos::visitante1; }
	else if (tipo == 2) { img = Recursos::visitante2; }
	else if (tipo == 3) { img = Recursos::visitante3; }
	else if (tipo == 4) { img = Recursos::visitante4; }
	return img;
}