#include "pch.h"
#include "GestorEscenario2.h"
GestorEscenario2::GestorEscenario2(Guardia* guardia, int anchoLienzo, int altoLienzo)
{
	this->guardia = guardia;
	this->anchoLienzo = anchoLienzo;
	this->altoLienzo = altoLienzo;
}
GestorEscenario2::~GestorEscenario2(){
	for (auto cuidador : cuidadores) delete cuidador;
	cuidadores.clear();
	for (auto huaquero : huaqueros) delete huaquero;
	huaqueros.clear();

}
void GestorEscenario2::mover(int x){
	if (x==1) {guardia->mover(Direccion::Abajo,anchoLienzo,altoLienzo,2);}
	else if (x==2) {guardia->mover(Direccion::Arriba,anchoLienzo,altoLienzo,2);}
	else if (x==3) {guardia->mover(Direccion::Izquierda,anchoLienzo,altoLienzo,2);}
	else if (x==4) {guardia->mover(Direccion::Derecha,anchoLienzo,altoLienzo,2);}

	for (auto huaquero : huaqueros) { huaquero->mover(anchoLienzo,altoLienzo); }

}
void GestorEscenario2::dibujar(Graphics^ g){
	guardia->dibujar(g);
	for (auto huaquero : huaqueros) { huaquero->dibujar(g); }

}
void GestorEscenario2::detectarColisiones(){}
bool GestorEscenario2::victoria() { return false; }
int GestorEscenario2::getTotalHuaquero() { return (int)huaqueros.size(); }

void GestorEscenario2::agregarCuidador(Cuidador* c){}
void GestorEscenario2::agregarHuaquero(Huaquero* h){}
void GestorEscenario2::agregarBien(){}
void  GestorEscenario2::eliminarCuidador(){}
void  GestorEscenario2::eliminarHuaquero() {}

void GestorEscenario2::jugar() {}