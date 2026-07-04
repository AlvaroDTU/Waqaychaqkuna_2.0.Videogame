#include "pch.h"
#include "GestorMuseo.h"

GestorMuseo::GestorMuseo(int enTotales) : Escenario(enTotales)
{
	srand(time(nullptr));
	iniciado = false;
	tempSpawnEntidades = 75;
	fondoActual = 1;
	intentos = 3;
	primerRondaVencida = false;
	segundaRondaVencida = false;
	enemigosRonda1 = rand() % (enemigosTotales / 2 - enemigosTotales / 4) + enemigosTotales / 4 + 1;
	enemigosRonda2 = enemigosTotales - enemigosRonda1;
}

GestorMuseo::~GestorMuseo()
{
	Escenario::~Escenario();
}

void GestorMuseo::crearSprites()
{
	fondo = new Fondo(1, anchoLienzo, altoLienzo);
	std::vector<std::string> frases;
	frases.push_back("Reportera: Evita que los huaqueros destruyan las huacas");
	frases.push_back("poniendo cuidadores que vigilen y protejan el patrimonio (letra E)");
	frases.push_back("Si el puntaje de una Huaca es menor a 1500, esta se destruye");
	dialogo.iniciar(frases);
	guardia = new Guardia(790, 170, 45, 60, 60, 80);

	agregarAliado(new Reportera(1095, 120, 45, 60, 60, 80));

	agregarBien(new Artilugio(243, 313, 181, 157, 800, "Cabeza Clava")); // 0
	agregarBien(new Artilugio(542, 313, 196, 157, 1000, "Telar"));// 1
	agregarBien(new Artilugio(857, 313, 181, 157, 2000, "Craneo"));// 2
	agregarBien(new Artilugio(223, 339, 177, 159, 3000, "Huaco"));// 3
	agregarBien(new Artilugio(507, 339, 180, 159, 5000, "Tumi Dorado"));// 4
	agregarBien(new Artilugio(794, 339, 171, 159, 2500, "Vaso Kero"));// 5

	setearColisionesMapa();
}

void GestorMuseo::mover()
{
	guardia->mover(objetos,bienes);
	aliados[0]->mover(anchoLienzo, altoLienzo);
	for (auto ladron : enemigos) ((Ladron*)ladron)->mover(objetos, bienes);
	for (auto visitante : visitantes) visitante->mover(objetos, bienes);
}

void GestorMuseo::dibujar(Graphics^ g)
{
	fondo->dibujarFondo(g);
	if (fondoActual == 1) 
	{
		for (auto reportera : aliados)
			reportera->dibujar(g);
	}
	for (auto ladron : enemigos) ladron->dibujar(g);
	for (auto visitante : visitantes) visitante->dibujar(g);
	guardia->dibujar(g);
}

