#pragma once
#include "Entidad.h"


class Guardia : public Entidad
{
private:
	int tipoAccion;
	bool accion;
public:

	Guardia(std::string nombre, int posX, int posY, int acnho, int alto, int dirX, int dirY, int tpAccion, bool Accio);
	~Guardia();
	bool getAccion();
	int getTipoAccion();
	void setAccion(bool acc);
	void setTipoAccion(int tAcc);
	
	std::string getNombre();
	void mover(Direccion direccion) override;
	void dibujar(Graphics^ g, Bitmap^ img) override;


};

