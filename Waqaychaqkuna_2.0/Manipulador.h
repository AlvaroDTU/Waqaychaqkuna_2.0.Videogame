#pragma once
#include "Enemigo.h"
class Manipulador : public Enemigo
{
private:
	int tipo;
	bool iluminado;
	int posFinal;
public:
	Manipulador(int posX, int posY, int an, int al, int anF, int alF, int dirX, int dirY, int obj, int t, bool iluminado);
	~Manipulador();

	int getTipo();
	void setTipo(int TM);
	bool getIluminado();
	void setIluminado(bool i);

	std::string getNombre() override;

	void mover(int ancho, int alto) override;
	Bitmap^ getBitmap() override;
	void atacar(Bien* bien) override;
};

