#pragma once
#include "Bien.h"

class Artilugio : public Bien
{
public:
	Artilugio(int px, int py, int an, int al, int pValor, std::string nom);
	~Artilugio();
	Bitmap^ getBitmap() override { return nullptr; }

	void describir() override;
};

