#include "pch.h"
#include "GestorEscenario1.h"
#include "Artilugio.h"
#include "Ladron.h"
#include <ctime>
#include <cstdlib>

GestorEscenario1::GestorEscenario1(Guardia* guardia, int anchoLienzo, int altoLienzo, int enemigosTotales) :
	guardia(guardia), anchoLienzo(anchoLienzo), altoLienzo(altoLienzo), enemigosTotales(enemigosTotales)
{
	srand(time(nullptr));
	artilugios.push_back(new Artilugio(153, 50, 230, 50, 800, "Cabeza Clava"));
	artilugios.push_back(new Artilugio(535, 50, 230, 50, 1000, "Telar"));
	artilugios.push_back(new Artilugio(917, 50, 230, 50, 2000, "Craneo"));
	artilugios.push_back(new Artilugio(153, 600, 230, 50, 3000, "Huaco"));
	artilugios.push_back(new Artilugio(535, 600, 230, 50, 5000, "Tumi Dorado"));
	artilugios.push_back(new Artilugio(917, 600, 230, 50, 2500, "Vaso Kero"));
	reportera = new Reportera(40, 120, 0, 0, false, rand() % 4 + 1);
	enemigosDerrotados = 0;
	temporizador = 0;
}

GestorEscenario1::~GestorEscenario1()
{
	for (auto visitante : visitantes) delete visitante;
	visitantes.clear();
	for (auto ladron : ladrones) delete ladron;
	ladrones.clear();
	delete reportera;
	reportera = nullptr;
}

void GestorEscenario1::mover()
{
	for (auto ladron : ladrones) ladron->mover(anchoLienzo, altoLienzo);
	for (int i=0;i< (int)visitantes.size();i++) 
	{ 
		visitantes[i]->mover(anchoLienzo, altoLienzo);
		if (visitantes[i]->terminoRecorrido()) {
			eliminarVisitante(i);
			i--;
		}
	}
}
void GestorEscenario1::moverGuardia(Direccion direccion)
{
	guardia->mover(direccion, anchoLienzo, altoLienzo, 1);
}
void GestorEscenario1::dibujar(Graphics^ g)
{
	reportera->dibujar(g);
	for (auto ladron : ladrones) ladron->dibujar(g);
	for (auto visitante : visitantes) visitante->dibujar(g);
	guardia->dibujar(g);
}

void GestorEscenario1::detectarColisiones()
{

}

void GestorEscenario1::jugar()
{
	if (temporizador == 20)
	{
		temporizador = 0;
		int dx = (rand() % 2) * 10 - 5; // entre -1 y 1
		int dy = 0;
		int objetivo = rand() % 6;
		int x = 0, y = (rand() % 2) * 110 + 305;
		if (dx > 0) x = 0;
		if (dx < 0) x = 1239;
		int op = rand() % 4;
		if (op < 2)
		{
			Ladron* nuevo = new Ladron(x, y, dx, dy, false, objetivo, rand() % 4 + 1, reportera->getTipoPista());
			agregarLadron(nuevo);
		}
		else
		{
			Visitante* nuevo = new Visitante(x, y, dx, 0);
			agregarVisitante(nuevo);
		}
	}
	mover();
	detectarColisiones();
	temporizador++;
}

void GestorEscenario1::agregarLadron(Enemigo* nuevo) { ladrones.push_back(nuevo); }
void GestorEscenario1::agregarVisitante(Visitante* nuevo) { visitantes.push_back(nuevo); }
void GestorEscenario1::eliminarLadron(int i) { ladrones.erase(ladrones.begin() + i); }
void GestorEscenario1::eliminarVisitante(int i) { visitantes.erase(visitantes.begin() + i); }
bool GestorEscenario1::victoria()
{
	return false;
}

int GestorEscenario1::getTotalLadrones() { return (int)ladrones.size(); }