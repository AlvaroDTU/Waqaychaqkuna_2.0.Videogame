#pragma once
#include <string>
#include "Recursos.h"

using namespace System::Drawing;


enum Direccion { Arriba, Abajo, Izquierda, Derecha };

class Entidad
{
protected:
	int posX;
	int posY;
	int alto;
	int ancho;
	int dirX;
	int dirY;
	int fila, columna;
	bool moviendose;
	bool activo;
public:
	Entidad();
	Entidad(int posX, int posY, int dirX, int dirY);
	~Entidad();

	int getPosX();
	int getPosY();
	int getDirX();
	int getDirY();
	int getAlto();
	int getAncho();
	int getFila();
	int getColumna();
	bool getMoviendose();

	void setMoviendose(bool a);
	void setPos(int x, int y);
	void setAlto(int alt);
	void setAncho(int anch);
	void setFila(int fil);
	void setColumna(int colum);
	bool estaActivo();
	void setActivo(bool a);
	virtual Bitmap^ getBitmap() = 0;


	virtual void dibujar(Graphics^ g);
	virtual void mover(int ancho, int alto) = 0;
	virtual std::string getNombre() = 0;
	void avanzarEscena();

	System::Drawing::Rectangle getRectangle(int extra=0);


};

