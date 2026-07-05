#include "pch.h"
#include "Archivo.h"
#include "Recursos.h"

Archivo::Archivo(int px, int py, int an, int al, int pValor, std::string nom, bool nc, int ti) : 
	Bien(px, py, an, al, pValor, nom, ti) 
{}
Archivo::~Archivo() {}

std::string Archivo::getNombre() { return nombre; }

Bitmap^ Archivo::getBitmap() { return nullptr; }
Bitmap^ Archivo::getBitmapDescripciones() {
	if (tipo == 1) return Recursos::huaca1Desc;
	else if (tipo == 2) return Recursos::huaca2Desc;
	else if (tipo == 3) return Recursos::huaca3Desc;
	else if (tipo == 4) return Recursos::huaca4Desc;
}

void Archivo::dibujar(Graphics^ g, float escalaX, float escalaY) {
	
}
void Archivo::dibujarDescripcion(Graphics^ g, float escalaX, float escalaY) {
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
