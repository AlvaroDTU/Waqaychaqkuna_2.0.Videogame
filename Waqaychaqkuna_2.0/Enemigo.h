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
	Enemigo(int posX, int posY,int dirX, int dirY, bool at, int obj);
	~Enemigo();

	bool getAtacando();
	int getObjetivo();
	void setAtacando(bool at);
	void setObjetivo(int obj);
	virtual void atacar(Bien* bien) = 0;

};
