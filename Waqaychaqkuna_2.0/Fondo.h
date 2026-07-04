#pragma once

using namespace System::Drawing;

class Fondo
{
private:
	int tipo;
	int fondoActual;
	int x, ancho, alto;
public:
	Fondo(int t, int anchoLienzo, int altoLienzo);
	void dibujarFondo(Graphics^ g, float escalaX, float escalaY);
	void cambioEscena(int destino);
	Bitmap^ getBitmap();
};

