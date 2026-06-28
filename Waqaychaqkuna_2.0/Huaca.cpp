#include "pch.h"
#include "Huaca.h"
#include "Recursos.h"
Huaca::Huaca(int px, int py, int an, int al, int pValor, std::string nom) : Bien(px,py,an,al,pValor,nom)
{}

Huaca::~Huaca() {}

void Huaca::describir() {}

void Huaca::dibujar(Graphics^ g) {
	Bitmap^ img = getBitmap();
	g->DrawImage(img, posX, posY, getRectangle(), GraphicsUnit::Pixel);
}
Bitmap^ Huaca::getBitmap() {
	return Recursos::huaca1;
}