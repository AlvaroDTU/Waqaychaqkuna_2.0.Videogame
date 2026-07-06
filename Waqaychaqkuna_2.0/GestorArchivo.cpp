#include "pch.h"
#include "GestorArchivo.h"
#include <cstring>
using namespace std;

void GestorArchivo::cargarTodo(int& n1, int& n2, int& n3, int& gx, int& gy, int& bat) {
    std::ifstream f("PARAMETERS.txt");
    if (!f.is_open()) return;

    f >> n1; f.ignore(1);
    f >> n2; f.ignore(1);
    f >> n3; f.ignore(1);
    f >> gx; f.ignore(1);
    f >> gy; f.ignore(1);
    f >> bat;

    f.close();
}

string GestorArchivo::fechaActual()
{
    time_t t = time(nullptr);
    tm tiempo;
    localtime_s(&tiempo, &t);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y/%m/%d %H:%M", &tiempo);
    return string(buffer);
}

struct RegistroBinario {
    char nombre[50]; // Espacio fijo para nombres de hasta 49 letras
    int puntos;
    char fecha[20];  // Espacio fijo para la fecha
};


void GestorArchivo::guardarBinario(Puntaje* p)
{
    ofstream f("puntajes.dat", ios::binary | ios::app);
    if (f.is_open())
    {
        RegistroBinario reg;

        strncpy_s(reg.nombre, p->getNombre().c_str(), sizeof(reg.nombre) - 1);
        reg.puntos = p->getPuntos();
        strncpy_s(reg.fecha, p->getFecha().c_str(), sizeof(reg.fecha) - 1);

        f.write(reinterpret_cast<char*>(&reg), sizeof(RegistroBinario));
        f.close();
    }
}
void GestorArchivo::guardarTexto(Puntaje* p)
{
    ofstream f("puntajes.txt", ios::app); 
    if (f.is_open())
    {
        f << p->getNombre() << ";" << p->getPuntos() << ";" << p->getFecha() << "\n";
        f.close();
    }
}

vector<Puntaje*> GestorArchivo::leerTexto()
{
    vector<Puntaje*> lista;
    ifstream f("puntajes.txt");
    string nombre, sPuntos, fecha;

    // lee hasta el primer ;
    while (getline(f, nombre, ';'))
    {
        // lee el puntaje (texto)
        getline(f, sPuntos, ';');
        // lee el resto de la linea = fecha
        getline(f, fecha);
        // convierte el puntaje a numero    
        int puntos = atoi(sPuntos.c_str());
        lista.push_back(new Puntaje(nombre, puntos, fecha));
    }
    f.close();
    return lista;
}
// NUEVO MÉTODO: Lee todo el archivo binario y te devuelve el vector
vector<Puntaje*> GestorArchivo::leerBinario()
{
    vector<Puntaje*> lista;
    ifstream f("puntajes.dat", ios::binary);
    if (f.is_open())
    {
        RegistroBinario reg;

        while (f.read(reinterpret_cast<char*>(&reg), sizeof(RegistroBinario)))
        {
            string nombreStr(reg.nombre);
            string fechaStr(reg.fecha);

            lista.push_back(new Puntaje(nombreStr, reg.puntos, fechaStr));
        }
        f.close();
    }
    return lista;
}




void GestorArchivo::eliminarPuntajeBinario(string nombreAEliminar)
{
    ifstream origen("puntajes.dat", ios::binary);
    ofstream destino("temporal.dat", ios::binary);

    if (origen.is_open() && destino.is_open())
    {
        RegistroBinario reg;

        // Leemos bloque por bloque el archivo binario
        while (origen.read(reinterpret_cast<char*>(&reg), sizeof(RegistroBinario)))
        {
            string nombreStr(reg.nombre);

            // CONDICIÓN: Si el nombre coincide, lo saltamos (se elimina)
            if (nombreStr == nombreAEliminar)
            {
                continue;
            }

            // Si es de otro jugador, se conserva en el archivo temporal
            destino.write(reinterpret_cast<char*>(&reg), sizeof(RegistroBinario));
        }

        origen.close();
        destino.close();

        // Aplicamos los cambios en el disco
        remove("puntajes.dat");
        rename("temporal.dat", "puntajes.dat");
    }
}

