#pragma once
#include "Enemigo.h"
class Huaquero : public Enemigo
{
private:
	int vidas;
	int tiempoMovimiento;

public:
	Huaquero(int x, int y, int dx, int dy, bool at, int obj, int vid, int tM);
	~Huaquero();

	int getVidas();
	void RestarVidas(int v);
	int getTemMov();
	void setTemMov(int TM);

	std::string getNombre() override;

	void mover(int ancho, int alto) override;
	void dibujar(Graphics^ g) override;

	// virtual void atacar(Bien* bien) override


};

