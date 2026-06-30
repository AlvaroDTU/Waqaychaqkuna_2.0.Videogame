#include "pch.h"
#include "GestorBiblioteca.h"

GestorBiblioteca::GestorBiblioteca(int enTotal) : Escenario(enTotal)
{
	//FALTA MODIFICAR POSICIONES Y TAMAÑO
	//archivos.push_back(new Archivo(24, 7, 40, 200, 5000, "Archivo Caceres", false));
	//archivos.push_back(new Archivo(53, 7, 40, 200, 4500, "Trad. peruanas", false));
	//archivos.push_back(new Archivo(111, 7, 40, 200, 4000, "Juras de indep.", false));
	//archivos.push_back(new Archivo(82, 7, 40, 200, 6000, "Archivo Courret", false));
	//archivos.push_back(new Archivo(140, 7, 40, 200, 3000, "Manuscrito Inca", false));

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


	agregarBien(new Archivo(24, 7, 40, 200, 5000, "Archivo Caceres", false));
	agregarBien(new Archivo(53, 7, 40, 200, 4500, "Trad. peruanas", false));
	agregarBien(new Archivo(111, 7, 40, 200, 4000, "Juras de indep.", false));
	agregarBien(new Archivo(82, 7, 40, 200, 6000, "Archivo Courret", false));

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
				enemigosCapturados++;
				eliminarEnemigo(i);
				guardia->setAccion(false);
				guardia->setTipoAccion(0);
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

bool GestorBiblioteca::victoria(){ return false;}
bool GestorBiblioteca::derrota(){ return false;}

void GestorBiblioteca::jugar(){}

void GestorBiblioteca::setearColisionesMapa(){}

void GestorBiblioteca::generarHuaquero(){}

void GestorBiblioteca::recargaLinterna(){}