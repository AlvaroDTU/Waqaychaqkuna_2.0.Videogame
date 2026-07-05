#pragma once
#include "Bien.h"
class Huaca : public Bien
{
private:
	int tipo;
public:
	Huaca(int px, int py, int an, int al, int pValor, std::string nom, int ti);
	~Huaca();
	Bitmap^ getBitmap() override;
	Bitmap^ getBitmapDescripciones() override;
};

