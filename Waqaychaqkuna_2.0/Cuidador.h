#pragma once
#include "Aliado.h"
class Cuidador : public Aliado
{
private:
	int duracion;
	int contadorAnimacion = 40;
public:
	Cuidador(int posX, int posY, int an, int al, int anF, int alF);
	~Cuidador();

	int getDuracion();
	void RestarDuracion(int d);

	void mover(int ancho, int alto) override {}
	void ayudar() override {}

	std::string getNombre() override;
	Bitmap^ getBitmap() override;
	void sinMover();

};

