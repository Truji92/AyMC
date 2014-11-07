#include <iostream>
using namespace std;
#include "conjuntoInt.h"

///////////// Implementación de los métodos /////////////

void conjuntoInt::vaciar() {
    tamano = 0;
}

void conjuntoInt::insertar(int n) {
    if (tamano < MAXIMO)
        datos[tamano++] = n; // pueden estar repetidos pues no se comprueba si ya está el n
    else
        cerr << "ERROR: el conjunto esta lleno " << endl;
}

bool conjuntoInt::miembro(int n) {
    for (int i = 0; i < tamano; i++)
        if (datos[i] == n)
            return true;
    return false;
}

void conjuntoInt::ordena(int tam) {
    for (int i = 0; i < tam - 1; i++)
        for (int j = i + 1; j < tam; j++)
            if (datos[j] < datos[i]) {
                int tmp = datos[i];
                datos[i] = datos[j];
                datos[j] = tmp;
            }
}

void conjuntoInt::ordena() {
    ordena(tamano);
}

void conjuntoInt::escribe(int tam) {
    for (int i = 0; i < tam; i++)
        cout << datos[i] << (i < tam - 1 ? ", " : "\n");
}

void conjuntoInt::escribe(){
    escribe(tamano);
}

void conjuntoInt::clonar(conjuntoInt& c) {
    this->tamano = c.tamano;
    for (int i = 0; i < tamano; i++) {
        this->datos[i] = c.datos[i];
    }
}




