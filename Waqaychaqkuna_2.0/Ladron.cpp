#include "pch.h"
#include "Ladron.h"

Ladron::Ladron(int posX, int posY, int an, int al, int anF, int alF, int dirX, int dirY, int obj, int t, int tPista)
	: Enemigo(posX, posY, an, al, anF, alF, dirX, dirY, obj)
{
	this->tipo = t;
	this->tipoPista = tPista;
	fila = (dirX > 0) ? 2 : 1;
	atacando = false;
	tempMovimiento = 0;
	tempAtaque = 1000;
}
Ladron::~Ladron() {}

std::string Ladron::getNombre() {
	for (int i = 0; i < 4; i++) {
		if (i == tipo) {
			return "ladron" + std::to_string(i + 1);
		}
	}
}
void Ladron::mover(vector<Objeto*> objetos, vector<Bien*> bienes) {

	if (tempAtaque > 0) 
	{
		tempAtaque--;
		tempMovimiento++;
		if (tempMovimiento >= 100 && tempMovimiento <= 150)
		{
			if (tempMovimiento == 100) {
				dirX = (rand() % 3 - 1);
				dirY = (rand() % 3 - 1);
				if (dirX == 0 && dirY == 0)
				{
					if (rand() % 2 == 0) { dirX = (rand() % 2 == 0) ? 1 : -1; dirY = 0; }
					else { dirX = 0; dirY = (rand() % 2 == 0) ? 1 : -1; }
				}
			}
			bool colision = false;
			Rectangle hbLadron = getRectangle();
			hbLadron.X += dirX;
			hbLadron.Y += dirY;
			for (int i = 0; i < (int)objetos.size(); i++)
			{
				if (hbLadron.IntersectsWith(objetos[i]->getRectangle()))
					colision = true;
			}
			for (int i = 0; i < (int)bienes.size(); i++)
			{
				if (hbLadron.IntersectsWith(bienes[i]->getRectangle()) && bienes[i]->estaActivo())
					colision = true;
			}
			if (!colision)
			{
				posX += dirX;
				posY += dirY;
			}

			if (tempMovimiento >= 150)
			{
				tempMovimiento = 0;
				dirX = 0;
				dirY = 0;
			}
		}
	}
	else
	{
		atacando = true;
		int cx=0, cy=0;
		if (objetivo == 0) { cx = 333; cy = 391; }
		if (objetivo == 1) { cx = 640; cy = 391; }
		if (objetivo == 2) { cx = 947; cy = 386; }
		if (objetivo == 3) { cx = 312; cy = 419; }
		if (objetivo == 4) { cx = 596; cy = 418; }
		if (objetivo == 5) { cx = 880; cy = 418; }

		if (posX < cx) dirX = 3;
		if (posX > cx) dirX = -3;
		if (posY > cy) dirY = -3;
		if (posY < cy) dirY = 3;

		bool colision = false;
		Rectangle hbLadron = getRectangle();
		hbLadron.X += dirX;
		hbLadron.Y += dirY;
		for (int i = 0; i < (int)objetos.size(); i++)
		{
			if (hbLadron.IntersectsWith(objetos[i]->getRectangle()))
				colision = true;
		}
		for (int i = 0; i < (int)bienes.size(); i++)
		{
			if (hbLadron.IntersectsWith(bienes[i]->getRectangle()) && bienes[i]->estaActivo())
				colision = true;
		}
		if (!colision)
		{
			posX += dirX;
			posY += dirY;
		}
	}
	if (dirX > 0) fila = 2;
	if (dirX < 0) fila = 1;
	if (dirY > 0) fila = 0;
	if (dirY < 0) fila = 3;

	if (dirX != 0 || dirY != 0) avanzarEscena();
	else columna = 0;

}

void Ladron::atacar(Bien* bien) 
{
	bien->restarPuntajeValor(5);
}

Bitmap^ Ladron::getBitmap() {
	Bitmap^ img=nullptr;
	if (tipo == 1) {
		if (tipoPista == 1) { img = Recursos::ladron_bandana1; }
		else if (tipoPista == 2) { img = Recursos::ladron_brazalete1; }
		else if (tipoPista == 3) { img = Recursos::ladron_camisa1; }
	}
	else if (tipo == 2) {
		if (tipoPista == 1) { img = Recursos::ladron_bandana2; }
		else if (tipoPista == 2) { img = Recursos::ladron_brazalete2; }
		else if (tipoPista == 3) { img = Recursos::ladron_camisa2; }
	}
	else if (tipo == 3) {
		if (tipoPista == 1) { img = Recursos::ladron_bandana3; }
		else if (tipoPista == 2) { img = Recursos::ladron_brazalete3; }
		else if (tipoPista == 3) { img = Recursos::ladron_camisa3; }
	}
	else if (tipo == 4) {
		if (tipoPista == 1) { img = Recursos::ladron_bandana4; }
		else if (tipoPista == 2) { img = Recursos::ladron_brazalete4; }
		else if (tipoPista == 3) { img = Recursos::ladron_camisa4; }
	}
	return img;
}