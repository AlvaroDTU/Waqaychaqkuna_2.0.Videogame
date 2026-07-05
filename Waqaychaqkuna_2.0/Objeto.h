#pragma once

using namespace System::Drawing;

class Objeto
{
private:
	int posX, posY;
	int ancho, alto;
	bool activo;
public:
	Objeto(int x, int y, int ancho, int alto);
	bool estaActivo();
	void setActivo(bool a);
	System::Drawing::Rectangle getRectangle(int extra=0);
};

