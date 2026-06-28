#pragma once
#include "Guardia.h"
#include "Huaquero.h"
#include "Cuidador.h"
#include "Escenario.h"
#include <vector>
using std::vector;

class GestorHuacas : public Escenario
{
private:
	int temporizadorMov;
public:
	GestorHuacas(int enTotales);
	~GestorHuacas();
	void crearSprites() override;
	void dibujar(Graphics^ g) override;
	void mover() override;
	void detectarColisiones() override;

	bool victoria() override;
	void jugar();

	void generarHuaquero();

};

