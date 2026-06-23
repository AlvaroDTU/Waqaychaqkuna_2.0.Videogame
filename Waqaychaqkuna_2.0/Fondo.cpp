#include "pch.h"
#include "Recursos.h"
#include "Fondo.h"

Fondo::Fondo(int t, int anchoLienzo, int altoLienzo)
	: x(0), tipo(t), ancho(anchoLienzo), alto(altoLienzo)
{
}

void Fondo::dibujarFondo(Graphics^ g)
{
	Bitmap^ bmp = getBitmap();
	g->DrawImage(bmp, 0, 0, Rectangle(x, 0, ancho, alto), GraphicsUnit::Pixel);
}
Bitmap^ Fondo::getBitmap() 
{
	if (tipo == 1) return Recursos::museo;
	// if (tipo == 2) return Recursos::huacas;
	// if (tipo == 3) return Recursos::biblioteca;
}