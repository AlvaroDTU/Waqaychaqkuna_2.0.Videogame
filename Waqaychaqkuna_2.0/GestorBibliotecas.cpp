#include "pch.h"
#include "GestorBiblioteca.h"

GestorBiblioteca::GestorBiblioteca(int enTotal) : Escenario(enTotal)
{
	enemigosCapturados = 0;
	this->tiempoRecarga = 100.00;
	tempSpawnEntidades = 70;
	vidas = 20;
}

GestorBiblioteca::~GestorBiblioteca(){
	Escenario::~Escenario();
}
void GestorBiblioteca::crearSprites(){

	fondo = new Fondo(3, anchoLienzo, altoLienzo);

	guardia = new Guardia(622, 674, 30, 40, 60, 80);
	
	agregarAliado(new Murcielago(131, 541, 40, 30, 40, 24));

	agregarBien(new Archivo(320,203, 60, 320, 5000, "Archivo Caceres", false));
	agregarBien(new Archivo(524, 203, 60, 320, 4500, "Trad. peruanas", false));
	agregarBien(new Archivo(718, 203, 60, 320, 4000, "Juras de indep.", false));
	agregarBien(new Archivo(910, 203, 60, 320, 6000, "Archivo Courret", false));

	setearColisionesMapa();

}
void GestorBiblioteca::dibujar(Graphics^ g){

	fondo->dibujarFondo(g);
	for (auto manipulador : enemigos) manipulador->dibujar(g);
	for (auto murcielago : aliados)
		murcielago->dibujar(g);

	if (encenderLinterna()){ linterna->dibujar(g); }
	guardia->dibujar(g);

}
void GestorBiblioteca::mover(){

	guardia->mover(objetos, bienes);
	aliados[0]->mover(anchoLienzo, altoLienzo);
	for (size_t j = 0; j < (int)enemigos.size(); j++) {
		if (enemigos[j]->getAtacando() == false) { enemigos[j]->mover(anchoLienzo, altoLienzo); }
	}

}
void GestorBiblioteca::detectarColisiones(){

	Rectangle hbGuardia = guardia->getRectangle();
	Rectangle hbLinterna = linterna->getRectangle();
	//colision guardia y enemigos
	for (int i = (int)enemigos.size() - 1; i >= 0; i--)
	{
		Rectangle hbLadron = enemigos[i]->getRectangle(1);
		if (hbLadron.IntersectsWith(hbGuardia))	{ vidas = vidas - 0.2; }
		else vidas = 0;
	}
	//colision enemigos y bienes
	for (size_t i = 0; i < (int)bienes.size(); i++)
	{
		Rectangle htbBien = bienes[i]->getRectangle();
		for (size_t j = 0; j < (int)enemigos.size(); j++)
		{
			Rectangle htbEnemigo = enemigos[j]->getRectangle();
			if (htbBien.IntersectsWith(htbEnemigo)) {
				enemigos[j]->setMoviendose(false);
				enemigos[j]->setColumna(0);
				enemigos[j]->setAtacando(true);
				bienes[i]->restarPuntajeValor(1);
			}
		}
	}
	//colision enemigos y linterna
	for (int i = (int)enemigos.size() - 1; i >= 0; i--)
	{
		Rectangle hbLadron = enemigos[i]->getRectangle(1);
		if (hbLadron.IntersectsWith(hbLinterna) && linterna->getEncendida() == true) { eliminarEnemigo(i); }
	}

}

bool GestorBiblioteca::victoria(){ return enemigosCapturados == enemigosTotales; }
bool GestorBiblioteca::derrota(){

	bool bienDestruido = false;
	for (auto bien : bienes)
	{
		if (bien->getPuntajeValor() <= 0) {bienDestruido = true; return bienDestruido;}
	}
	if (vidas <= 0) return true;

}

void GestorBiblioteca::jugar(){
	mover();
	recargaLinterna();
	tempSpawnEntidades--;
	if (tempSpawnEntidades == 0) {
		generarManipulador();
		tempSpawnEntidades = 120;
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
	//bordes
	agregarObjeto(new Objeto(27, 24, 33, 684));
	agregarObjeto(new Objeto(1238, 24, 33, 684));
	agregarObjeto(new Objeto(28, 691, 490, 18));
	agregarObjeto(new Objeto(779, 691, 490, 18));
	agregarObjeto(new Objeto(486, 720, 327, 33));
	agregarObjeto(new Objeto(198, 95, 809, 20));
}

void GestorBiblioteca::generarManipulador(){
	int tipo = rand() % 4 + 1;

	if (tipo == 1) {
		Manipulador* nuevo = new Manipulador(305, 64, 30, 40, 60, 80, 0, 5, 1, 1, false);
		agregarEnemigo(nuevo);
	}
	else if (tipo == 2) {
		Manipulador* nuevo = new Manipulador(534, 64, 30, 40, 60, 80, 0, 5, 2, tipo, false);
		agregarEnemigo(nuevo);
	}
	else if (tipo == 3) {
		Manipulador* nuevo = new Manipulador(750, 64, 30, 40, 60, 80, 0, 5, 3, tipo, false);
		agregarEnemigo(nuevo);
	}
	else if (tipo == 4) {
		Manipulador* nuevo = new Manipulador(962, 64, 30, 40, 60, 80, 0, 5, 4, tipo, false);
		agregarEnemigo(nuevo);
	}
}
void GestorBiblioteca::recargaLinterna(){

	Rectangle g = guardia->getRectangle();
	Rectangle m = aliados[0]->getRectangle();

	if (g.IntersectsWith(m)){

		tiempoRecarga = 100.00;
		aliados[0]->setColumna(2);
	}

	if (tiempoRecarga <= 0) tiempoRecarga = 0;

	else tiempoRecarga = tiempoRecarga - 0.4;
}

double GestorBiblioteca::getTiempoRecarga() {
	return tiempoRecarga;
}

double GestorBiblioteca::getVidas() {
	return vidas;
}

bool GestorBiblioteca::encenderLinterna() {
	if (guardia->getAccion() && guardia->getTipoAccion() == 1) {
		int lx = guardia->getPosX();
		int ly = guardia->getPosY() + 114;
		linterna->setEncencida(true);
		linterna->setPos(lx, ly);
		return true;
	}
	else return false;
}