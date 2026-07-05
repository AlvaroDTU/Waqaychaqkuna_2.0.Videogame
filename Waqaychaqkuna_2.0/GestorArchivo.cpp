#include "pch.h"
#include "GestorArchivo.h"
#include <cstring>
using namespace std;

void GestorArchivo::cargarTodo(int& n1, int& n2, int& n3, int& gx, int& gy, int& bat) {
    std::ifstream f("PARAMETERS.txt");
    if (!f.is_open()) return;

    // Lee el número e ignora 1 carácter (el separador ';') antes del siguiente
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

// Estructura fija para escribir/leer bloques perfectos en binario
struct RegistroBinario {
    char nombre[50]; // Espacio fijo para nombres de hasta 49 letras
    int puntos;
    char fecha[20];  // Espacio fijo para la fecha
};


void GestorArchivo::guardarBinario(Puntaje* p)
{
    // ios::binary para manejar bytes, ios::app para agregar al final
    ofstream f("puntajes.dat", ios::binary | ios::app);
    if (f.is_open())
    {
        RegistroBinario reg;

        // Copiamos los string variables a nuestros arreglos fijos de bytes
        strncpy_s(reg.nombre, p->getNombre().c_str(), sizeof(reg.nombre) - 1);
        reg.puntos = p->getPuntos();
        strncpy_s(reg.fecha, p->getFecha().c_str(), sizeof(reg.fecha) - 1);

        // Escribimos el bloque completo de memoria en el archivo
        f.write(reinterpret_cast<char*>(&reg), sizeof(RegistroBinario));
        f.close();
    }
}
void GestorArchivo::guardarTexto(Puntaje* p)
{
    ofstream f("puntajes.txt", ios::app); // ios::app = agrega al final, no borra
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

        // Lee bloques del tamaño exacto de la estructura hasta que se acabe el archivo
        while (f.read(reinterpret_cast<char*>(&reg), sizeof(RegistroBinario)))
        {
            // Convertimos los char arrays de vuelta a std::string automáticamente
            string nombreStr(reg.nombre);
            string fechaStr(reg.fecha);

            lista.push_back(new Puntaje(nombreStr, reg.puntos, fechaStr));
        }
        f.close();
    }
    return lista;
}


// Devuelve el puntaje de la ultima partida guardada (0 si no hay ninguna).
int GestorArchivo::ultimoPuntaje()
{
    vector<Puntaje*> lista = leerTexto();
    int ultimo = 0;
    if (!lista.empty())
        ultimo = lista[lista.size() - 1]->getPuntos();
    for (int i = 0; i < (int)lista.size(); i++)
        delete lista[i];
    return ultimo;
}
int GestorArchivo::leerRecord()
{
    int record = 0;
    ifstream f("record.dat", ios::binary);
    if (f.is_open())
    {
        // lee los 4 bytes del entero
        f.read((char*)&record, sizeof(int));
        f.close();
    }
    return record;
}

// Guarda el record en binario. Usa ios::trunc para SOBRESCRIBIR (solo queda el mejor).
void GestorArchivo::guardarRecord(int puntos)
{
    ofstream f("record.dat", ios::binary | ios::trunc);
    if (f.is_open())
    {
        f.write((char*)&puntos, sizeof(int));
        f.close();
    }
}

