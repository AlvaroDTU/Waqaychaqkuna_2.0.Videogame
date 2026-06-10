#include "pch.h"
#include "Archivo.h"

Archivo::Archivo(int px, int py, int an, int al, int pValor, std::string nom, bool nc) : Bien(px, py, an, al, pValor, nom) {}
Archivo::~Archivo() {}

void Archivo::describir() {}