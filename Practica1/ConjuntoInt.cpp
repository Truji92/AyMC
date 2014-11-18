#include <iostream>
using namespace std;
#include "ConjuntoInt.h"
#include <cstdlib>

///////////// Implementación de los métodos /////////////

ConjuntoInt::ConjuntoInt(int max) {
    tamano = max;
    nelementos = 0;
    datos = new int[max];
}

ConjuntoInt::~ConjuntoInt() {
    delete[] datos;
}


void ConjuntoInt::vaciar() {
    nelementos = 0;
}

void ConjuntoInt::insertar(int n) {
    if (nelementos < tamano) {
        datos[nelementos] = n; // pueden estar repetidos pues no se comprueba si ya está el n
        nelementos++;
    } else {
        int *aux = new int[tamano + 3];
        for (int i = 0; i < tamano; i++) {
            aux[i] = datos[i];
        }
        tamano += 3;
        delete datos;
        datos = aux;
        datos[nelementos] = n;
        nelementos++;
    }
}

bool ConjuntoInt::miembro(int n) {
    for (int i = 0; i < nelementos; i++)
        if (datos[i] == n)
            return true;
    return false;
}

void ConjuntoInt::ordena(int tam) {
    for (int i = 0; i < tam - 1; i++)
        for (int j = i + 1; j < tam; j++)
            if (datos[j] < datos[i]) {
                int tmp = datos[i];
                datos[i] = datos[j];
                datos[j] = tmp;
            }
}

void ConjuntoInt::ordena() {
    ordena(nelementos);
}

void ConjuntoInt::escribe(int tam) {
    for (int i = 0; i < tam; i++)
        cout << datos[i] << (i < tam - 1 ? ", " : "\n");
}

void ConjuntoInt::escribe(){
    escribe(nelementos);
}

void ConjuntoInt::clonar(ConjuntoInt& c) {
    this->tamano = c.tamano;
    this->nelementos = c.nelementos;
    for (int i = 0; i < tamano; i++) {
        this->datos[i] = c.datos[i];
    }
}

int* ConjuntoInt::getDatos() {
    return datos;
}

void ConjuntoInt::generaVector() {
    srand((unsigned) time(NULL)); //srand(time(0));
    for (int i = 0; i < tamano; i++) {
        datos[i] = rand() % 1000; //genera un n�mero aleatorio entre 1 y 999
    }
    nelementos = tamano;
}