void GestorMuseo::detectarColisiones()
{
	Rectangle hbGuardia = guardia->getRectangle();
	Rectangle hbReportera = aliados[0]->getRectangle(1);
	if (hbGuardia.IntersectsWith(hbReportera))
	{
		aliados[0]->ayudar();
	}
	else
		aliados[0]->setAyudando(false);

	// Colision con guardia y enemigos
	for (int i = (int)enemigos.size()-1; i >=0 ; i--)
	{
		Rectangle hbLadron = enemigos[i]->getRectangle(1);
		if (hbLadron.IntersectsWith(hbGuardia))
		{
			if (guardia->getAccion() && guardia->getTipoAccion()==1) {
				enemigosCapturados++;
				eliminarEnemigo(i);
				guardia->setAccion(false);
				guardia->setTipoAccion(0);
			}
		}
	}
	// Colision con guardia y visitantes
	for (int i = (int)visitantes.size()-1; i >=0 ; i--)
	{
		Rectangle hbVistante = visitantes[i]->getRectangle(1);
		if (hbVistante.IntersectsWith(hbGuardia))
		{
			if (guardia->getAccion() && guardia->getTipoAccion()==1) {
				intentos--;
				guardia->setAccion(false);
				guardia->setTipoAccion(0);
			}
		}
	}
	// Colision enemigos y bienes
	for (int i = 0; i < (int)enemigos.size(); i++)
	{
		for (int j = 0; j < (int)bienes.size(); j++)
		{
			Rectangle hitboxEnemigo = enemigos[i]->getRectangle();
			Rectangle hitboxBien = bienes[j]->getRectangle(5);
			if (hitboxEnemigo.IntersectsWith(hitboxBien) && enemigos[i]->getAtacando() && bienes[j]->estaActivo())
			{
				enemigos[i]->atacar(bienes[j]);
			}
		}
	}
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
		if (!iniciado)
		{
			if (((Reportera*)aliados[0])->getTipoPista() > 0) {
				iniciado = true;
				fondoActual++;
				fondo->cambioEscena(fondoActual);
				if (fondoActual == 2) guardia->setPos(85, 370);
				if (fondoActual == 3) guardia->setPos(80, 365);
				setearColisionesMapa();
				tempSpawnEntidades = 0;
			}
		}
	}
	if (hbGuardia.IntersectsWith(cambioIzq)) {
		if (!iniciado)
		{
			fondoActual--;
			fondo->cambioEscena(fondoActual);
			if (fondoActual == 1) guardia->setPos(1171, 377);
			if (fondoActual == 2) guardia->setPos(1162, 367);
			setearColisionesMapa();
			tempSpawnEntidades = 0;
		}
	}
}

