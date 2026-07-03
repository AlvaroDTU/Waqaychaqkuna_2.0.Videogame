#include "pch.h"
#include "Dialogo.h"

using namespace System;
using namespace System::Drawing;

Dialogo::Dialogo()
    : lineaActual(0), letras(0), contador(0), ticksPorLetra(3), activo(false)
{}

void Dialogo::iniciar(std::vector<std::string> frases)
{
    lineas = frases;
    lineaActual = 0;
    letras = 0;
    contador = 0;
    activo = !lineas.empty();
}

void Dialogo::actualizar()
{
    if (!activo)
        return;

    contador++;
    if (contador >= ticksPorLetra)
    {
        contador = 0;
        if (letras < (int)lineas[lineaActual].length())
            letras++;
    }
}

void Dialogo::avanzar()
{
    if (!activo)
        return;

    if (letras < (int)lineas[lineaActual].length()) { letras = (int)lineas[lineaActual].length(); }

    else {
        lineaActual++;
        letras = 0;
        contador = 0;
        if (lineaActual >= (int)lineas.size())
            activo = false;
    }
}

bool Dialogo::estaActivo(){ return activo;}

void Dialogo::dibujar(Graphics^ g, int anchoLienzo, int altoLienzo)
{
    if (!activo)
        return;

    int margen = 30, alto = 130;
    int x = margen, ancho = anchoLienzo - 2 * margen;
    int y = altoLienzo - alto - margen;

    g->FillRectangle(gcnew SolidBrush(Color::FromArgb(225, 20, 20, 45)), x, y, ancho, alto);
    g->DrawRectangle(gcnew Pen(Color::White, 3), x, y, ancho, alto);

    String^ texto = gcnew String(lineas[lineaActual].substr(0, letras).c_str());

    g->DrawString(texto, gcnew System::Drawing::Font("Segoe UI", 16, FontStyle::Bold), gcnew SolidBrush(Color::White),
        RectangleF((float)(x + 20), (float)(y + 18), (float)(ancho - 40), (float)(alto - 50)));

    g->DrawString("[Espacio] continuar", gcnew System::Drawing::Font("Segoe UI", 10),
        gcnew SolidBrush(Color::Silver), (float)(x + ancho - 170), (float)(y + alto - 28));
}