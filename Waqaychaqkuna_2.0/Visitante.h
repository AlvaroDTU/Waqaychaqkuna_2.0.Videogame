#pragma once
#include "Entidad.h"
class Visitante : public Entidad
{
private:
	int tipo;
	int posXFinal;
public:

	Visitante(int posX, int posY, int dirX, int dirY);
	~Visitante();
	std::string getNombre() override;
	void mover(Direccion direccion, int ancho, int alto) override;
	void dibujar(Graphics^ g) override;
	bool terminoRecorrido();

};