void GestorMuseo::setearColisionesMapa()
{
	for (auto enemigo : enemigos) delete enemigo;
	enemigos.clear();
	for (auto visitante : visitantes) delete visitante;
	visitantes.clear();
	objetos.clear();
	if (fondoActual == 1)
	{
		enemigosCapturados = 0;
		primerRondaVencida = false;
		segundaRondaVencida = false;
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
		agregarObjeto(new Objeto(1284, 347, 16, 114));	//bordeDer

		for (int i = 0; i < (int)bienes.size(); i++) 
			bienes[i]->setActivo(false);
		aliados[0]->setActivo(true);
	}
	if (fondoActual == 2)
	{
		agregarObjeto(new Objeto(0, 312, 40, 26));
		agregarObjeto(new Objeto(40, 11, 34, 327));
		agregarObjeto(new Objeto(74, 11, 1156, 125));
		agregarObjeto(new Objeto(74, 136, 276, 23));
		agregarObjeto(new Objeto(480, 136, 71, 23));
		agregarObjeto(new Objeto(577, 136, 150, 21));
		agregarObjeto(new Objeto(748, 136, 71, 23));
		agregarObjeto(new Objeto(978, 136, 252, 23));
		agregarObjeto(new Objeto(1230, 11, 34, 331));
		agregarObjeto(new Objeto(1264, 312, 36, 30));
		agregarObjeto(new Objeto(0, 462, 38, 47));
		agregarObjeto(new Objeto(38, 462, 36, 329));
		agregarObjeto(new Objeto(74, 738, 1190, 53));
		agregarObjeto(new Objeto(1230, 464, 34, 274));
		agregarObjeto(new Objeto(1264, 464, 36, 53));
		agregarObjeto(new Objeto(0, 348, 15, 113));		// bordeIzq
		agregarObjeto(new Objeto(1285, 351, 15, 113));	// bordeDer
		agregarObjeto(new Objeto(442, 416, 48, 23));	//cartel 0
		agregarObjeto(new Objeto(760, 417, 48, 23));	// cartel 1
		agregarObjeto(new Objeto(1056, 416, 49, 23));	// cartel 2

		if (!primerRondaVencida)
		{
			for (int i = 0; i < enemigosRonda1; i++)
			{
				int x = 0, y = 0;
				x = rand() % 1109 + 75; // 75 a 1183
				if (rand() % 2 == 0) y = rand() % 84 + 159; // 159 a 242
				else y = rand() % 200 + 477; // 477 a 676
				int tipo = rand() % 3 + 1;
				agregarEnemigo(new Ladron(x, y, 45, 60, 60, 80, 0, 0, rand() % 3, tipo, ((Reportera*)aliados[0])->getTipoPista()));
			}
		}
		for (int i = 0; i < enemigosRonda1; i++)
		{
			int x = 0, y = 0;
			x = rand() % 1109 + 75; // 75 a 1183
			if (rand() % 2 == 0) y = rand() % 84 + 159; // 159 a 242
			else y= rand() % 200 + 477; // 477 a 676
			agregarVisitante(new Visitante(x,y,45,60,60,80,0,0));
		}

		for (int i = 0; i < (int)bienes.size(); i++)
		{
			if (i < 3) bienes[i]->setActivo(true);
			else bienes[i]->setActivo(false);
		}
		aliados[0]->setActivo(false);
	}
	if (fondoActual == 3)
	{
		agregarObjeto(new Objeto(0, 311, 72, 30));
		agregarObjeto(new Objeto(28, 148, 44, 163));
		agregarObjeto(new Objeto(28, 12, 1153, 136));
		agregarObjeto(new Objeto(449, 148, 56, 28));
		agregarObjeto(new Objeto(534, 148, 149, 24));
		agregarObjeto(new Objeto(716, 148, 56, 28));
		agregarObjeto(new Objeto(913, 148, 223, 24));
		agregarObjeto(new Objeto(1136, 148, 45, 638));
		agregarObjeto(new Objeto(0, 465, 28, 53));
		agregarObjeto(new Objeto(28, 465, 44, 265));
		agregarObjeto(new Objeto(28, 730, 1108, 56));
		agregarObjeto(new Objeto(0, 351, 14, 113));		// bordeIzq
		agregarObjeto(new Objeto(411, 438, 44, 32));	// cartel 3
		agregarObjeto(new Objeto(698, 438, 44, 32));	// cartel 4
		agregarObjeto(new Objeto(976, 438, 44, 32));	// cartel 5

		if (!segundaRondaVencida) {
			for (int i = 0; i < enemigosRonda2; i++)
			{
				int x = 0, y = 0;
				x = rand() % 1013 + 75; // 75 a 1088
				if (rand() % 2 == 0) y = rand() % 96 + 180; // 180 a 275
				else y = rand() % 137 + 532; // 532 a 668
				int tipo = rand() % 3 + 1;
				agregarEnemigo(new Ladron(x, y, 45, 60, 60, 80, 0, 0, rand() % 3 + 3, tipo, ((Reportera*)aliados[0])->getTipoPista()));
			}
		}
		for (int i = 0; i < enemigosRonda2; i++)
		{
			int x = 0, y = 0;
			x = rand() % 1013 + 75; // 75 a 1088
			if (rand() % 2 == 0) y = rand() % 96 + 180; // 180 a 275
			else y = rand() % 137 + 532; // 532 a 668
			agregarVisitante(new Visitante(x, y, 45, 60, 60, 80, 0, 0));
		}
		for (int i = 0; i < (int)bienes.size(); i++)
		{
			if (i < 3) bienes[i]->setActivo(false);
			else bienes[i]->setActivo(true);
		}
		aliados[0]->setActivo(false);
	}
}
void GestorMuseo::jugar()
{
	mover();
	detectarColisiones();

	if (enemigosCapturados == enemigosRonda1 && !primerRondaVencida) { iniciado = false; primerRondaVencida = true; }
	if (enemigosCapturados == enemigosTotales && !segundaRondaVencida) { iniciado = false; segundaRondaVencida = true; }
	if (fondoActual > 1) tempSpawnEntidades++;
}

void GestorMuseo::agregarVisitante(Visitante* nuevo) { visitantes.push_back(nuevo); }
void GestorMuseo::eliminarVisitante(int i) { visitantes.erase(visitantes.begin() + i); }
bool GestorMuseo::victoria()
{
	return primerRondaVencida && segundaRondaVencida;
}
bool GestorMuseo::derrota()
{
	bool bienDestruido=false;
	for (auto bien : bienes) 
	{
		if (bien->getPuntajeValor() <= 0) bienDestruido = true;
	}
	return intentos <= 0 || bienDestruido;
}

Reportera* GestorMuseo::getReportera()
{
	return (Reportera*)aliados[0];
}