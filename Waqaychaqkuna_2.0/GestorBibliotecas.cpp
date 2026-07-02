#include "pch.h"
#include "GestorBiblioteca.h"

GestorBiblioteca::GestorBiblioteca(int enTotal) : Escenario(enTotal)
{
	this->guardia = guardia;
	this->anchoLienzo = anchoLienzo;
	this->altoLienzo = altoLienzo;
	enemigosCapturados = 0;
}

GestorBiblioteca::~GestorBiblioteca(){
	Escenario::~Escenario();
}
void GestorBiblioteca::crearSprites(){
	fondo = new Fondo(3, anchoLienzo, altoLienzo);

	guardia = new Guardia(622, 674, 30, 40, 60, 80);

	agregarBien(new Archivo(320,203, 60, 324, 5000, "Archivo Caceres", false));
	agregarBien(new Archivo(524, 203, 60, 324, 4500, "Trad. peruanas", false));
	agregarBien(new Archivo(718, 203, 60, 324, 4000, "Juras de indep.", false));
	agregarBien(new Archivo(910, 203, 60, 324, 6000, "Archivo Courret", false));

	setearColisionesMapa();

}
void GestorBiblioteca::dibujar(Graphics^ g){

	fondo->dibujarFondo(g);
	for (auto manipulador : enemigos) manipulador->dibujar(g);
	guardia->dibujar(g);

}
void GestorBiblioteca::mover(){

	guardia->mover(objetos, bienes);

	for (size_t j = 0; j < (int)enemigos.size(); j++) {
		if (enemigos[j]->getAtacando() == false) { enemigos[j]->mover(anchoLienzo, altoLienzo); }
	}

}
void GestorBiblioteca::detectarColisiones(){

	Rectangle hbGuardia = guardia->getRectangle();

	for (int i = (int)enemigos.size() - 1; i >= 0; i--)
	{
		Rectangle hbLadron = enemigos[i]->getRectangle(1);
		if (hbLadron.IntersectsWith(hbGuardia))
		{
			if (guardia->getAccion() && guardia->getTipoAccion() != 1) {
				intentos--;
			}
		}
	}

	for (int i = 0; i < (int)enemigos.size(); i++)
	{
		for (int j = 0; j < (int)bienes.size(); j++)
		{
			Rectangle hitboxEnemigo = enemigos[i]->getRectangle();
			Rectangle hitboxBien = bienes[j]->getRectangle(5);
			if (hitboxEnemigo.IntersectsWith(hitboxBien) && enemigos[i]->getAtacando() && bienes[j]->estaActivo())
			{
				enemigos[i]->atacar(bienes[j]);
			}
		}
	}

}

bool GestorBiblioteca::victoria(){ return enemigosCapturados == enemigosTotales; }
bool GestorBiblioteca::derrota(){

	bool bienDestruido = false;
	for (auto bien : bienes)
	{
		if (bien->getPuntajeValor() <= 0) bienDestruido = true;
	}
	return intentos <= 0 || bienDestruido;
}

void GestorBiblioteca::jugar(){
	mover();
	tempSpawnEntidades--;
	if (tempSpawnEntidades == 0) {
		generarManipulador();
		tempSpawnEntidades = 10;
	}
}

void GestorBiblioteca::setearColisionesMapa(){
//escritorio
	agregarObjeto(new Objeto(572, 578, 36, 45));
	agregarObjeto(new Objeto(610, 599, 110, 23));
//plantas
	agregarObjeto(new Objeto(890, 627, 42, 40));
	agregarObjeto(new Objeto(1190, 561, 42, 40));
	agregarObjeto(new Objeto(1188, 304, 42, 40));
	agregarObjeto(new Objeto(885, 113, 42, 40));
	agregarObjeto(new Objeto(677, 113, 42, 40));
	agregarObjeto(new Objeto(581, 113, 42, 40));
	agregarObjeto(new Objeto(373, 113, 42, 40));
	agregarObjeto(new Objeto(72, 304, 42, 40));
	agregarObjeto(new Objeto(72, 561, 42, 40));
	agregarObjeto(new Objeto(367, 627, 42, 40));
	agregarObjeto(new Objeto(148, 607, 40, 38));
	agregarObjeto(new Objeto(1109, 607, 40, 38));
	//estantes
	agregarObjeto(new Objeto(80, 68, 118, 94));
	agregarObjeto(new Objeto(1102, 68, 118, 94));
	//cercas
	agregarObjeto(new Objeto(148, 638, 208, 46));
	agregarObjeto(new Objeto(942, 638, 208, 46));
	//varillas (?
	agregarObjeto(new Objeto(70, 200, 32, 68));
	agregarObjeto(new Objeto(1203, 200, 32, 68));
	agregarObjeto(new Objeto(77, 454, 26, 58));
	agregarObjeto(new Objeto(1195, 454, 26, 58));
	//mesitas
	agregarObjeto(new Objeto(162, 336, 39, 76));
	agregarObjeto(new Objeto(1091, 336, 39, 76));
	//bancos
	agregarObjeto(new Objeto(158, 160, 42, 45));
	agregarObjeto(new Objeto(1098, 160, 42, 45));
}

void GestorBiblioteca::generarManipulador(){
	int tipo = rand() % 4 + 1;

	if (tipo == 1) {
		Manipulador* nuevo = new Manipulador(305, 365, 30, 40, 60, 80, 0, 5, 1, 1);
		agregarEnemigo(nuevo);
	}
	else if (tipo == 2) {
		Manipulador* nuevo = new Manipulador(534, 365, 30, 40, 60, 80, 0, 5, 2, tipo);
		agregarEnemigo(nuevo);
	}
	else if (tipo == 3) {
		Manipulador* nuevo = new Manipulador(750, 365, 30, 40, 60, 80, 0, 5, 3, tipo);
		agregarEnemigo(nuevo);
	}
	else if (tipo == 4) {
		Manipulador* nuevo = new Manipulador(962, 365, 30, 40, 60, 80, 0, 5, 4, tipo);
		agregarEnemigo(nuevo);
	}
}

void GestorBiblioteca::recargaLinterna(){
	tiempoRecarga = 100.00;
}