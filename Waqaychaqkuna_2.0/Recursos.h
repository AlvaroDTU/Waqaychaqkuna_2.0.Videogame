#pragma once

using namespace System::Drawing;
using namespace System::Media;

public ref class Recursos
{
public:
    static Bitmap^ guardia = gcnew Bitmap("sprites\\guardia.png");
   
    //----------------  ALIADOS  ----------------
    static Bitmap^ reportera = gcnew Bitmap("sprites\\reportera.png");
    static Bitmap^ cuidador = gcnew Bitmap("sprites\\cuidador.png");
    static Bitmap^ murcielago = gcnew Bitmap("sprites\\bat.png");
    static Bitmap^ linterna = gcnew Bitmap("sprites\\linterna.png");


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
    static Bitmap^ huacas = gcnew Bitmap("backgrounds\\huacas.png");
    static Bitmap^ biblioteca = gcnew Bitmap("backgrounds\\biblioteca.png");

    //----------------- RECURSOS DEL MAPA ----------------------
    static Bitmap^ vidrioRoto = gcnew Bitmap("sprites\\vidrioroto.png");
    static Bitmap^ huaca1 = gcnew Bitmap("backgrounds\\Huaca1.png");
    static Bitmap^ huaca2 = gcnew Bitmap("backgrounds\\Huaca2.png");
    static Bitmap^ huaca3 = gcnew Bitmap("backgrounds\\Huaca3.png");
    static Bitmap^ huaca4 = gcnew Bitmap("backgrounds\\Huaca4.png");
    static Bitmap^ libros = gcnew Bitmap("sprites\\libros.png");

    //---------------- SONIDOS ----------------
    static SoundPlayer^ victoria = gcnew SoundPlayer("sonidos\\victoria.wav");
    static SoundPlayer^ perdiste = gcnew SoundPlayer("sonidos\\perdiste.wav");
    static SoundPlayer^ normal1 = gcnew SoundPlayer("sonidos\\normal1.wav");
    static SoundPlayer^ suspenso1 = gcnew SoundPlayer("sonidos\\suspenso1.wav");
    static SoundPlayer^ normal2 = gcnew SoundPlayer("sonidos\\normal2.wav");
    static SoundPlayer^ suspenso2 = gcnew SoundPlayer("sonidos\\suspenso2.wav"); 
    static SoundPlayer^ normal3 = gcnew SoundPlayer("sonidos\\normal3.wav");
    static SoundPlayer^ suspenso3 = gcnew SoundPlayer("sonidos\\suspenso3.wav");

    //---------------- DESCRIPCIONES ----------------
    static Bitmap^ huaca1Desc = gcnew Bitmap("backgrounds\\solDesc.png");
    static Bitmap^ huaca2Desc = gcnew Bitmap("backgrounds\\lunaDesc.png");
    static Bitmap^ huaca3Desc = gcnew Bitmap("backgrounds\\dragonDesc.png");
    static Bitmap^ huaca4Desc = gcnew Bitmap("backgrounds\\takaDesc.png");
    static Bitmap^ artilugio1Desc = gcnew Bitmap("backgrounds\\artilugio1Desc.png");
    static Bitmap^ artilugio2Desc = gcnew Bitmap("backgrounds\\artilugio2Desc.png");
    static Bitmap^ artilugio3Desc = gcnew Bitmap("backgrounds\\artilugio3Desc.png");
    static Bitmap^ artilugio4Desc = gcnew Bitmap("backgrounds\\artilugio4Desc.png");
    static Bitmap^ artilugio5Desc = gcnew Bitmap("backgrounds\\artilugio5Desc.png");
    static Bitmap^ artilugio6Desc = gcnew Bitmap("backgrounds\\artilugio6Desc.png");
    static Bitmap^ archivo1Desc = gcnew Bitmap("backgrounds\\archivo1desc.png");
    static Bitmap^ archivo2Desc = gcnew Bitmap("backgrounds\\archivo2desc.png");
    static Bitmap^ archivo3Desc = gcnew Bitmap("backgrounds\\archivo3desc.png");
    static Bitmap^ archivo4Desc = gcnew Bitmap("backgrounds\\archivo4desc.png");


    //---------------- ESTADITICAS ----------------
    static Bitmap^ PanelEstadisticas1 = gcnew Bitmap("backgrounds\\PanelEstadisticas1.png");
    static Bitmap^ PanelEstadisticas2 = gcnew Bitmap("backgrounds\\PanelEstadisticas2.png");
    static Bitmap^ PanelEstadisticas3 = gcnew Bitmap("backgrounds\\PanelEstadisticas3.png");

};