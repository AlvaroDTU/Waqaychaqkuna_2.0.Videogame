#pragma once

using namespace System::Drawing;

class Fondo
{
private:
	int tipo;
	int x, ancho, alto;
public:
	Fondo(int t, int anchoLienzo, int altoLienzo);
	void dibujarFondo(Graphics^ g);
	Bitmap^ getBitmap();
};

