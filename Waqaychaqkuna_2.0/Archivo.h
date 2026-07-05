#pragma once
#include "Bien.h"
class Archivo : public Bien

{
	public:
	Archivo(int px, int py, int an, int al, int pValor, std::string nom, bool nc, int ti);
	~Archivo();
	Bitmap^ getBitmap();
	std::string getNombre();
	Bitmap^ getBitmapDescripciones() override;
	void dibujar(Graphics^ g, float escalaX, float escalaY) override;
	void dibujarDescripcion(Graphics^ g, float escalaX, float escalaY) override;

};

