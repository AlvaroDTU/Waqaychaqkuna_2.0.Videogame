#include "pch.h"
#include "GestorMuseo.h"
#include "Artilugio.h"
#include "Ladron.h"
#include "Reportera.h"
#include <ctime>
#include <cstdlib>

GestorMuseo::GestorMuseo(int enTotales) : Escenario(enTotales)
{
	srand(time(nullptr));
	crearSprites();
	tempSpawnEntidades = 75;
	fondoActual = 1;
}

GestorMuseo::~GestorMuseo()
{
	Escenario::~Escenario();
}

void GestorMuseo::crearSprites()
{
	fondo = new Fondo(1, anchoLienzo, altoLienzo);

	guardia = new Guardia(790, 170,45,60,60,80);

	agregarBien(new Artilugio(153, 50, 230, 50, 800, "Cabeza Clava"));
	agregarBien(new Artilugio(535, 50, 230, 50, 1000, "Telar"));
	agregarBien(new Artilugio(917, 50, 230, 50, 2000, "Craneo"));
	agregarBien(new Artilugio(153, 600, 230, 50, 3000, "Huaco"));
	agregarBien(new Artilugio(535, 600, 230, 50, 5000, "Tumi Dorado"));
	agregarBien(new Artilugio(917, 600, 230, 50, 2500, "Vaso Kero"));
}

void GestorMuseo::mover()
{
	guardia->mover(1, anchoLienzo, altoLienzo);
	for (auto ladron : enemigos) ladron->mover(anchoLienzo, altoLienzo);
	for (int i = 0; i < (int)visitantes.size(); i++)
	{
		visitantes[i]->mover(anchoLienzo, altoLienzo);
		if (visitantes[i]->terminoRecorrido()) {
			eliminarVisitante(i);
			i--;
		}
	}
}
// void GestorMuseo::moverGuardia(Direccion direccion)
// {
// 	guardia->mover(direccion, anchoLienzo, altoLienzo, 1);
// }
void GestorMuseo::dibujar(Graphics^ g)
{
	fondo->dibujarFondo(g);
	for (auto reportera : aliados) reportera->dibujar(g);
	for (auto ladron : enemigos) ladron->dibujar(g);
	for (auto visitante : visitantes) visitante->dibujar(g);
	guardia->dibujar(g);
}

void GestorMuseo::detectarColisiones()
{
	Rectangle hbGuardia = guardia->getRectangle();
	Rectangle cambioDer = Rectangle(0, 0, 0, 0);
	Rectangle cambioIzq = Rectangle(0, 0, 0, 0);

	if (fondoActual == 1)
	{
		cambioDer = Rectangle(1241, 349, 60, 110);
	}
	if (fondoActual == 2)
	{
		cambioIzq = Rectangle(0, 350, 70, 110);
		cambioDer = Rectangle(1236, 355, 64, 110);
	}
	if (fondoActual == 3)
	{
		cambioIzq = Rectangle(0, 356, 65, 105);
	}
	if (hbGuardia.IntersectsWith(cambioDer))
	{
		fondoActual++;
		fondo->cambioEscena(fondoActual);
		if (fondoActual == 2) guardia->setPos(85, 370);
		if (fondoActual == 3) guardia->setPos(80, 365);
	}
	if (hbGuardia.IntersectsWith(cambioIzq)) {
		fondoActual--;
		fondo->cambioEscena(fondoActual);
		if (fondoActual == 1) guardia->setPos(1171, 377);
		if (fondoActual == 2) guardia->setPos(1162, 367);
	}
}

// void GestorMuseo::jugar()
// {
// 	if (temporizador == 50)
// 	{
// 		temporizador = 0;
// 		int dx = (rand() % 2) * 10 - 5; // entre -1 y 1
// 		int dy = 0;
// 		int objetivo = rand() % 6;
// 		int x = 0, y = (rand() % 2) * 110 + 305;
// 		if (dx > 0) x = -60;
// 		if (dx < 0) x = 1299;
// 		int op = rand() % 4;
// 		if (op < 2)
// 		{
// 			Ladron* nuevo = new Ladron(x, y, dx, dy, false, objetivo, rand() % 4 + 1, reportera->getTipoPista());
// 			agregarLadron(nuevo);
// 		}
// 		else
// 		{
// 			Visitante* nuevo = new Visitante(x, y, dx, 0);
// 			agregarVisitante(nuevo);
// 		}
// 	}
// 	mover();
// 	detectarColisiones();
// 	temporizador++;
// }

void GestorMuseo::agregarVisitante(Visitante* nuevo) { visitantes.push_back(nuevo); }
void GestorMuseo::eliminarVisitante(int i) { visitantes.erase(visitantes.begin() + i); }
bool GestorMuseo::victoria()
{
	return false;
}