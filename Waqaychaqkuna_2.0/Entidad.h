#pragma once
#include <string>
using namespace System::Drawing;


enum Direccion { Arriba, Abajo, Izquierda, Derecha };

class Entidad
{
protected:
	std::string nombre;
	int posX;
	int posY;
	int alto;
	int ancho;
	int dirX;
	int dirY;
	int fila, columna;
	bool moviendose;

public:
	Entidad();
	Entidad(std::string nombre, int posX, int posY, int ancho, int alto, int dirX, int dirY);
	~Entidad();


	// HOLA BRO

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
	


	virtual void dibujar(Graphics^ g, Bitmap^ img) = 0;
	virtual void mover(Direccion direccion) = 0;
	virtual std::string getNombre() = 0;

	System::Drawing::Rectangle getRectangle(int extra = 0);


};

