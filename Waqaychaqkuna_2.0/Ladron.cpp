#include "pch.h"
#include "Ladron.h"

Ladron::Ladron(int posX, int posY, int dirX, int dirY, bool atack, int obj, int t, int tPista)
	: Enemigo(posX, posY, dirX, dirY, atack, obj)
{
	this->tipo = t;
	this->tipoPista = tPista;
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
		if (posX >= 269) { dirX = 0; dirY = -1; }
		if (posY >= 200) { posY = 200; atacando = true; }
	}
	if (objetivo == 1)
	{
		if (posX >= 651) { dirX = 0; dirY = -1; }
		if (posY >= 200) { posY = 200; atacando = true; }
	}
	if (objetivo == 2)
	{
		if (posX >= 1033) { dirX = 0; dirY = -1; }
		if (posY >= 200) { posY = 200; atacando = true; }
	}
	if (objetivo == 3)
	{
		if (posX >= 269) { dirX = 0; dirY = 1; }
		if (posY == 37) atacando = true;
	}
	if (objetivo == 4)
	{
		if (posX >= 651) { dirX = 0; dirY = 1; }
		if (posY == 37) atacando = true;
	}
	if (objetivo == 5)
	{
		if (posX >= 1033) { dirX = 0; dirY = 1; }
		if (posY == 37) atacando = true;
	}
}
void Ladron::dibujar(Graphics^ g) {
	Bitmap^ img;
	// LUEGO CAMBIAR POR EL DISEÑO DE CADA UNO YAP :V
	if (tipo == 1) {
		if (tipoPista == 1) { img = Recursos::guardia; }
		else if (tipoPista == 2) { img = Recursos::guardia; }
		else if (tipoPista == 3) { img = Recursos::guardia; }
		else if (tipoPista == 4) { img = Recursos::guardia; }
	}
	else if (tipo == 2) {
		if (tipoPista == 1) { img = Recursos::guardia; }
		else if (tipoPista == 2) { img = Recursos::guardia; }
		else if (tipoPista == 3) { img = Recursos::guardia; }
		else if (tipoPista == 4) { img = Recursos::guardia; }
	}
	else if (tipo == 3) {
		if (tipoPista == 1) { img = Recursos::guardia; }
		else if (tipoPista == 2) { img = Recursos::guardia; }
		else if (tipoPista == 3) { img = Recursos::guardia; }
		else if (tipoPista == 4) { img = Recursos::guardia; }
	}
	else if (tipo == 4) {
		if (tipoPista == 1) { img = Recursos::guardia; }
		else if (tipoPista == 2) { img = Recursos::guardia; }
		else if (tipoPista == 3) { img = Recursos::guardia; }
		else if (tipoPista == 4) { img = Recursos::guardia; }
	}
	this->alto = img->Height / 4;
	this->ancho = img->Width / 4;

	Rectangle molde = Rectangle(ancho * columna, fila * alto, ancho, alto);
	if (moviendose == true) {
		columna++;
		if (columna == 4) { columna = 0; }
	}
	else
	{
		columna = 0;
	}
	moviendose = false;
}

void Ladron::atacar(Bien* bien) {}