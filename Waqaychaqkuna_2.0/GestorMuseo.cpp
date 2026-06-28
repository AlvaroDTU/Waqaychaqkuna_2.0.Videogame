#include "pch.h"
#include "GestorMuseo.h"
#include "Artilugio.h"
#include "Ladron.h"
#include "Reportera.h"
#include <ctime>
#include <cstdlib>

GestorMuseo::GestorMuseo(int enTotales) : Escenario(enTotales)
{
	srand(time(nullptr));
	crearSprites();
	tempSpawnEntidades = 75;
	fondoActual = 1;
}

GestorMuseo::~GestorMuseo()
{
	Escenario::~Escenario();
}

void GestorMuseo::crearSprites()
{
	fondo = new Fondo(1, anchoLienzo, altoLienzo);

	guardia = new Guardia(790, 170,45,60,60,80);

	agregarBien(new Artilugio(153, 50, 230, 50, 800, "Cabeza Clava"));
	agregarBien(new Artilugio(535, 50, 230, 50, 1000, "Telar"));
	agregarBien(new Artilugio(917, 50, 230, 50, 2000, "Craneo"));
	agregarBien(new Artilugio(153, 600, 230, 50, 3000, "Huaco"));
	agregarBien(new Artilugio(535, 600, 230, 50, 5000, "Tumi Dorado"));
	agregarBien(new Artilugio(917, 600, 230, 50, 2500, "Vaso Kero"));

	agregarObjeto(new Objeto(294, 7, 974, 115));
	agregarObjeto(new Objeto(1159, 128, 105, 43));
	agregarObjeto(new Objeto(1210, 174, 57, 154));
	agregarObjeto(new Objeto(1242, 311, 58, 25));
	agregarObjeto(new Objeto(1212, 330, 18, 28));
	agregarObjeto(new Objeto(1206, 465, 22, 63));
	agregarObjeto(new Objeto(1241, 463, 59, 44));
	agregarObjeto(new Objeto(1241, 507, 28, 260));
	agregarObjeto(new Objeto(1140, 613, 87, 119));
	agregarObjeto(new Objeto(1047, 577, 84, 76));
	agregarObjeto(new Objeto(1019, 631, 28, 104));
	agregarObjeto(new Objeto(974, 664, 34, 68));
	agregarObjeto(new Objeto(1021, 345, 96, 157));
	agregarObjeto(new Objeto(910, 287, 30, 119));
	agregarObjeto(new Objeto(910, 472, 29, 125));
	agregarObjeto(new Objeto(907, 742, 362, 28));
	agregarObjeto(new Objeto(694, 770, 234, 27));
	agregarObjeto(new Objeto(680, 289, 28, 115));
	agregarObjeto(new Objeto(680, 471, 29, 129));
	agregarObjeto(new Objeto(335, 138, 252, 112));
	agregarObjeto(new Objeto(336, 255, 171, 44));
	agregarObjeto(new Objeto(503, 346, 91, 156));
	agregarObjeto(new Objeto(338, 429, 15, 88));
	agregarObjeto(new Objeto(292, 123, 26, 617));
	agregarObjeto(new Objeto(427, 574, 82, 78));
	agregarObjeto(new Objeto(338, 601, 17, 127));
	agregarObjeto(new Objeto(372, 632, 29, 95));
	agregarObjeto(new Objeto(409, 701, 110, 32));
	agregarObjeto(new Objeto(517, 616, 29, 21));
	agregarObjeto(new Objeto(550, 630, 30, 66));
	agregarObjeto(new Objeto(532, 660, 30, 71));
	agregarObjeto(new Objeto(570, 689, 35, 45));
	agregarObjeto(new Objeto(292, 741, 429, 29));
}

void GestorMuseo::mover()
{
	guardia->mover(1, anchoLienzo, altoLienzo, objetos);
	for (auto ladron : enemigos) ladron->mover(anchoLienzo, altoLienzo);
	for (int i = 0; i < (int)visitantes.size(); i++)
	{
		visitantes[i]->mover(anchoLienzo, altoLienzo);
		if (visitantes[i]->terminoRecorrido()) {
			eliminarVisitante(i);
			i--;
		}
	}
}
// void GestorMuseo::moverGuardia(Direccion direccion)
// {
// 	guardia->mover(direccion, anchoLienzo, altoLienzo, 1);
// }
void GestorMuseo::dibujar(Graphics^ g)
{
	fondo->dibujarFondo(g);
	for (auto reportera : aliados) reportera->dibujar(g);
	for (auto ladron : enemigos) ladron->dibujar(g);
	for (auto visitante : visitantes) visitante->dibujar(g);
	guardia->dibujar(g);
}

void GestorMuseo::detectarColisiones()
{
	Rectangle hbGuardia = guardia->getRectangle();
	Rectangle cambioDer = Rectangle(0, 0, 0, 0); // para que se mantengan inicializados
	Rectangle cambioIzq = Rectangle(0, 0, 0, 0);

	if (fondoActual == 1)
	{
		cambioDer = Rectangle(1241, 349, 60, 110);
	}
	if (fondoActual == 2)
	{
		cambioIzq = Rectangle(0, 350, 70, 110);
		cambioDer = Rectangle(1236, 355, 64, 110);
	}
	if (fondoActual == 3)
	{
		cambioIzq = Rectangle(0, 356, 65, 105);
	}
	if (hbGuardia.IntersectsWith(cambioDer))
	{
		fondoActual++;
		fondo->cambioEscena(fondoActual);
		if (fondoActual == 2) guardia->setPos(85, 370);
		if (fondoActual == 3) guardia->setPos(80, 365);
		cambioColisionesMapa();
	}
	if (hbGuardia.IntersectsWith(cambioIzq)) {
		fondoActual--;
		fondo->cambioEscena(fondoActual);
		if (fondoActual == 1) guardia->setPos(1171, 377);
		if (fondoActual == 2) guardia->setPos(1162, 367);
		cambioColisionesMapa();
	}
}

