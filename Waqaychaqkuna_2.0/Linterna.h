#pragma once
#include "Recursos.h"
using namespace System::Drawing;

class Linterna
{
	private:
		int posX;
		int posY;
		int dirX;
		int dirY;
		int ancho, alto;
		int anchoFrame, altoFrame;
		int fila, columna;
		bool encendida;

	public:
		Linterna(bool encendida);
		~Linterna();

		int getPosX();
		int getPosY();
		int getDirX();
		int getDirY();
		int getAlto();
		int getAncho();
		bool getEncendida();

		void setPos(int x, int y);
		void setEncendida(bool e);
		void dibujar(Graphics^ g);
		Bitmap^ getBitmap();
		Rectangle getRectangle(int extra=0);
};

