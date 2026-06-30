#pragma once
#include "Enemigo.h"
class Manipulador : public Enemigo
{
private:
	int tiempoMovimiento;
	int tipo;
public:
	Manipulador(int posX, int posY, int an, int al, int anF, int alF, int dirX, int dirY, int obj, int t);
	~Manipulador();

	int getTemMov();
	void setTemMov(int TM);

	std::string getNombre() override;

	void mover(int ancho, int alto) override;
	Bitmap^ getBitmap() override;
	void atacar(Bien* bien) override;
};

