#pragma once
#include "Aliado.h"
class Murcielago : public Aliado
{
public:

	Murcielago(int posX, int posY, int dirX, int dirY, bool ayuda, int Tr);
	~Murcielago();

	std::string getNombre() override;
	void dibujar(Graphics^ g) override;

	// VER SI ESTO SE IMPREMENTARA
	//void ayudar() override
};

