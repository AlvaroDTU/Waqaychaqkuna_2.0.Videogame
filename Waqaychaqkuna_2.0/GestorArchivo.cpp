#include "pch.h"
#include "GestorArchivo.h"
#include <fstream>
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