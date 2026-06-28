#pragma once
#include "Fondo.h"
#include "Guardia.h"
#include "Objeto.h"
#include "Enemigo.h"
#include "Aliado.h"
#include "Bien.h"
#include <vector>

using std::vector;

class Escenario
{
protected:
	Fondo* fondo;
	Guardia* guardia;
	vector<Enemigo*> enemigos;
	vector<Aliado*> aliados;
	vector<Bien*> bienes;
	vector<Objeto*> objetos;
	int anchoLienzo;
	int altoLienzo;
	int enemigosTotales;
	int enemigosDerrotados;
	int tempSpawnEntidades;
	int puntajeNivel;

public:
	Escenario(int enTotales);
	virtual ~Escenario();

	virtual void crearSprites() = 0;
	virtual void dibujar(Graphics^ g) = 0;
	virtual void mover() = 0;
	virtual void detectarColisiones() = 0;
	virtual bool victoria() = 0;

	void setLienzo(int ancho, int alto);
	void agregarEnemigo(Enemigo* nuevo);
	void agregarAliado(Aliado* nuevo);
	void agregarBien(Bien* nuevo);
	void agregarObjeto(Objeto* nuevo);
	void eliminarEnemigo(int i);
	void eliminarAliado(int i);
	int totalEnemigos();
	int totalAliados();
	int totalBienes();

	int getPuntajeNivel() { return puntajeNivel; }

	Guardia* getGuardia();
};


