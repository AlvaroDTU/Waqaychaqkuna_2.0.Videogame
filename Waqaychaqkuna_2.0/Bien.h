#pragma once
#include "Recursos.h"
#include <string>

using namespace System::Drawing;

class Bien
{
protected:
	int posX, posY;
	int ancho, alto;
	int puntajeValor;
	int tipo;
	std::string nombre;
	bool colision;
	bool activo;

public:
	Bien(int px, int py, int an, int al, int pValor, std::string nom, int ti, bool act = true);
	~Bien();

	int getPosX();
	int getPosY();
	int getPuntajeValor();
	std::string getNombre();
	bool getColision();
	void setColision(bool a);

	bool estaActivo();
	void setActivo(bool act);
	void restarPuntajeValor(int pv);
	Rectangle getRectangle(int extra = 0);
	virtual Bitmap^ getBitmap() = 0;
	virtual Bitmap^ getBitmapDescripciones() = 0;
	virtual void dibujar(Graphics^ g, float escalaX, float escalaY) = 0;
	virtual void dibujarDescripcion(Graphics^ g, float escalaX, float escalaY) = 0;

};

