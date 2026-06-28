#include "pch.h"
#include "Aliado.h"
Aliado::Aliado(int posX, int posY, int an, int al, int anF, int alF, bool act) :
	Entidad(posX, posY, an, al, anF, alF, 0, 0), ayudando(false), activo(act)
{}

Aliado::~Aliado() {}

bool Aliado::estaAyudando() { return ayudando; }
void Aliado::setAyudando(bool ayuda) { ayudando = ayuda; }

bool Aliado::estaActivo() { return activo; }
void Aliado::setActivo(bool act) { activo = act; }