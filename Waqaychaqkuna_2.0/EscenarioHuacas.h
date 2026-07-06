#pragma once
#include "Guardia.h"
#include "Huaquero.h"
#include "Cuidador.h"
#include "Escenario.h"
#include <vector>
using std::vector;

class EscenarioHuacas : public Escenario
{
private:
	int contador;
	int temporizadorMov;
public:
	EscenarioHuacas();
	~EscenarioHuacas();
	void crearSprites() override;
	void dibujar(Graphics^ g) override;
	void mover() override;
	void detectarColisiones() override;

	bool victoria() override;
	bool derrota() override;

	void jugar();

	void generarHuaquero();
	void generarCuidador();

};

