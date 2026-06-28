#pragma once
#include "Visitante.h"
#include "Reportera.h"
#include "Artilugio.h"
#include "Ladron.h"
#include "Escenario.h"
#include <vector>

using std::vector;

class GestorMuseo : public Escenario
{
private:
	vector<Visitante*> visitantes;
	int fondoActual;
	bool iniciado;
public:
	GestorMuseo(int enTotales);
	~GestorMuseo();
	
	void crearSprites() override;
	void dibujar(Graphics^ g) override;
	void mover() override;
	void detectarColisiones() override;
	void jugar();
	void setearColisionesMapa();
	bool victoria() override;

	void agregarVisitante(Visitante* nuevo);
	void eliminarVisitante(int i);

	Reportera* getReportera();
	int getFondoActual() { return fondoActual; }
};

