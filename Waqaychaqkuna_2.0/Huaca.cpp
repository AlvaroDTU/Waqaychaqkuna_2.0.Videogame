#include "pch.h"
#include "Huaca.h"
#include "Recursos.h"
Huaca::Huaca(int px, int py, int an, int al, int pValor, std::string nom, int ti) 
	: Bien(px, py, an, al, pValor, nom, ti)
{}

Huaca::~Huaca() {}

Bitmap^ Huaca::getBitmapDescripciones() {
	if (tipo == 1) return Recursos::huaca1Desc;
	else if (tipo == 2) return Recursos::huaca2Desc;
	else if (tipo == 3) return Recursos::huaca3Desc;
	else if (tipo == 4) return Recursos::huaca4Desc;
}

Bitmap^ Huaca::getBitmap() {
	if (tipo == 1) return Recursos::huaca1;
	else if (tipo == 2) return Recursos::huaca2;
	else if (tipo == 3) return Recursos::huaca3;
	else if (tipo == 4) return Recursos::huaca4;
}

void Huaca::dibujar(Graphics^ g, float escalaX, float escalaY) {
	Bitmap^ img = getBitmap();
	Rectangle origen(0, 0, ancho, alto);
	Rectangle destino(
		(int)(posX * escalaX),
		(int)(posY * escalaY),
		(int)(ancho * escalaX),
		(int)(alto * escalaY)
	);
	g->DrawImage(img, destino, origen, GraphicsUnit::Pixel);
}

void Huaca::dibujarDescripcion(Graphics^ g, float escalaX, float escalaY)
{
	Bitmap^ img = getBitmapDescripciones();
	Rectangle origen(0, 0, 300, 358);
	Rectangle destino(
		(int)(0 * escalaX),
		(int)(0 * escalaY),
		(int)(300 * escalaX),
		(int)(358 * escalaY)
	);
	g->DrawImage(img, destino, origen, GraphicsUnit::Pixel);
}