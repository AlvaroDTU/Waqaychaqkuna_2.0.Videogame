#pragma once
#include "Entidad.h"
#include "Bien.h"

class Nivel;

class Enemigo : public Entidad
{
protected:
	bool atacando;
	int objetivo;
public:
	Enemigo(int posX, int posY, int an, int al, int anF, int alF, int dirX, int dirY, int obj);
	~Enemigo();

	bool getAtacando();
	int getObjetivo();
	void setAtacando(bool at);
	void setObjetivo(int obj);
	virtual void atacar(Bien* bien) = 0;

};
