#include "pch.h"
#include "Bien.h"

Bien::Bien(int px, int py, int an, int al, int pValor, std::string nom) :
	posX(px), posY(py), ancho(an), alto(al), puntajeValor(pValor), nombre(nom)
{}
Bien::~Bien() {}

int Bien::getPosX() { return posX; }
int Bien::getPosY() { return posY; }
int Bien::getPuntajeValor() { return puntajeValor; }
std::string Bien::getNombre() { return nombre; }

void Bien::restarPuntajeValor(int pv) { puntajeValor -= pv; }

Rectangle Bien::getRectangle(int extra) { return Rectangle(posX - extra, posY - extra, ancho + extra * 2, alto + extra * 2); }