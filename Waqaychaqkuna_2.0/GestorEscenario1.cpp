#include "pch.h"
#include "GestorEscenario1.h"
#include "Artilugio.h"
#include "Ladron.h"

GestorEscenario1::GestorEscenario1(Guardia* guardia, int anchoLienzo, int altoLienzo, int enemigosTotales) :
	guardia(guardia), anchoLienzo(anchoLienzo), altoLienzo(altoLienzo), enemigosTotales(enemigosTotales)
{
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
	for (auto visitante : visitantes) visitante->mover(anchoLienzo, altoLienzo);
}
void GestorEscenario1::moverGuardia(Direccion direccion)
{
	guardia->mover(direccion, anchoLienzo, altoLienzo,1);
}
void GestorEscenario1::dibujar(Graphics^ g)
{
	guardia->dibujar(g);
	reportera->dibujar(g);
	for (auto ladron : ladrones) ladron->dibujar(g);
	for (auto visitante : visitantes) visitante->dibujar(g);
}

void GestorEscenario1::detectarColisiones()
{

}

void GestorEscenario1::jugar()
{
	if (temporizador == 100)
	{
		temporizador = 0;
		// int dx = (rand() % 2) * 2 - 1; // entre -1 y 1
		// int dy = 0;
		// int objetivo = rand() % 6;
		// int x = 0, y = 0;
		// if (dx == 1) { x = 0; y = (rand() % 2) * 8 + 18; } // y: te da o 18 o 26. 18 = linea 1, 26 = linea 2
		// else if (dx == -1) { x = 167; y = (rand() % 2) * 8 + 18; } //x: 175 (limite) - ancho del visitante | y: te da o 18 o 26. 18 = linea 1, 26 = linea 2
		// int op = rand() % 4;
		// if (op < 2)
		// {	
		// 	Ladron* nuevo = new Ladron(x, y, dx, dy, false, objetivo, rand() % 4 + 1, reportera->getTipoPista());
		// 	agregarLadron(nuevo);
		// }
		// else
		// {
		// 	Visitante* nuevo = new Visitante(x,y, dx, 0);
		// 	agregarVisitante(nuevo);
		// }
	}
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