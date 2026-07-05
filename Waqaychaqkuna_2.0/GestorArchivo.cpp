#include "pch.h"
#include "GestorArchivo.h"
using namespace std;

void GestorArchivo::cargarTodo(int& n1, int& n2, int& n3, int& gx, int& gy, int& bat) {
    std::ifstream f("PARAMETERS.txt");
    if (!f.is_open()) return;

    char sep; 

    f >> n1 >> sep; 
    f >> n2 >> sep;
    f >> n3 >> sep; 
    f >> gx >> sep; 
    f >> gy >> sep; 
    f >> bat >> sep;

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

// Guarda en texto legible: una linea "nombre;puntos;fecha"
void GestorArchivo::guardarTexto(Puntaje* p)
{
    ofstream f("puntajes.txt", ios::app); // ios::app = agrega al final, no borra
    if (f.is_open())
    {
        f << p->getNombre() << ";" << p->getPuntos() << ";" << p->getFecha() << "\n";
        f.close();
    }
}

// Lee todos los puntajes del .txt para poder mostrarlos en el formulario
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

