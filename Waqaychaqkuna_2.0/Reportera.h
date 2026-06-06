#pragma once
#include "Aliado.h"

class Reportera : public Aliado
{
private:
	int tipoPista;
public:
	Reportera(int posX, int posY, int dirX, int dirY, bool ayuda, int TipPis);
	~Reportera();

	int getTipoPista();
	void setTipoPista(int Tp);

	std::string getNombre() override;
	void mover(Direccion direccion, int ancho, int alto) override;
	void dibujar(Graphics^ g) override;
	
	// VER SI ESTO SE IMPREMENTARA
	//void ayudar() override

};

