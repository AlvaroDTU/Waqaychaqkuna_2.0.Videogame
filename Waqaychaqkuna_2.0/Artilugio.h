#pragma once
#include "Bien.h"

class Artilugio : public Bien
{
public:
	Artilugio(int px, int py, int an, int al, int pValor, std::string nom, int ti);
	~Artilugio();
	Bitmap^ getBitmap() override;
	Bitmap^ getBitmapDescripciones() override;
	void dibujar(Graphics^ g, float escalaX, float escalaY) override;
	void dibujarDescripcion(Graphics^ g, float escalaX, float escalaY) override;
};

