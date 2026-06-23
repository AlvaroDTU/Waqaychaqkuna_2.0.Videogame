#include "pch.h"
#include "GestorHuacas.h"
GestorHuacas::GestorHuacas(Guardia* guardia, int anchoLienzo, int altoLienzo)
{
	this->guardia = guardia;
	this->anchoLienzo = anchoLienzo;
	this->altoLienzo = altoLienzo;
}
GestorHuacas::~GestorHuacas(){
	for (auto cuidador : cuidadores) delete cuidador;
	cuidadores.clear();
	for (auto huaquero : huaqueros) delete huaquero;
	huaqueros.clear();

}
void GestorHuacas::mover(int x){
	for (auto huaquero : huaqueros) { huaquero->mover(anchoLienzo,altoLienzo); }

}
void GestorHuacas::dibujar(Graphics^ g){
	guardia->dibujar(g);
	for (auto huaquero : huaqueros) { huaquero->dibujar(g); }

}
void GestorHuacas::detectarColisiones() {

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
bool GestorHuacas::victoria() { return false; }

int GestorHuacas::getTotalHuaquero(){ return (int)huaqueros.size(); }

void GestorHuacas::agregarCuidador(Cuidador* c) { cuidadores.push_back(c); }
void GestorHuacas::agregarHuaquero(Huaquero* h) { huaqueros.push_back(h); }
void GestorHuacas::agregarBien(){}
void  GestorHuacas::eliminarCuidador(int i) { cuidadores.erase(cuidadores.begin() + i); }
void  GestorHuacas::eliminarHuaquero(int i) { huaqueros.erase(huaqueros.begin() + i); }

void GestorHuacas::jugar() {
	detectarColisiones();
	

}