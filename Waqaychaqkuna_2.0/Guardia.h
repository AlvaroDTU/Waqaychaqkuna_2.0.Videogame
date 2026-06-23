#pragma once
#include "Entidad.h"


class Guardia : public Entidad
{
private:
	int tipoAccion;
	bool accion;
public:

	Guardia(int posX, int posY, int dirX, int dirY, int tpAccion, bool Accio);
	~Guardia();
	bool getAccion();
	int getTipoAccion();
	void setVelocidad(int dx, int dy);
	void mover(int idx, int ancho, int alto);
	int getDirX();
	int getDirY();
	void setAccion(bool acc);
	void setTipoAccion(int tAcc);

	Bitmap^ getBitmap() override;
	std::string getNombre() override;
	void mover(int ancho, int alto) override;
	void dibujar(Graphics^ g) override;


};

