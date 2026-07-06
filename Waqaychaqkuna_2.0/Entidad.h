#pragma once
#include <string>
#include "Recursos.h"
using namespace System::Drawing;

class Entidad
{
protected:
	int posX;
	int posY;
	int dirX;
	int dirY;
	int ancho, alto;
	int anchoFrame, altoFrame;

	int fila, columna;
	int contadorTicks;
	bool activo;

	void avanzarEscena();
public:
	Entidad();
	Entidad(int posX, int posY, int an, int al, int anF, int alF, int dirX, int dirY,bool acti=true);
	~Entidad();

	int getPosX();
	int getPosY();
	int getDirX();
	int getDirY();
	int getAlto();
	int getAncho();
	int getFila();
	int getColumna();

	void setPos(int x, int y);
	void setAlto(int alt);
	void setAncho(int anch);
	void setFila(int fil);
	void setColumna(int colum);
	bool estaActivo();
	void setActivo(bool a);
	void dibujar(Graphics^ g, float escalaX, float escalaY);

	virtual Bitmap^ getBitmap() = 0;
	virtual void mover(int ancho, int alto) = 0;
	virtual std::string getNombre() = 0;

	System::Drawing::Rectangle getRectangle(int extra=0);
};

