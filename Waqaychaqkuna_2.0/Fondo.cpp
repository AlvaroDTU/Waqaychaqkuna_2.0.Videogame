#include "pch.h"
#include "Recursos.h"
#include "Fondo.h"

Fondo::Fondo(int t, int anchoLienzo, int altoLienzo)
	: x(0), tipo(t), ancho(anchoLienzo), alto(altoLienzo), fondoActual(1)
{

}

void Fondo::dibujarFondo(Graphics^ g)
{
	Bitmap^ bmp = getBitmap();
	g->DrawImage(bmp, 0, 0, Rectangle(x, 0, ancho, alto), GraphicsUnit::Pixel);
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