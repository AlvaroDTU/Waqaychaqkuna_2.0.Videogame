#include "pch.h"
#include "Artilugio.h"


Artilugio::Artilugio(int px, int py, int an, int al, int pValor, std::string nom,int ti) 
	: Bien(px, py, an, al, pValor, nom, ti) 
{}
Artilugio::~Artilugio() {}
Bitmap^ Artilugio::getBitmap()
{
	return Recursos::vidrioRoto;
}
Bitmap^ Artilugio::getBitmapDescripciones()
{
	if (tipo == 1) return Recursos::artilugio1Desc;
	if (tipo == 2) return Recursos::artilugio2Desc;
	if (tipo == 3) return Recursos::artilugio3Desc;
	if (tipo == 4) return Recursos::artilugio4Desc;
	if (tipo == 5) return Recursos::artilugio5Desc;
	if (tipo == 6) return Recursos::artilugio6Desc;
	else return nullptr;
}
void Artilugio::dibujar(Graphics^ g, float escalaX, float escalaY) {
	Bitmap^ img = getBitmap();
	Rectangle origen(0, 0, 1080, 1066);
	Rectangle destino(
		(int)(posX * escalaX),
		(int)(posY * escalaY),
		(int)(ancho * escalaX),
		(int)(alto * escalaY)
	);
	g->DrawImage(img, destino, origen, GraphicsUnit::Pixel);
}

void Artilugio::dibujarDescripcion(Graphics^ g, float escalaX, float escalaY)
{
	Bitmap^ img = getBitmapDescripciones();
	Rectangle origen(0, 0, 300, 370);
	Rectangle destino(
		(int)(0 * escalaX),
		(int)(0 * escalaY),
		(int)(300 * escalaX),
		(int)(370 * escalaY)
	);
	g->DrawImage(img, destino, origen, GraphicsUnit::Pixel);
}
