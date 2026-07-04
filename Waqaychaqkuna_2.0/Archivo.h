#pragma once
#include "Bien.h"
class Archivo : public Bien

{
	private:
	int tipo;

	public:
	Archivo(int px, int py, int an, int al, int pValor, std::string nom, bool nc, int t);
	~Archivo();

	std::string getNombre();
	void describir() override;

};

