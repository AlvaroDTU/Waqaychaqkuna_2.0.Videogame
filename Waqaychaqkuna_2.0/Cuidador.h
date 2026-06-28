#pragma once
#include "Aliado.h"
class Cuidador : public Aliado
{
private:
	int duracion;
public:
	Cuidador(int posX, int posY, int an, int al, int anF, int alF);
	~Cuidador();

	int getDuracion();
	void RestarDuracion(int d);


	std::string getNombre() override;
	Bitmap^ getBitmap() override;
	void sinMover() {
		if (ayudando == false) {
			fila++;
			if (fila == 4) {
				fila = 0;
			}
		}
	}

};

