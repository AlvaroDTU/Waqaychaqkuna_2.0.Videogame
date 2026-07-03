#pragma once
#include <string>
#include <vector>

using namespace System::Drawing;

class Dialogo {

private:
    std::vector<std::string> lineas;
    int lineaActual;
    int letras;
    int contador;
    int ticksPorLetra;
    bool activo;

public:
    Dialogo();

    void iniciar(std::vector<std::string> frases);
    void actualizar();
    void avanzar();
    bool estaActivo();
    void dibujar(Graphics^ g, int anchoLienzo, int altoLienzo);
};
