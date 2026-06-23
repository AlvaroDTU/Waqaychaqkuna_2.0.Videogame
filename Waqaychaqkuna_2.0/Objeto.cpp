#include "pch.h"
#include "Objeto.h"

Objeto::Objeto(int x, int y, int ancho, int alto)
	: posX(x), posY(y), ancho(ancho), alto(alto), activo(false)
{}

bool Objeto::estaActivo() { return activo; }
void Objeto::setActivo(bool a) { activo = a; }
Rectangle Objeto::getRectangle(int extra)
{
	return Rectangle(posX - extra, posY - extra, ancho + 2 * extra, alto + 2 * extra);
}