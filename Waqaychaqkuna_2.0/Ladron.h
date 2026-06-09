#pragma once
#include "Enemigo.h"
#include "Bien.h"

class Ladron : public Enemigo
{
private:
	int tipo;
	int tipoPista;
public:
	Ladron(int posX, int posY, int dirX, int dirY, bool atack, int obj, int t, int tPista);
	~Ladron();

	std::string getNombre() override;
	void mover(int ancho, int alto) override;
	void dibujar(Graphics^ g) override;
	Bitmap^ getBitmap() override;
	void atacar(Bien* bien) override;
};

