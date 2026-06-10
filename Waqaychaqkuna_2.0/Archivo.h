#pragma once
#include "Bien.h"
class Archivo : public Bien

{
	public:
	Archivo(int px, int py, int an, int al, int pValor, std::string nom, bool nc);
	~Archivo();

	void describir() override;

};

