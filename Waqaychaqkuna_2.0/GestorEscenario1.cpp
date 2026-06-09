#include "pch.h"
#include "GestorEscenario1.h"
#include "Artilugio.h"
#include "Reportera.h"

GestorEscenario1::GestorEscenario1(Guardia* guardia, int anchoLienzo, int altoLienzo) :
	guardia(guardia), anchoLienzo(anchoLienzo), altoLienzo(altoLienzo)
{
	temporizador = 15;
	artilugios.push_back(new Artilugio(153, 50, 230, 50, 800, "Cabeza Clava"));
	artilugios.push_back(new Artilugio(535, 50, 230, 50, 1000, "Telar"));
	artilugios.push_back(new Artilugio(917, 50, 230, 50, 2000, "Craneo"));
	artilugios.push_back(new Artilugio(153, 600, 230, 50, 3000, "Huaco"));
	artilugios.push_back(new Artilugio(535, 600, 230, 50, 5000, "Tumi Dorado"));
	artilugios.push_back(new Artilugio(917, 600, 230, 50, 2500, "Vaso Kero"));
	reportera = new Reportera(40, 120, 0, 0, false, rand() % 4 + 1);
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
	guardia->mover(direccion, anchoLienzo, altoLienzo);
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