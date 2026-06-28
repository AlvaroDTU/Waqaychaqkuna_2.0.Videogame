#pragma once
#include "Entidad.h"
#include "Objeto.h"
#include "Bien.h"
#include <vector>

using std::vector;
class Guardia : public Entidad
{
private:
	int tipoAccion;
	bool accion;
public:

	Guardia(int posX, int posY, int an, int al, int anF, int alF);
	~Guardia();
	bool getAccion();
	int getTipoAccion();
	void setVelocidad(int dx, int dy);
	void mover(vector<Objeto*> objetos, vector<Bien*> bienes);
	int getDirX();
	int getDirY();
	void setAccion(bool acc);
	void setTipoAccion(int tAcc);
	void setMoviendose(bool mov);

	Bitmap^ getBitmap() override;
	std::string getNombre() override;
	void mover(int ancho, int alto) override;
};

