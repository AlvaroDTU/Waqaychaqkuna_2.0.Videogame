#include "pch.h"
#include "Visitante.h"

Visitante::Visitante(int posX, int posY, int dirX, int dirY)
			: Entidad(posX,posY,dirX,dirY)
{
	tipo = rand() % 6 + 1;
	posXFinal = 0;
}
Visitante::~Visitante(){}
std::string Visitante::getNombre() {
	for (int i = 0;i < 6;i++) {
		if (i == tipo) {
			return "enemigo" + std::to_string(i);;
		}
	}
}
void Visitante::mover(Direccion direccion, int ancho, int alto) {
	moviendose = true;

	switch (direccion) {
	case Direccion::Abajo:
		this->posY += dirY;
		this->fila = 0;
		break;
	case Direccion::Arriba:
		this->posY -= dirY;
		this->fila = 3;
		break;
	case Direccion::Derecha:
		this->posX += dirX;
		this->fila = 2;		
		break;
	case Direccion::Izquierda:
		this->posX -= dirX;
		this->fila = 1;		
		break;
	}

}
void Visitante::dibujar(Graphics^ g) {
	// luego cambiar a el img a al correspondiende de los visitantes
	Bitmap^ img;
	if (tipo == 1) {  img = Recursos::guardia; }
	else if (tipo == 2) { img = Recursos::guardia; }
	else if (tipo == 3) { img = Recursos::guardia; }
	else if (tipo == 4) { img = Recursos::guardia; }
	else if (tipo == 5) { img = Recursos::guardia; }
	else if (tipo == 6) { img = Recursos::guardia; }

	this->alto = img->Height / 4;
	this->ancho = img->Width / 4;

	Rectangle molde = Rectangle(columna * ancho, fila * alto, ancho, alto);
	if (moviendose == true) {
		columna++;
		if (columna == 4) { columna = 0; }
	}
	else
	{
		columna = 0;
	}
	g->DrawImage(img, posX, posY, molde, GraphicsUnit::Pixel);
	moviendose = false;
}
// cambiar d e acuerdo a los nuevos tamaños de la ventada
bool Visitante::terminoRecorrido() {
	if (dirX > 0) { posXFinal = 167; }
	else { posXFinal = 0; }
	return posX == posXFinal;
}