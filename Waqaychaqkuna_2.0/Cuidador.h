#pragma once
#include "Aliado.h"
class Cuidador : public Aliado
{
private:
	int duracion;
public:
	Cuidador(int posX, int posY, int dirX, int dirY, bool ayuda, int dura);
	~Cuidador();

	int getDuracion();
	void RestarDuracion(int d);


	std::string getNombre() override;
	void dibujar(Graphics^ g) override;
	Bitmap^ getBitmap() override;
};

