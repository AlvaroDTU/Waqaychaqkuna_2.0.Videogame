#include "pch.h"
#include "GestorHuacas.h"
GestorHuacas::GestorHuacas(int enTotales) : Escenario(enTotales)
{
	tempSpawnEntidades = 70;
}
GestorHuacas::~GestorHuacas() {
	Escenario::~Escenario();
}
void GestorHuacas::crearSprites() {
	fondo = new Fondo(2, anchoLienzo, altoLienzo);

	guardia = new Guardia(790, 170, 30, 40, 60, 80);

	
	agregarObjeto(new Objeto(0, 0, 180, 800));
	agregarObjeto(new Objeto(183, 0, 922, 127));
	agregarObjeto(new Objeto(183, 645, 922, 154));
	agregarObjeto(new Objeto(1110, 0, 192, 800));
	agregarObjeto(new Objeto(512, 459, 20, 52));
	agregarObjeto(new Objeto(524, 232, 25, 56));
	agregarObjeto(new Objeto(738, 495, 21, 23));
	agregarObjeto(new Objeto(753, 278, 8, 37));
	agregarObjeto(new Objeto(779, 243, 23, 54));

	
	agregarBien(new Huaca(209, 129, 247, 157,2000,"Huaca del Sol"));
	agregarBien(new Huaca(854, 133, 266, 151,2069, "Huaca de la Luna"));
	agregarBien(new Huaca(210, 487, 246, 157,2679,"Huaca Dragon"));
	agregarBien(new Huaca(813, 493, 255, 151,3000,"Huaca Charly"));

}
void GestorHuacas::dibujar(Graphics^ g) {
	fondo->dibujarFondo(g);

	for (auto huaquero : enemigos) huaquero->dibujar(g);
	for (auto cuidador : aliados) cuidador->dibujar(g);

	guardia->dibujar(g);

}
void GestorHuacas::mover() {
	guardia->mover(objetos, bienes);

	for (auto cuidador : aliados) ((Cuidador*) cuidador)->sinMover();
	for (auto ladron : enemigos) ladron->mover(anchoLienzo, altoLienzo);
	
}
void GestorHuacas::detectarColisiones() {}

bool GestorHuacas::victoria() { return false; }
void GestorHuacas::jugar() {
	mover();
	tempSpawnEntidades--;
	if (tempSpawnEntidades == 0) {
		generarHuaquero();
		tempSpawnEntidades = 70;
	}
}

void GestorHuacas::generarHuaquero() {
	int tipo = rand() % 16 + 1;
	//Derecha
	 if (tipo == 1) {
		Huaquero* nuevo = new Huaquero(0, 365, 30, 40, 60, 80, 5,0,1,1);
		agregarEnemigo(nuevo);
	}
	else if (tipo == 2) {
		Huaquero* nuevo = new Huaquero(0, 365, 30, 40, 60, 80, 5, 0,2, tipo);
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
		Huaquero* nuevo = new Huaquero(634, 0, 30, 40, 60, 80, 0,5, 2, tipo);
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
	} else if (tipo == 14) {
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
