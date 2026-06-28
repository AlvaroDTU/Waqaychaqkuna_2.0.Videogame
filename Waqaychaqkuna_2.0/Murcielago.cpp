#include "pch.h"
#include "Murcielago.h"
Murcielago::Murcielago(int posX, int posY, int an, int al, int anF, int alF)
	: Aliado(posX, posY, an, al, anF, alF)
{}

Murcielago::~Murcielago() {}

std::string Murcielago::getNombre() { return "murcielago"; }
