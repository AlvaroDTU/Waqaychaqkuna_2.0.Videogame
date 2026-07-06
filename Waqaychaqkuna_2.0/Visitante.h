#pragma once
#include "Entidad.h"
#include "Bien.h"
#include "Objeto.h"
#include <vector>
using std::vector;


class Visitante : public Entidad
{
private:
	int tipo;
	int tempMovimiento;
public:	
	Visitante(int posX, int posY, int an, int al, int anF, int alF, int dirX, int dirY);
	~Visitante();
	void mover(vector<Objeto*> objetos, vector<Bien*> bienes);

	std::string getNombre() override;
	void mover(int ancho, int alto) override {}
	Bitmap^ getBitmap() override;

};

