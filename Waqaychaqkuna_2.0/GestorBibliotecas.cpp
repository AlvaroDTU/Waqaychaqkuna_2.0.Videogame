#include "pch.h"
#include "GestorBiblioteca.h"

GestorBiblioteca::GestorBiblioteca(Guardia* guardia, int anchoLienzo, int altoLienzo, int enemigosTotales) :
	guardia(guardia), anchoLienzo(anchoLienzo), altoLienzo(altoLienzo), enemigosTotales(enemigosTotales)
{
	//FALTA MODIFICAR POSICIONES Y TAMAÑO
	archivos.push_back(new Archivo(24, 7, 40, 200, 5000, "Archivo Caceres", false));
	archivos.push_back(new Archivo(53, 7, 40, 200, 4500, "Trad. peruanas", false));
	archivos.push_back(new Archivo(111, 7, 40, 200, 4000, "Juras de indep.", false));
	archivos.push_back(new Archivo(82, 7, 40, 200, 6000, "Archivo Courret", false));
	archivos.push_back(new Archivo(140, 7, 40, 200, 3000, "Manuscrito Inca", false));

	this->guardia = guardia;
	this->anchoLienzo = anchoLienzo;
	this->altoLienzo = altoLienzo;
	enemigosDerrotados = 0;
	temporizador = 0;

}

GestorBiblioteca::~GestorBiblioteca(){
	for (auto manipulador : manipuladores) { delete manipulador; manipuladores.clear(); }
}

void GestorBiblioteca::mover(){
	for (auto manipulador : manipuladores) manipulador->mover(anchoLienzo, altoLienzo);
}

void GestorBiblioteca::moverGuardia(Direccion direccion) {
	guardia->mover(direccion, anchoLienzo, altoLienzo, 1);
}

void GestorBiblioteca::dibujar(Graphics^ g){
	guardia->dibujar(g);
	for (auto manipulador : manipuladores) { manipulador->dibujar(g); }
}
void GestorBiblioteca::detectarColisiones(){
	Rectangle hitboxGuardia = guardia->getRectangle(2);

	//Logica de la linterna pendiente




	//Colision del guardia y los manipuladores de yapa
	for (size_t i = 0; i < manipuladores.size(); i++)
	{
		System::Drawing::Rectangle hitboxEnemigo = manipuladores[i]->getRectangle(1);
		if (hitboxEnemigo.IntersectsWith(hitboxGuardia)) {

			enemigosDerrotados++;
			eliminarManipulador(i);
			i--;
		}
	}

}

bool GestorBiblioteca::victoria(){ return false; }

int GestorBiblioteca::getTotalManipulador(){return (int)manipuladores.size(); }

void GestorBiblioteca::jugar(){
	detectarColisiones();


}

void GestorBiblioteca::agregarManipulador(Manipulador* nuevo){manipuladores.push_back(nuevo);
}

void GestorBiblioteca::eliminarManipulador(int i){manipuladores.erase(manipuladores.begin()+i); }

void GestorBiblioteca::recargaLinterna(){}