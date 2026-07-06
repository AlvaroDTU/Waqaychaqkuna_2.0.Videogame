#include "pch.h"
#include "GestorHuacas.h"
#include "Cuidador.h"
GestorHuacas::GestorHuacas() : Escenario()
{
	int n1, n2, n3, gx1, gy1, gx2, gy2, gx3, gy3, bat;
	gestor->cargarTodo(n1, n2, n3, gx1, gy1, gx2, gy2, gx3, gy3, bat);

	enemigosTotales = n2;
	contador = 0;
	tempSpawnEntidades = 70;
}
GestorHuacas::~GestorHuacas() {
	Escenario::~Escenario();
}
void GestorHuacas::crearSprites() {
	fondo = new Fondo(2, anchoLienzo, altoLienzo);

	int n1, n2, n3, gx1, gy1, gx2, gy2, gx3, gy3, bat;
	gestor->cargarTodo(n1, n2, n3, gx1, gy1, gx2, gy2, gx3, gy3, bat);
	guardia = new Guardia(gx2, gy2, 30, 40, 60, 80);


	agregarObjeto(new Objeto(0, 0, 180, 800));
	agregarObjeto(new Objeto(183, 0, 922, 127));
	agregarObjeto(new Objeto(183, 645, 922, 154));
	agregarObjeto(new Objeto(1110, 0, 192, 800));
	agregarObjeto(new Objeto(512, 459, 20, 52));
	agregarObjeto(new Objeto(524, 232, 25, 56));
	agregarObjeto(new Objeto(738, 495, 21, 23));
	agregarObjeto(new Objeto(753, 278, 8, 37));
	agregarObjeto(new Objeto(779, 243, 23, 54));

	agregarBien(new Huaca(177, 109, 300, 194, 2000, "HUACA DEL SOL", 1));
	agregarBien(new Huaca(817, 108, 299, 188, 2069, "HUACA DE LA LUNA", 2));
	agregarBien(new Huaca(202, 482, 266, 177, 2679, "HUACA DRAGON", 3));
	agregarBien(new Huaca(801, 474, 309, 200, 3000, "HUACA TAKAYNAMO", 4));

}
void GestorHuacas::dibujar(Graphics^ g) {
	fondo->dibujarFondo(g, escalaX, escalaY);
	for (size_t i = 0; i < (int)bienes.size(); i++)
	{
		if (bienes[i]->getPuntajeValor() < 1505)
			bienes[i]->dibujar(g, escalaX, escalaY);
	}
	for (auto huaquero : enemigos) huaquero->dibujar(g, escalaX, escalaY);
	for (auto cuidador : aliados) cuidador->dibujar(g, escalaX, escalaY);

	guardia->dibujar(g, escalaX, escalaY);

}
void GestorHuacas::mover() {
	guardia->mover(objetos, bienes);

	for (auto cuidador : aliados) ((Cuidador*)cuidador)->sinMover();
	for (size_t j = 0; j < (int)enemigos.size(); j++) {
		if (enemigos[j]->getAtacando() == false) { enemigos[j]->mover(anchoLienzo, altoLienzo); }
	}
}
void GestorHuacas::detectarColisiones() {

	Rectangle htbGuardia = guardia->getRectangle();

	for (size_t i = 0; i < (int)bienes.size(); i++)
	{
		Rectangle r = bienes[i]->getRectangle(5);
		if (htbGuardia.IntersectsWith(r)) {
			if (guardia->getAccion() && guardia->getTipoAccion() == 2) {
				bienes[i]->setColision(!bienes[i]->getColision());
				guardia->setAccion(false);
				guardia->setTipoAccion(0);
			}
		}
		else
			bienes[i]->setColision(false);
	}

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
	for (size_t i = 0; i < (int)aliados.size(); i++)
	{
		Rectangle htbAliado = aliados[i]->getRectangle();
		bool ayudando = false;

		for (size_t j = 0; j < enemigos.size(); j++)
		{
			Rectangle htbEnemigo = enemigos[j]->getRectangle();

			if (htbAliado.IntersectsWith(htbEnemigo))
			{
				ayudando = true;

				((Huaquero*)enemigos[j])->RestarVidas(1);
				((Cuidador*)aliados[i])->RestarDuracion(1);
				break;   // ya encontró un enemigo
			}
		}

		((Cuidador*)aliados[i])->setAyudando(ayudando);
	}


	for (size_t i = 0; i < (int)enemigos.size(); i++)
	{
		if (((Huaquero*)enemigos[i])->getVidas() <= 0) {
			eliminarEnemigo(i);
			//SUMA PUNTAJE
			puntajeNivel += 10;
			enemigosCapturados++;
			i--;
		}
	}
	for (size_t i = 0; i < (int)aliados.size(); i++)
	{
		if (((Cuidador*)aliados[i])->getDuracion() <= 0) {
			eliminarAliado(i);
			i--;
		}
	}

}

