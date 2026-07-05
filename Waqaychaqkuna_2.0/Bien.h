#pragma once
#include <string>

using namespace System::Drawing;

class Bien
{
protected:
	int posX, posY;
	int ancho, alto;
	int puntajeValor;
	std::string nombre;
	bool colision;
	bool activo;

public:
	Bien(int px, int py, int an, int al, int pValor, std::string nom,bool act=true);
	~Bien();

	int getPosX();
	int getPosY();
	int getPuntajeValor();
	std::string getNombre();
	bool getColision();
	void setColision(bool a);

	bool estaActivo();
	void setActivo(bool act);
	void restarPuntajeValor(int pv);
	Rectangle getRectangle(int extra = 0);
	virtual Bitmap^ getBitmap()=0;
	virtual Bitmap^ getBitmapDescripciones()=0;
	void dibujar(Graphics^ g, float escalaX, float escalaY) {
		Bitmap^ img = getBitmap();
		Rectangle origen(0, 0, ancho, alto);
		Rectangle destino(
			(int)(posX * escalaX),
			(int)(posY * escalaY),
			(int)(ancho * escalaX),
			(int)(alto * escalaY)
		);
		
	}
	void dibujarDescricicion(Graphics^ g, float escalaX, float escalaY) {
		Bitmap^ img = getBitmapDescripciones();
		Rectangle origen(0, 0, 300, 358);
		Rectangle destino(
			(int)(0 * escalaX),
			(int)(0 * escalaY),
			(int)(300 * escalaX),
			(int)(358 * escalaY)
		);
		g->DrawImage(img, destino, origen, GraphicsUnit::Pixel);
	}

};

