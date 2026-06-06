#pragma once
#include "Entidad.h"
class Aliado : public Entidad
{
protected:
	bool ayudando;
public:
	Aliado();
	Aliado(int posX, int posY, int dirX, int dirY, bool ayuda);
	~Aliado();

	bool getAyudando();
	void setAyudando(bool ayuda);


	// VER SI ESTO SE IMPREMENTARA
	virtual void ayudar() = 0;


};

