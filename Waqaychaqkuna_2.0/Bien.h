#pragma once
#include <string>

using namespace System::Drawing;

class Bien
{
protected:
	int posX, posY;
	int ancho, alto;
	int puntajeValor;
	std::string nombre;
public:
	Bien(int px, int py, int an, int al, int pValor, std::string nom);
	~Bien();

	int getPosX();
	int getPosY();
	int getPuntajeValor();
	std::string getNombre();

	void restarPuntajeValor(int pv);
	virtual void describir() = 0;
	Rectangle getRectangle(int extra = 0);
};

