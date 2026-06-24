#pragma once
#include "Entidad.h"
class Aliado : public Entidad
{
protected:
	bool ayudando;
public:
	Aliado(int posX, int posY, int an, int al, int anF, int alF, bool ayuda);
	~Aliado();

	bool getAyudando();
	void setAyudando(bool ayuda);

	// VER SI ESTO SE IMPREMENTARA
	virtual void ayudar() = 0;


};

