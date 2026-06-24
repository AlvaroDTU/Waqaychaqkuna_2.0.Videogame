#include "pch.h"
#include "Ladron.h"

Ladron::Ladron(int posX, int posY, int an, int al, int anF, int alF, int dirX, int dirY, bool at, int obj, int t, int tPista)
	: Enemigo(posX, posY, an, al, anF, alF, dirX, dirY, at, obj)
{
	this->tipo = t;
	this->tipoPista = tPista;
	fila = (dirX > 0) ? 2 : 1;
	atacando = false;
}
Ladron::~Ladron() {}

std::string Ladron::getNombre() {
	for (int i = 0; i < 4; i++) {
		if (i == tipo) {
			return "ladron" + std::to_string(i + 1);
		}
	}
}
void Ladron::mover(int ancho, int alto) {
	moviendose = true;
	Rectangle hitboxLadron = getRectangle(5);
	Rectangle bien1 = Rectangle(153, 50, 230, 50);
	Rectangle bien2 = Rectangle(535, 50, 230, 50);
	Rectangle bien3 = Rectangle(917, 50, 230, 50);
	Rectangle bien4 = Rectangle(153, 600, 230, 50);
	Rectangle bien5 = Rectangle(535, 600, 230, 50);
	Rectangle bien6 = Rectangle(917, 600, 230, 50);
	bool colisionMapa = hitboxLadron.IntersectsWith(bien1) || hitboxLadron.IntersectsWith(bien2) ||
		hitboxLadron.IntersectsWith(bien3) || hitboxLadron.IntersectsWith(bien4) ||
		hitboxLadron.IntersectsWith(bien5) || hitboxLadron.IntersectsWith(bien6);
	if (!colisionMapa) { posX += dirX; posY += dirY; }
	if (objetivo == 0)
	{
		if (posX >= 258 && posX <= 277) { dirX = 0; dirY = -5; fila = 3; }
		if (posY <= 200) { posY = 200; moviendose = false; }
	}
	if (objetivo == 1)
	{
		if (posX >= 640 && posX <= 659) { dirX = 0; dirY = -5; fila = 3; }
		if (posY <= 200) { posY = 200; moviendose = false; }
	}
	if (objetivo == 2)
	{
		if (posX >= 1022 && posX <= 1041) { dirX = 0; dirY = -5; fila = 3; }
		if (posY <= 200) { posY = 200; moviendose = false; }
	}
	if (objetivo == 3)
	{
		if (posX >= 258 && posX <= 277) { dirX = 0; dirY = 5; fila = 0; }
		if (posY + alto >= 599) { posY = 599 - alto; moviendose = false; }
	}
	if (objetivo == 4)
	{
		if (posX >= 640 && posX <= 659) { dirX = 0; dirY = 5; fila = 0; }
		if (posY + alto >= 599) { posY = 599 - alto; moviendose = false; }
	}
	if (objetivo == 5)
	{
		if (posX >= 1022 && posX <= 1041) { dirX = 0; dirY = 5; fila = 0; }
		if (posY + alto >= 599) { posY = 599 - alto; moviendose = false; }
	}
}
void Ladron::dibujar(Graphics^ g) {
	Bitmap^ img = getBitmap();
	this->alto = img->Height / 4;
	this->ancho = img->Width / 4;

	Rectangle molde = Rectangle(ancho * columna, fila * alto, ancho, alto);
	avanzarEscena();
	g->DrawImage(img, posX, posY, molde, GraphicsUnit::Pixel);
}

void Ladron::atacar(Bien* bien) {}

Bitmap^ Ladron::getBitmap() {
	Bitmap^ img;
	if (tipo == 1) {
		if (tipoPista == 1) { img = Recursos::ladron_bandana1; }
		else if (tipoPista == 2) { img = Recursos::ladron_brazalete1; }
		else if (tipoPista == 3) { img = Recursos::ladron_camisa1; }
		else if (tipoPista == 4) { img = Recursos::guardia; }
	}
	else if (tipo == 2) {
		if (tipoPista == 1) { img = Recursos::ladron_bandana2; }
		else if (tipoPista == 2) { img = Recursos::ladron_brazalete2; }
		else if (tipoPista == 3) { img = Recursos::ladron_camisa2; }
		else if (tipoPista == 4) { img = Recursos::guardia; }
	}
	else if (tipo == 3) {
		if (tipoPista == 1) { img = Recursos::ladron_bandana3; }
		else if (tipoPista == 2) { img = Recursos::ladron_brazalete3; }
		else if (tipoPista == 3) { img = Recursos::ladron_camisa3; }
		else if (tipoPista == 4) { img = Recursos::guardia; }
	}
	else if (tipo == 4) {
		if (tipoPista == 1) { img = Recursos::ladron_bandana4; }
		else if (tipoPista == 2) { img = Recursos::ladron_brazalete4; }
		else if (tipoPista == 3) { img = Recursos::ladron_camisa4; }
		else if (tipoPista == 4) { img = Recursos::guardia; }
	}
	return img;
}