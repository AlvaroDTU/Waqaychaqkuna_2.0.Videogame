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
	bool primerRondaVencida;
	bool segundaRondaVencida;
	int enemigosRonda1;
	int enemigosRonda2;
	int intentos;
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
	bool derrota() override;

	void agregarVisitante(Visitante* nuevo);
	void eliminarVisitante(int i);

	Reportera* getReportera();
	int getFondoActual() { return fondoActual; }
	int getIntentos() { return intentos; }
	void restarIntentos() { intentos--; }

	bool getIniciado() { return iniciado; }
	bool getPrimeraRondaVencida() { return primerRondaVencida; }
	bool getSegundaRondaVencida() { return segundaRondaVencida; }
};

