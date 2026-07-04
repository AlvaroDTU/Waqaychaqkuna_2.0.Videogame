#include "pch.h"
#include "Recursos.h"
#include "Fondo.h"

Fondo::Fondo(int t, int anchoLienzo, int altoLienzo)
	: x(0), tipo(t), ancho(anchoLienzo), alto(altoLienzo), fondoActual(1)
{

}

void Fondo::dibujarFondo(Graphics^ g, float escalaX, float escalaY)
{
	Bitmap^ bmp = getBitmap();
	Rectangle origen(x, 0, ancho, alto);
	Rectangle destino(0, 0, 1300 * escalaX, 800 * escalaY);
	g->DrawImage(bmp, destino, origen, GraphicsUnit::Pixel);
}

void Fondo::cambioEscena(int fActual)
{
	if (fActual > 3 || fActual < 0) return;
	fondoActual = fActual;
}

Bitmap^ Fondo::getBitmap()
{
	Bitmap^ img = nullptr;
	if (tipo == 1)
	{
		if (fondoActual == 1) img = Recursos::museo_fondo1;
		if (fondoActual == 2) img = Recursos::museo_fondo2;
		if (fondoActual == 3) img = Recursos::museo_fondo3;
	}
	if (tipo == 2) img = Recursos::huacas;
	if (tipo == 3) img = Recursos::biblioteca;

	return img;
}