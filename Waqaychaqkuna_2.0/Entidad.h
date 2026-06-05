#pragma once
#include <string>

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

public:
	Entidad();
	Entidad(std::string nombre, int posX, int posY, int alto, int ancho, int dirX, int dirY);
	~Entidad();




	int getPosX();
	int getPosY();
	int getDirX();
	int getDirY();
	int getAlto();
	int getAncho();

	void setPos(int x, int y);
	void setAlto(int alt);
	void setAncho(int anch);

	virtual void dibujar() = 0;
	virtual void mover(Direccion direccion) = 0;
	virtual std::string getNombre() = 0;

	System::Drawing::Rectangle getRectangle(int extra = 0);


};

