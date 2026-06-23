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
}

GestorMuseo::~GestorMuseo()
{
	Escenario::~Escenario();
}

void GestorMuseo::crearSprites() 
{
	fondo = new Fondo(1, anchoLienzo, altoLienzo);

	guardia = new Guardia(20, 20, 0, 0, 0, false);

	agregarBien(new Artilugio(153, 50, 230, 50, 800, "Cabeza Clava"));
	agregarBien(new Artilugio(535, 50, 230, 50, 1000, "Telar"));
	agregarBien(new Artilugio(917, 50, 230, 50, 2000, "Craneo"));
	agregarBien(new Artilugio(153, 600, 230, 50, 3000, "Huaco"));
	agregarBien(new Artilugio(535, 600, 230, 50, 5000, "Tumi Dorado"));
	agregarBien(new Artilugio(917, 600, 230, 50, 2500, "Vaso Kero"));

	// agregarAliado(new Reportera(40, 120, 0, 0, false, rand() % 3 + 1));
}

void GestorMuseo::mover()
{
	guardia->mover(1, anchoLienzo, altoLienzo);
	for (auto ladron : enemigos) ladron->mover(anchoLienzo, altoLienzo);
	for (int i=0;i< (int)visitantes.size();i++) 
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