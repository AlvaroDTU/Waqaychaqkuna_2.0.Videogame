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
	bool activo;

public:
	Bien(int px, int py, int an, int al, int pValor, std::string nom,bool act=true);
	~Bien();

	int getPosX();
	int getPosY();
	int getPuntajeValor();
	std::string getNombre();

	bool estaActivo();
	void setActivo(bool act);
	void restarPuntajeValor(int pv);
	virtual void describir() = 0;
	Rectangle getRectangle(int extra = 0);
	virtual Bitmap^ getBitmap()=0;
	void dibujar(Graphics^ g, float escalaX, float escalaY) {
		Bitmap^ img = getBitmap();
		Rectangle origen(0, 0, ancho, alto);
		Rectangle destino(
			(int)(posX * escalaX),
			(int)(posY * escalaY),
			(int)(ancho * escalaX),
			(int)(alto * escalaY)
		);

		g->DrawImage(img, destino, origen, GraphicsUnit::Pixel);
	}
};

