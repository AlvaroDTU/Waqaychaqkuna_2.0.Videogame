#pragma once
#include "Guardia.h"
#include "Huaquero.h"
#include "Cuidador.h"
#include <vector>
using std::vector;

class GestorHuacas
{
private:
	Guardia* guardia;
	vector<Enemigo*> huaqueros;
	vector<Cuidador*> cuidadores;
	int anchoLienzo;
	int altoLienzo;
	int enemigosTotales;
	int enemigosDerrotados;
	int temporizador;
	int puntajeNivel;

public:
	GestorHuacas(Guardia* guardia, int anchoLienzo, int altoLienzo);
	~GestorHuacas();
	void mover(int x);
	void dibujar(Graphics^ g);
	void detectarColisiones();
	bool victoria();
	int getTotalHuaquero();

	void jugar();
	void agregarCuidador(Cuidador* c);
	void agregarHuaquero(Huaquero* h);
	void eliminarCuidador(int i);
	void eliminarHuaquero(int i);
	void agregarBien();

};

