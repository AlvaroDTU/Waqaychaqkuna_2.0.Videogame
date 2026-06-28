#pragma once
#include "Enemigo.h"
#include "Bien.h"
#include "Objeto.h"
#include <vector>
using std::vector;

class Ladron : public Enemigo
{
private:
	int tipo;
	int tipoPista;
	int tempMovimiento;
	int tempAtaque;
public:
	Ladron(int posX, int posY, int an, int al, int anF, int alF, int dirX, int dirY, int obj, int t, int tPista);
	~Ladron();

	std::string getNombre() override;
	void mover(int ancho, int alto) override {}
	void mover(vector<Objeto*> objetos, vector<Bien*> bienes);
	Bitmap^ getBitmap() override;
	void atacar(Bien* bien) override;
};

