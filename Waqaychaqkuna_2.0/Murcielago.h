#pragma once
#include "Aliado.h"
class Murcielago : public Aliado
{
public:
	Murcielago(int posX, int posY, int an, int al, int anF, int alF, bool ayuda);
	~Murcielago();

	std::string getNombre() override;
	void dibujar(Graphics^ g) override;

	// VER SI ESTO SE IMPREMENTARA
	//void ayudar() override
};

