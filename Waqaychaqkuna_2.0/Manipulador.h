#pragma once
#include "Enemigo.h"
class Manipulador : public Enemigo
{
public:
	int tiempoMovimiento;
private:
	Manipulador(int x, int y, int dx, int dy, bool at, int obj, int vid, int tM);
	~Manipulador();

	int getTemMov();
	void setTemMov(int TM);

	std::string getNombre() override;

	void mover(int ancho, int alto) override;
	void dibujar(Graphics^ g) override;
	Bitmap^ getBitmap() override;
	// virtual void atacar(Bien* bien) override



};

