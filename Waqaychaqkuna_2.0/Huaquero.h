#pragma once
#include "Enemigo.h"
class Huaquero : public Enemigo
{
private:
	int vidas;
	int tiempoMovimiento;

public:
	Huaquero(int x, int y, int ancho, int alto, int dx, int dy, bool at, int obj, int vid, int tM);
	~Huaquero();

	int getVidas();
	void RestarVidas(int v);
	int getTemMov();
	void setTemMov(int TM);

	std::string getNombre() override;

	void mover(Direccion direccion) override;
	void dibujar(Graphics^ g) override;


};

