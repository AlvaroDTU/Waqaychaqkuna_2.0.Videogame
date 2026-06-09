#pragma once
#include "Guardia.h"
#include "Enemigo.h"
#include "Visitante.h"
#include "Reportera.h"
#include "Bien.h"
#include <vector>

using std::vector;

class GestorEscenario1
{
private:
	Guardia* guardia;
	vector<Enemigo*> ladrones;
	vector<Visitante*> visitantes;
	vector<Bien*> artilugios;
	Reportera* reportera;
	int anchoLienzo;
	int altoLienzo;
	int enemigosTotales;
	int enemigosDerrotados;
	int temporizador;
public:
	GestorEscenario1(Guardia* guardia, int anchoLienzo, int altoLienzo, int enemigosTotales);
	~GestorEscenario1();
	void mover();
	void moverGuardia(Direccion direccion);
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

