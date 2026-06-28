#pragma once
#include "Entidad.h"
class Aliado : public Entidad
{
protected:
	bool ayudando;
	bool activo;
public:
	Aliado(int posX, int posY, int an, int al, int anF, int alF,bool act=true);
	~Aliado();

	bool estaAyudando();
	void setAyudando(bool ayuda);

	bool estaActivo();
	void setActivo(bool act);

	virtual void ayudar() = 0;


};

