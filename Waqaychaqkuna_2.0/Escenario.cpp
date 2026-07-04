#include "pch.h"
#include "Escenario.h"

Escenario::Escenario(int enTotales)
	: fondo(nullptr), guardia(nullptr), anchoLienzo(1300), altoLienzo(800), enemigosTotales(enTotales)
{
	srand(time(nullptr));
	enemigosCapturados = 0;
	tempSpawnEntidades = 0;
	escalaX = 1.0f;
	escalaY = 1.0f;
}

Escenario::~Escenario()
{
	if (fondo)
	{
		delete fondo;
		fondo = nullptr;
	}
	if (guardia)
	{
		delete guardia;
		guardia = nullptr;
	}
	for (auto enemigo : enemigos) delete enemigo;
	enemigos.clear();
	for (auto aliado : aliados) delete aliado;
	aliados.clear();
	for (auto bien : bienes) delete bien;
	bienes.clear();
}

void Escenario::setLienzo(int ancho, int alto)
{
	anchoLienzo = ancho;
	altoLienzo = alto;
}

void Escenario::agregarEnemigo(Enemigo* nuevo) { enemigos.push_back(nuevo); }
void Escenario::agregarAliado(Aliado* nuevo) { aliados.push_back(nuevo); }
void Escenario::agregarBien(Bien* nuevo) { bienes.push_back(nuevo); }
void Escenario::agregarObjeto(Objeto* nuevo) { objetos.push_back(nuevo); }

void Escenario::eliminarEnemigo(int i) { delete enemigos[i]; enemigos.erase(enemigos.begin() + i); }
void Escenario::eliminarAliado(int i) { aliados.erase(aliados.begin() + i); }

int Escenario::totalEnemigos() { return (int)enemigos.size(); }
int Escenario::totalAliados() { return (int)aliados.size(); }
int Escenario::totalBienes() { return (int)bienes.size(); }

Guardia* Escenario::getGuardia() { return guardia; }
Bien* Escenario::getBien(int i) {
	return bienes[i];
}

Dialogo* Escenario::getDialogo() { return &dialogo;}

void Escenario::setEscalado(float eX, float eY) 
{
	escalaX = eX;
	escalaY = eY;
}