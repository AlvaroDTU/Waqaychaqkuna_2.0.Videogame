#include "pch.h"
#include "GestorEscenario1.h"

GestorEscenario1::GestorEscenario1(Guardia* guardia, int anchoLienzo, int altoLienzo) :
	guardia(guardia), anchoLienzo(anchoLienzo), altoLienzo(altoLienzo)
{

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
	for (auto visitante : visitantes) visitante->mover(anchoLienzo,altoLienzo);
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