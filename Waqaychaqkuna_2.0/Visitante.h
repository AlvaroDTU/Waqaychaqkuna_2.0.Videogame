#pragma once
#include "Entidad.h"
class Visitante : public Entidad
{
private:
	int tipo;
	int posXFinal;
public:

	Visitante(int posX, int posY, int an, int al, int anF, int alF, int dirX, int dirY);
	~Visitante();
	std::string getNombre() override;
	void mover(int ancho, int alto) override;
	bool terminoRecorrido();
	Bitmap^ getBitmap() override;

};

