#pragma once
#include "Guardia.h"
#include "Enemigo.h"
#include "Visitante.h"
#include "Aliado.h"
#include "Reportera.h"
#include <vector>

using std::vector;

class GestorEscenario1
{
private:
	Guardia* guardia;
	vector<Enemigo*> ladrones;
	vector<Visitante*> visitantes;
	Aliado* reportera;
	int anchoLienzo;
	int altoLienzo;
	int enemigosTotales;
	int enemigosDerrotados;
	int temporizador;
public:
	GestorEscenario1(Guardia* guardia, int anchoLienzo, int altoLienzo);
	~GestorEscenario1();
	void mover();
	void dibujar(Graphics^ g);
	void detectarColisiones();
	void jugar();

	void agregarLadron(Enemigo* nuevo);
	void agregarVisitante(Visitante* nuevo);
	void eliminarLadron(int i);
	void eliminarVisitante(int i);

	bool victoria();
	int getTotalLadrones();
};

