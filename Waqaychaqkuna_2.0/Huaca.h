#pragma once
#include "Bien.h"
class Huaca : public Bien
{
public:
	Huaca(int px, int py, int an, int al, int pValor, std::string nom);
	~Huaca();
	void dibujar(Graphics^ g);
	Bitmap^ getBitmap();
	void describir() override;
};

