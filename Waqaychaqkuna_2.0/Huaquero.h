#pragma once
#include "Enemigo.h"
class Huaquero : public Enemigo
{
private:
	int vidas;
	int tiempoMovimiento;

public:
	Huaquero(int posX, int posY, int an, int al, int anF, int alF, int dirX, int dirY, int obj, int vid, int tM);
	~Huaquero();

	int getVidas();
	void RestarVidas(int v);
	int getTemMov();
	void setTemMov(int TM);

	std::string getNombre() override;

	void mover(int ancho, int alto) override;
	Bitmap^ getBitmap() override;

	// virtual void atacar(Bien* bien) override


};

