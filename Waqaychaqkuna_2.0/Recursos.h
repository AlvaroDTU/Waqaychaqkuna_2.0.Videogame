#pragma once

using namespace System::Drawing;

public ref class Recursos
{
public:
    static Bitmap^ guardia = gcnew Bitmap("sprites\\guardia.png");
   
    //----------------  ALIADOS  ----------------
    static Bitmap^ reportera = gcnew Bitmap("sprites\\reportera.png");
    static Bitmap^ cuidador = gcnew Bitmap("sprites\\cuidador.png");

    //---------------- VISITANTES ----------------
    static Bitmap^ visitante1 = gcnew Bitmap("sprites\\visitante1.png");
    static Bitmap^ visitante2 = gcnew Bitmap("sprites\\visitante2.png");
    static Bitmap^ visitante3 = gcnew Bitmap("sprites\\visitante3.png");
    static Bitmap^ visitante4 = gcnew Bitmap("sprites\\visitante4.png");

    //----------------  ENEMIGOS  ----------------
    static Bitmap^ ladron_brazalete1 = gcnew Bitmap("sprites\\ladron_brazalete1.png");
    static Bitmap^ ladron_brazalete2 = gcnew Bitmap("sprites\\ladron_brazalete2.png");
    static Bitmap^ ladron_brazalete3 = gcnew Bitmap("sprites\\ladron_brazalete3.png");
    static Bitmap^ ladron_brazalete4 = gcnew Bitmap("sprites\\ladron_brazalete4.png");
    static Bitmap^ ladron_bandana1 = gcnew Bitmap("sprites\\ladron_bandana1.png");
    static Bitmap^ ladron_bandana2 = gcnew Bitmap("sprites\\ladron_bandana2.png");
    static Bitmap^ ladron_bandana3 = gcnew Bitmap("sprites\\ladron_bandana3.png");
    static Bitmap^ ladron_bandana4 = gcnew Bitmap("sprites\\ladron_bandana4.png");
    static Bitmap^ ladron_camisa1 = gcnew Bitmap("sprites\\ladron_camisa1.png");
    static Bitmap^ ladron_camisa2 = gcnew Bitmap("sprites\\ladron_camisa2.png");
    static Bitmap^ ladron_camisa3 = gcnew Bitmap("sprites\\ladron_camisa3.png");
    static Bitmap^ ladron_camisa4 = gcnew Bitmap("sprites\\ladron_camisa4.png");

    static Bitmap^ huaquero = gcnew Bitmap("sprites\\huaquero.png");

    static Bitmap^ chavon = gcnew Bitmap("sprites\\chavon.png");

    //----------------  MAPAS  ---------------- 
    static Bitmap^ museo_fondo1 = gcnew Bitmap("backgrounds\\museo_fondo1.png");
    static Bitmap^ museo_fondo2 = gcnew Bitmap("backgrounds\\museo_fondo2.png");
    static Bitmap^ museo_fondo3 = gcnew Bitmap("backgrounds\\museo_fondo3.png");
    static Bitmap^ huacas = gcnew Bitmap("backgrounds\\Huacas.png");
    static Bitmap^ biblioteca = gcnew Bitmap("backgrounds\\lvl3.png");
};