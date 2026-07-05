#include "pch.h"
#include "Huaca.h"
#include "Recursos.h"
Huaca::Huaca(int px, int py, int an, int al, int pValor, std::string nom, int ti) : Bien(px, py, an, al, pValor, nom)
{
	tipo = ti;
}

Huaca::~Huaca() {}

void Huaca::describir() {}

Bitmap^ Huaca::getBitmap() {
	if(tipo==1) return Recursos::huaca1;
	else if(tipo==2) return Recursos::huaca2;
	else if(tipo==3) return Recursos::huaca3;
	else if(tipo==4) return Recursos::huaca4;
}