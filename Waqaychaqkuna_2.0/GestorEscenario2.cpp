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
void GestorEscenario2::detectarColisiones() {

	Rectangle hitboxGuardia = guardia->getRectangle(2);

	for (size_t i = 0; i < cuidadores.size(); i++)
	{
		for (size_t j = 0; j < huaqueros.size(); j++)
		{
			System::Drawing::Rectangle hitboxCuidador = cuidadores[i]->getRectangle(1);
			System::Drawing::Rectangle hitboxHuaquero = huaqueros[j]->getRectangle(1);
			if (hitboxHuaquero.IntersectsWith(hitboxCuidador)) {
				((Huaquero*)huaqueros[j])->RestarVidas(1); //cuidador.ayudar pero no lo pusimos xd
				((Cuidador*)cuidadores[i])->RestarDuracion(1);

				if (((Huaquero*)huaqueros[j])->getVidas() <= 0)
				{
					eliminarHuaquero(j);
					j--;
					enemigosDerrotados++;
				}
				if (((Cuidador*)huaqueros[i])->getDuracion() <= 0)
				{
					
					eliminarCuidador(i);
					i--;
				}
			}
		}
	}


	// Colisiones de Guardia con ENEMMGIOS
	for (size_t i = 0; i < huaqueros.size(); i++)
	{
		System::Drawing::Rectangle hitboxEnemigo = huaqueros[i]->getRectangle(1);
		if (hitboxEnemigo.IntersectsWith(hitboxGuardia)) {

			enemigosDerrotados++;
			eliminarHuaquero(i);
			i--;
		}
	}

}
bool GestorEscenario2::victoria() {
	return false;}

int GestorEscenario2::getTotalHuaquero(){
	return (int)huaqueros.size();
}

void GestorEscenario2::agregarCuidador(Cuidador* c) { cuidadores.push_back(c); }
void GestorEscenario2::agregarHuaquero(Huaquero* h) { huaqueros.push_back(h); }
void GestorEscenario2::agregarBien(){}
void  GestorEscenario2::eliminarCuidador(int i) { cuidadores.erase(cuidadores.begin() + i); }
void  GestorEscenario2::eliminarHuaquero(int i) { huaqueros.erase(huaqueros.begin() + i); }

void GestorEscenario2::jugar() {
	detectarColisiones();
	

}