#include "pch.h"
#include "Cuidador.h"
Cuidador::Cuidador(int posX, int posY, int dirX, int dirY, bool ayuda, int dura)
	: Aliado(posX,posY,dirX,dirY,ayuda)
{
	this->duracion = dura;
}
Cuidador::~Cuidador(){}

int Cuidador::getDuracion() { return this->duracion; }
void Cuidador::RestarDuracion(int d) { this->duracion = d; }


std::string Cuidador::getNombre() { return "cuidador"; }
void Cuidador::mover(Direccion direccion, int ancho, int alto) {
	moviendose = true;

	switch (direccion) {
	case Direccion::Arriba:
		posY -= dirY;
		this->fila = 3;
		break;
	case Direccion::Abajo:
		posY += dirY;
		this->fila = 0;

		break;
	case Direccion::Derecha:
		posX += dirX;
		this->fila = 2;

		break;
	case Direccion::Izquierda:
		posX -= dirX;
		this->fila = 1;
		break;
	}

	Rectangle r = getRectangle(0);
	if (posX < 0) { posX = 0; }
	if (posY < 0) { posY = 0; }
	if (posX + r.Width > ancho)
		posX = ancho - r.Width;

	if (posY + r.Height > alto)
		posY = alto - r.Height;
}
void Cuidador::dibujar(Graphics^ g) {
	// CAMBIAR LUEGO A :
// Bitmap^ img = Recursos::cuidador;
	Bitmap^ img = Recursos::guardia;

	ancho = img->Width / 4;
	alto = img->Height / 4;

	//Rectangle r = Rectangle(columna*ancho,)

}