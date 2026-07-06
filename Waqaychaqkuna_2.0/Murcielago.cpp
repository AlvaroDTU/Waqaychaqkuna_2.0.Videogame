#include "pch.h"
#include "Murcielago.h"
Murcielago::Murcielago(int posX, int posY, int an, int al, int anF, int alF)
	: Aliado(posX, posY, an, al, anF, alF)
{}

Murcielago::~Murcielago() {}

std::string Murcielago::getNombre() { return "murcielago"; }

Bitmap^ Murcielago::getBitmap() {
	return Recursos::murcielago;
}
void Murcielago::mover(int anchoLienzo, int altoLienzo) {
	if (dirX < 0) { fila = 0; }

	posX += dirX;

	Rectangle r = getRectangle(0);
	if (posX < 0) { posX = 0; }
	if (posY < 0) { posY = 0; }
	if (posX + r.Width > anchoLienzo)
		posX = anchoLienzo - r.Width;

	if (posY + r.Height > altoLienzo)
		posY = altoLienzo - r.Height;

	if (posX <= 131) {
		posX = 131;
		dirX = 5;
		
	}
	else if (posX >= 1140) {
		posX = 1140;
		dirX *= -1;
	}
	if (columna < 2) columna = 0;
	avanzarEscena();

}
void Murcielago::ayudar() {
	//no se q poner aun aqui lol
}
