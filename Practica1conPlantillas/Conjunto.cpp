#include <iostream>
using namespace std;
#include <cstdlib>
#include <time.h>

///////////// Implementación de los métodos /////////////

template<class T>
Conjunto<T>::Conjunto(int max) {
    tamano = max;
    nelementos = 0;
    datos = new T[max];
}

template<class T>
Conjunto<T>::~Conjunto() {
    delete[] datos;
}

template<class T>
void Conjunto<T>::vaciar() {
    nelementos = 0;
}

template<class T>
void Conjunto<T>::insertar(T n) {
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

template<class T>
bool Conjunto<T>::miembro(T n) {
    for (int i = 0; i < nelementos; i++)
        if (datos[i] == n)
            return true;
    return false;
}

template<class T>
void Conjunto<T>::ordena(int tam) {
    for (int i = 0; i < tam - 1; i++)
        for (int j = i + 1; j < tam; j++)
            if (datos[j] < datos[i]) {
                T tmp = datos[i];
                datos[i] = datos[j];
                datos[j] = tmp;
            }
}

template<class T>
void Conjunto<T>::ordena() {
    ordena(nelementos);
}

template<class T>
void Conjunto<T>::escribe(int tam) {
    for (int i = 0; i < tam; i++)
        cout << datos[i] << (i < tam - 1 ? ", " : "\n");
}

template<class T>
void Conjunto<T>::escribe(){
    escribe(nelementos);
}

template<class T>
void Conjunto<T>::clonar(Conjunto& c) {
    this->tamano = c.tamano;
    this->nelementos = c.nelementos;
    for (int i = 0; i < tamano; i++) {
        this->datos[i] = c.datos[i];
    }
}

template<class T>
T* Conjunto<T>::getDatos() {
    return datos;
}

template<>
void Conjunto<char>::generaVector() {
    for (int i = 0; i< tamano; i++) {
        datos[i] = 'A' + (random() % 26);
    }
    nelementos = tamano;
} 

template<class T>
void Conjunto<T>::generaVector() {
    srand((unsigned) time(NULL)); //srand(time(0));
    for (int i = 0; i < tamano; i++) {
        datos[i] = (T) rand() % 100; //genera un n�mero aleatorio entre 1 y 999
    }
    nelementos = tamano;
}


