#include "pch.h"
#include "Visitante.h"

Visitante::Visitante(int posX, int posY, int an, int al, int anF, int alF, int dirX, int dirY)
	: Entidad(posX, posY, an, al, anF, alF, dirX, dirY)
{
	tipo = rand() % 4 + 1;
	tempMovimiento = 0;
}
Visitante::~Visitante() {}

std::string Visitante::getNombre() {
	for (int i = 0; i < 4; i++) {
		if (i + 1 == tipo) {
			return "visitante" + std::to_string(i + 1);
		}
	}
}

void Visitante::mover(vector<Objeto*> objetos, vector<Bien*> bienes)
{
	bool colision = false;
	Rectangle hbVisitante = getRectangle();
	hbVisitante.X += dirX;
	hbVisitante.Y += dirY;
	for (int i = 0; i < (int)objetos.size(); i++)
	{
		if (hbVisitante.IntersectsWith(objetos[i]->getRectangle()))
			colision = true;
	}
	for (int i = 0; i < (int)bienes.size(); i++)
	{
		if (hbVisitante.IntersectsWith(bienes[i]->getRectangle()) && bienes[i]->estaActivo())
			colision = true;
	}

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
			if (dirX > 0) fila = 2;
			if (dirX < 0) fila = 1;
			if (dirY > 0) fila = 0;
			if (dirY < 0) fila = 3;
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
	if (dirX != 0 || dirY != 0) avanzarEscena();
	else columna = 0;
}

Bitmap^ Visitante::getBitmap()
{
	Bitmap^ img = nullptr;
	if (tipo == 1) { img = Recursos::visitante1; }
	else if (tipo == 2) { img = Recursos::visitante2; }
	else if (tipo == 3) { img = Recursos::visitante3; }
	else if (tipo == 4) { img = Recursos::visitante4; }
	return img;
}