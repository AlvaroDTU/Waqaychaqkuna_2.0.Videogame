#pragma once
#include "Aliado.h"

class Reportera : public Aliado
{
private:
	int tipoPista;
public:
	Reportera(int posX, int posY, int an, int al, int anF, int alF);
	~Reportera();

	int getTipoPista();
	void setTipoPista(int Tp);

	std::string getNombre() override;
	void mover(int ancho, int alto) override;
	Bitmap^ getBitmap() override;

	
	void ayudar() override;

};

