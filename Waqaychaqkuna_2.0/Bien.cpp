#include "pch.h"
#include "Bien.h"

Bien::Bien(int px, int py, int an, int al, int pValor, std::string nom, bool act) :
	posX(px), posY(py), ancho(an), alto(al), puntajeValor(pValor), nombre(nom),activo(act)
{}

Bien::~Bien() {}

int Bien::getPosX() { return posX; }
int Bien::getPosY() { return posY; }
int Bien::getPuntajeValor() { return puntajeValor; }
std::string Bien::getNombre() { return nombre; }

void Bien::restarPuntajeValor(int pv) 
{ 
	puntajeValor -= pv; 
	if (puntajeValor <= 0)
		puntajeValor = 0;
}

bool Bien::estaActivo() { return activo; }
void Bien::setActivo(bool act) { activo = act; }

Rectangle Bien::getRectangle(int extra) { return Rectangle(posX - extra, posY - extra, ancho + extra * 2, alto + extra * 2); }