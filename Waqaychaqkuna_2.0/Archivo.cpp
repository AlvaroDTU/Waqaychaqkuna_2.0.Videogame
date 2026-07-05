#include "pch.h"
#include "Archivo.h"
#include "Recursos.h"

Archivo::Archivo(int px, int py, int an, int al, int pValor, std::string nom, bool nc, int ti) : 
	Bien(px, py, an, al, pValor, nom, ti) 
{}
Archivo::~Archivo() {}

std::string Archivo::getNombre() { return nombre; }

Bitmap^ Archivo::getBitmap() { return nullptr; }
Bitmap^ Archivo::getBitmapDescripciones() { return nullptr; }

void Archivo::dibujar(Graphics^ g, float escalaX, float escalaY) 
{}
void Archivo::dibujarDescripcion(Graphics^ g, float escalaX, float escalaY) 
{}
