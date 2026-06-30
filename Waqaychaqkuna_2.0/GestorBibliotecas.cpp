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

	guardia = new Guardia(890, 1322, 45, 60, 60, 80);

	agregarBien(new Archivo(316,200, 60, 330, 5000, "Archivo Caceres", false));
	agregarBien(new Archivo(552, 200, 60, 330, 4500, "Trad. peruanas", false));
	agregarBien(new Archivo(718, 200, 60, 330, 4000, "Juras de indep.", false));
	agregarBien(new Archivo(908, 200, 60, 330, 6000, "Archivo Courret", false));

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
			if (guardia->getAccion() && guardia->getTipoAccion() == 1) {
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
		tempSpawnEntidades = 70;
	}
}

void GestorBiblioteca::setearColisionesMapa(){
	


}

void GestorBiblioteca::generarManipulador(){
	int tipo = rand() % 4 + 1;
	//Derecha
	if (tipo == 1) {
		Manipulador* nuevo = new Manipulador(0, 365, 30, 40, 60, 80, 5, 0, 1, 1);
		agregarEnemigo(nuevo);
	}
	else if (tipo == 2) {
		Manipulador* nuevo = new Manipulador(0, 365, 30, 40, 60, 80, 5, 0, 2, tipo);
		agregarEnemigo(nuevo);
	}
	else if (tipo == 3) {
		Manipulador* nuevo = new Manipulador(0, 365, 30, 40, 60, 80, 5, 0, 3, tipo);
		agregarEnemigo(nuevo);
	}
	else if (tipo == 4) {
		Manipulador* nuevo = new Manipulador(0, 365, 30, 40, 60, 80, 5, 0, 4, tipo);
		agregarEnemigo(nuevo);
	}
}

void GestorBiblioteca::recargaLinterna(){
	tiempoRecarga = 100.00;
}