bool GestorHuacas::victoria() { return enemigosCapturados == enemigosTotales; }
bool GestorHuacas::derrota() {
	bool bienDestruido = false;
	for (auto bien : bienes)
	{
		if (bien->getPuntajeValor() <= 0) bienDestruido = true;
	}
	return bienDestruido;
}

void GestorHuacas::jugar() {
	mover();
	tempSpawnEntidades--;
	if (tempSpawnEntidades == 0 && (contador != enemigosTotales)) {
		generarHuaquero();
		tempSpawnEntidades = 100;
		contador++;
	}
}

void GestorHuacas::generarHuaquero() {
	int tipo = rand() % 16 + 1;
	//Derecha
	if (tipo == 1) {
		Huaquero* nuevo = new Huaquero(0, 365, 30, 40, 60, 80, 5, 0, 1, 1);
		agregarEnemigo(nuevo);
	}
	else if (tipo == 2) {
		Huaquero* nuevo = new Huaquero(0, 365, 30, 40, 60, 80, 5, 0, 2, tipo);
		agregarEnemigo(nuevo);
	}
	else if (tipo == 3) {
		Huaquero* nuevo = new Huaquero(0, 365, 30, 40, 60, 80, 5, 0, 3, tipo);
		agregarEnemigo(nuevo);
	}
	else if (tipo == 4) {
		Huaquero* nuevo = new Huaquero(0, 365, 30, 40, 60, 80, 5, 0, 4, tipo);
		agregarEnemigo(nuevo);
	}

	// Izqueirda
	else if (tipo == 5) {
		Huaquero* nuevo = new Huaquero(1270, 365, 30, 40, 60, 80, -5, 0, 1, tipo);
		agregarEnemigo(nuevo);
	}
	else if (tipo == 6) {
		Huaquero* nuevo = new Huaquero(1270, 365, 30, 40, 60, 80, -5, 0, 2, tipo);
		agregarEnemigo(nuevo);
	}
	else if (tipo == 7) {
		Huaquero* nuevo = new Huaquero(1270, 365, 30, 40, 60, 80, -5, 0, 3, tipo);
		agregarEnemigo(nuevo);
	}
	else if (tipo == 8) {
		Huaquero* nuevo = new Huaquero(1270, 365, 30, 40, 60, 80, -5, 0, 4, tipo);
		agregarEnemigo(nuevo);
	}

	// Arriba
	else if (tipo == 9) {
		Huaquero* nuevo = new Huaquero(634, 0, 30, 40, 60, 80, 0, 5, 1, tipo);
		agregarEnemigo(nuevo);
	}
	else if (tipo == 10) {
		Huaquero* nuevo = new Huaquero(634, 0, 30, 40, 60, 80, 0, 5, 2, tipo);
		agregarEnemigo(nuevo);
	}
	else if (tipo == 11) {
		Huaquero* nuevo = new Huaquero(634, 0, 30, 40, 60, 80, 0, 5, 3, tipo);
		agregarEnemigo(nuevo);
	}
	else if (tipo == 12) {
		Huaquero* nuevo = new Huaquero(634, 0, 30, 40, 60, 80, 0, 5, 4, tipo);
		agregarEnemigo(nuevo);
	}

	// Abajo
	else if (tipo == 13) {
		Huaquero* nuevo = new Huaquero(634, 760, 30, 40, 60, 80, 0, -5, 1, tipo);
		agregarEnemigo(nuevo);
	}
	else if (tipo == 14) {
		Huaquero* nuevo = new Huaquero(634, 760, 30, 40, 60, 80, 0, -5, 2, tipo);
		agregarEnemigo(nuevo);
	}
	else if (tipo == 15) {
		Huaquero* nuevo = new Huaquero(634, 760, 30, 40, 60, 80, 0, -5, 3, tipo);
		agregarEnemigo(nuevo);
	}
	else if (tipo == 16) {
		Huaquero* nuevo = new Huaquero(634, 760, 30, 40, 60, 80, 0, -5, 4, tipo);
		agregarEnemigo(nuevo);
	}
}
void GestorHuacas::generarCuidador() {

	int dx = guardia->getDirX();
	int dy = guardia->getDirY();

	int x, y;

	if (dx > 0) x = guardia->getPosX() + 40;
	else if (dx < 0) x = guardia->getPosX() - 40;
	else x = guardia->getPosX();

	if (dy > 0) y = guardia->getPosY() + 40;
	else if (dy < 0) y = guardia->getPosY() - 40;
	else y = guardia->getPosY();

	Rectangle rCuidador(x, y, 30, 40);   // tamaño del sprite

	bool colisionHuaca = false;

	for (auto bien : bienes)
	{
		Rectangle rHuaca = bien->getRectangle();

		if (rCuidador.IntersectsWith(rHuaca))
		{
			colisionHuaca = true;
			break;
		}
	}

	if (!colisionHuaca)
	{
		Cuidador* nuevo = new Cuidador(x, y, 30, 40, 60, 80);
		agregarAliado(nuevo);
	}
}