void GestorMuseo::cambioColisionesMapa()
{
	objetos.clear();
	if (fondoActual == 1)
	{
		objetos.clear();
		agregarObjeto(new Objeto(294, 7, 974, 115));
		agregarObjeto(new Objeto(1159, 128, 105, 43));
		agregarObjeto(new Objeto(1210, 174, 57, 154));
		agregarObjeto(new Objeto(1242, 311, 58, 25));
		agregarObjeto(new Objeto(1212, 330, 18, 28));
		agregarObjeto(new Objeto(1206, 465, 22, 63));
		agregarObjeto(new Objeto(1241, 463, 59, 44));
		agregarObjeto(new Objeto(1241, 507, 28, 260));
		agregarObjeto(new Objeto(1140, 613, 87, 119));
		agregarObjeto(new Objeto(1047, 577, 84, 76));
		agregarObjeto(new Objeto(1019, 631, 28, 104));
		agregarObjeto(new Objeto(974, 664, 34, 68));
		agregarObjeto(new Objeto(1021, 345, 96, 157));
		agregarObjeto(new Objeto(910, 287, 30, 119));
		agregarObjeto(new Objeto(910, 472, 29, 125));
		agregarObjeto(new Objeto(907, 742, 362, 28));
		agregarObjeto(new Objeto(694, 770, 234, 27));
		agregarObjeto(new Objeto(680, 289, 28, 115));
		agregarObjeto(new Objeto(680, 471, 29, 129));
		agregarObjeto(new Objeto(335, 138, 252, 112));
		agregarObjeto(new Objeto(336, 255, 171, 44));
		agregarObjeto(new Objeto(503, 346, 91, 156));
		agregarObjeto(new Objeto(338, 429, 15, 88));
		agregarObjeto(new Objeto(292, 123, 26, 617));
		agregarObjeto(new Objeto(427, 574, 82, 78));
		agregarObjeto(new Objeto(338, 601, 17, 127));
		agregarObjeto(new Objeto(372, 632, 29, 95));
		agregarObjeto(new Objeto(409, 701, 110, 32));
		agregarObjeto(new Objeto(517, 616, 29, 21));
		agregarObjeto(new Objeto(550, 630, 30, 66));
		agregarObjeto(new Objeto(532, 660, 30, 71));
		agregarObjeto(new Objeto(570, 689, 35, 45));
		agregarObjeto(new Objeto(292, 741, 429, 29));
	}
	if (fondoActual == 2)
	{
		objetos.clear();
		agregarObjeto(new Objeto(0,312,40,26));
		agregarObjeto(new Objeto(40,11,34,327));
		agregarObjeto(new Objeto(74,11,1156,132));
		agregarObjeto(new Objeto(74,143,276,24));
		agregarObjeto(new Objeto(480,143,71,26));
		agregarObjeto(new Objeto(577,143,150,24));
		agregarObjeto(new Objeto(748,143,71,26));
		agregarObjeto(new Objeto(978,143,46,26));
		agregarObjeto(new Objeto(1047,143,104,26));
		agregarObjeto(new Objeto(1154,143,71,26));
		agregarObjeto(new Objeto(1230,11,34,331));
		agregarObjeto(new Objeto(1264,312,36,30));
		agregarObjeto(new Objeto(0,462,38,47));
		agregarObjeto(new Objeto(38,462,36,329));
		agregarObjeto(new Objeto(74,738,1190,53));
		agregarObjeto(new Objeto(1230,464,34,274));
		agregarObjeto(new Objeto(1264,464,36,53));
	}
	if (fondoActual == 3)
	{
		objetos.clear();
	}
}
// void GestorMuseo::jugar()
// {
// 	if (temporizador == 50)
// 	{
// 		temporizador = 0;
// 		int dx = (rand() % 2) * 10 - 5; // entre -1 y 1
// 		int dy = 0;
// 		int objetivo = rand() % 6;
// 		int x = 0, y = (rand() % 2) * 110 + 305;
// 		if (dx > 0) x = -60;
// 		if (dx < 0) x = 1299;
// 		int op = rand() % 4;
// 		if (op < 2)
// 		{
// 			Ladron* nuevo = new Ladron(x, y, dx, dy, false, objetivo, rand() % 4 + 1, reportera->getTipoPista());
// 			agregarLadron(nuevo);
// 		}
// 		else
// 		{
// 			Visitante* nuevo = new Visitante(x, y, dx, 0);
// 			agregarVisitante(nuevo);
// 		}
// 	}
// 	mover();
// 	detectarColisiones();
// 	temporizador++;
// }

void GestorMuseo::agregarVisitante(Visitante* nuevo) { visitantes.push_back(nuevo); }
void GestorMuseo::eliminarVisitante(int i) { visitantes.erase(visitantes.begin() + i); }
bool GestorMuseo::victoria()
{
	return false;
}