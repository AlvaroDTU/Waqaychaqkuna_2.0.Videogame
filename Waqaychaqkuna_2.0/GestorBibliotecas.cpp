#include "pch.h"
#include "GestorBiblioteca.h"

GestorBiblioteca::GestorBiblioteca() : Escenario()
{
	int n1, n2, n3, gx, gy, bat;
	gestor->cargarTodo(n1, n2, n3, gx, gy, bat);

	enemigosTotales = n3;
	contador = 0;
	this->tiempoRecarga = bat;
	tempSpawnEntidades = 80;
	vidas = 20;
	linterna = nullptr;
}

GestorBiblioteca::~GestorBiblioteca(){
	Escenario::~Escenario();
}
void GestorBiblioteca::crearSprites(){

	fondo = new Fondo(3, anchoLienzo, altoLienzo);

	linterna = new Linterna(false);

	int n1, n2, n3, gx=1, gy=1, bat;
	gestor->cargarTodo(n1, n2, n3, gx, gy, bat);

	guardia = new Guardia(gx, gy, 30, 40, 60, 80);

	agregarAliado(new Murcielago(131, 541, 40, 30, 40, 24));

	agregarBien(new Archivo(320,203, 60, 320, 4000, "Archivo Caceres", false,  1));
	agregarBien(new Archivo(524, 203, 60, 320, 4500, "Trad. peruanas", false, 2));
	agregarBien(new Archivo(718, 203, 60, 320, 5000, "Juras de indep.", false, 3));
	agregarBien(new Archivo(910, 203, 60, 320, 4000, "Archivo Courret", false, 4));

	setearColisionesMapa();

}
void GestorBiblioteca::dibujar(Graphics^ g){
	fondo->dibujarFondo(g, escalaX, escalaY);
	dibujarLibros(g,escalaX, escalaY);
	guardia->dibujar(g, escalaX, escalaY);
	for (auto manipulador : enemigos) manipulador->dibujar(g,escalaX, escalaY);
	for (auto murcielago : aliados)
		murcielago->dibujar(g, escalaX, escalaY);

	if (linterna->getEncendida())
		linterna->dibujar(g, escalaX, escalaY);

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
	//colision guardia y enemigos
	for (int i = (int)enemigos.size() - 1; i >= 0; i--)
	{
		Rectangle hbLadron = enemigos[i]->getRectangle(1);
		if (hbLadron.IntersectsWith(hbGuardia))	{ vidas = vidas - 0.2; }

	}
	//colision guardia y bienes
	for (size_t i = 0; i < (int)bienes.size(); i++)
	{
		Rectangle htbBien = bienes[i]->getRectangle();
		for (size_t j = 0; j < (int)enemigos.size(); j++)
		{
			if (htbBien.IntersectsWith(hbGuardia)) {
				
			}
		}
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
	if (linterna != nullptr && linterna->getEncendida())
	{
		Rectangle hbLinterna = linterna->getRectangle();

		for (int i = enemigos.size() - 1; i >= 0; i--)
		{
			Rectangle hbLadron = enemigos[i]->getRectangle();

			if (hbLadron.IntersectsWith(hbLinterna))
			{
				eliminarEnemigo(i);
				enemigosCapturados++;
				//SUMA PUNTAJE

				puntajeNivel += 10;
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
	return vidas <= 0 || bienDestruido;

}

void GestorBiblioteca::jugar(){
	mover();
	encenderLinterna();
	recargaLinterna();
	tempSpawnEntidades--;
	if (tempSpawnEntidades == 0 && (contador != enemigosTotales)) {
		generarManipulador();
		tempSpawnEntidades = 40;
		contador++;
	}
}

void GestorBiblioteca::setearColisionesMapa(){
//escritorio
	agregarObjeto(new Objeto(570, 578, 36, 43));
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
	agregarObjeto(new Objeto(198, 95, 893, 20));
}

void GestorBiblioteca::generarManipulador(){
	int tipo = rand() % 4 + 1;

	if (tipo == 1) {
		Manipulador* nuevo = new Manipulador(305, 64, 30, 40, 60, 80, 0, 7, 1, 1, false);
		agregarEnemigo(nuevo);
	}
	else if (tipo == 2) {
		Manipulador* nuevo = new Manipulador(534, 64, 30, 40, 60, 80, 0, 7, 2, tipo, false);
		agregarEnemigo(nuevo);
	}
	else if (tipo == 3) {
		Manipulador* nuevo = new Manipulador(750, 64, 30, 40, 60, 80, 0, 7, 3, tipo, false);
		agregarEnemigo(nuevo);
	}
	else if (tipo == 4) {
		Manipulador* nuevo = new Manipulador(962, 64, 30, 40, 60, 80, 0, 7, 4, tipo, false);
		agregarEnemigo(nuevo);
	}
}
void GestorBiblioteca::recargaLinterna(){

	Rectangle g = guardia->getRectangle();
	Rectangle m = aliados[0]->getRectangle();

	if (g.IntersectsWith(m)&& guardia->getAccion() && guardia->getTipoAccion() == 1){

		tiempoRecarga = 100.00;
		aliados[0]->setColumna(2);
	}

	if (tiempoRecarga <= 0) tiempoRecarga = 0;

	else tiempoRecarga = tiempoRecarga - 0.3;
}

double GestorBiblioteca::getTiempoRecarga() {
	return tiempoRecarga;
}

double GestorBiblioteca::getVidas() {
	return vidas;
}

bool GestorBiblioteca::encenderLinterna() {

	if (guardia->getAccion() && guardia->getTipoAccion() == 1 && tiempoRecarga >=1)
	{	

		int direccion = guardia->getFila();

		if (direccion == 3){
			linterna->setEncendida(true);
			linterna->setColumna(0);
			int lx = guardia->getPosX() - 21;
			int ly = guardia->getPosY() - linterna->getAlto();

			linterna->setPos(lx, ly);
		}

		else if (direccion == 0) {
			linterna->setEncendida(true);
			linterna->setColumna(1);
			int lx = guardia->getPosX() - 22;
			int ly = guardia->getPosY() + guardia->getAlto()-4;

			linterna->setPos(lx, ly);
		}
		else { linterna->setEncendida(false); }

		return true;
	}
	else
	{
		linterna->setEncendida(false);
		return false;
	}
}

void GestorBiblioteca::dibujarLibros(Graphics^ g , float escalaX, float escalaY) {
	
	for (size_t i = 0; i < (int)bienes.size(); i++)
	{
		Rectangle htbBien = bienes[i]->getRectangle();
		for (size_t j = 0; j < (int)enemigos.size(); j++)
		{
			Rectangle htbEnemigo = enemigos[j]->getRectangle();
			if (htbBien.IntersectsWith(htbEnemigo) && bienes[i]->getPuntajeValor() <=2005) {
				int x = enemigos[i]->getPosX() - 20;
				int y = enemigos[i]->getPosY();
				int ancho = 44;
				int alto = 22;

				Bitmap^ img = Recursos::libros;
				g->DrawImage(img, x* escalaX, y * escalaY, ancho * escalaX, alto * escalaY);
			}
		}
	}
}