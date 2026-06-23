#pragma once

using namespace System::Drawing;

class Objeto
{
private:
	int posX, posY;
	int ancho, alto;
public:
	Objeto(int x, int y, int ancho, int alto);
	Rectangle getRectangle(int extra=0);
};

