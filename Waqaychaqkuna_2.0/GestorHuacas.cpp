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

	guardia = new Guardia(790, 170, 45, 60, 60, 80);

	
	agregarObjeto(new Objeto(0, 0, 180, 800));
	agregarObjeto(new Objeto(183, 0, 922, 127));
	agregarObjeto(new Objeto(183, 645, 922, 154));
	agregarObjeto(new Objeto(1010, 0, 192, 800));
	agregarObjeto(new Objeto(512, 459, 20, 52));
	agregarObjeto(new Objeto(738, 495, 21, 23));
	agregarObjeto(new Objeto(753, 278, 8, 37));
	agregarObjeto(new Objeto(779, 243, 23, 54));

	
	agregarBien(new Huaca(209, 129, 247, 157,2000,"Huaca del Sol"));
	agregarBien(new Huaca(854, 133, 266, 151,2069, "Huaca de la Luna"));
	agregarBien(new Huaca(210, 487, 246, 157,2679,"Huaca Dragon"));
	agregarBien(new Huaca(81, 493, 255, 151,3000,"Huaca Charly"));

}
void GestorHuacas::dibujar(Graphics^ g) {


}
void GestorHuacas::mover() {}
void GestorHuacas::detectarColisiones() {}

bool GestorHuacas::victoria() { return false; }
void GestorHuacas::jugar() {}

