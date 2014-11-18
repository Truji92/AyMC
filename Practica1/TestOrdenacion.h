/* 
 * File:   TestOrdenacion.h
 * Author: alejandro
 * 
 */

#ifndef TESTORDENACION_H
#define	TESTORDENACION_H

using namespace std;

#include <string>
#include <vector>
#include "Ordenacion.h"

struct Tiempos {
    int elementos;
    double tiempo;
    Tiempos(){}
    Tiempos(int elem, double t) {
        elementos = elem;
        tiempo = t;
    }
};

struct tOrdenacion {
    int num_pruebas; // Numero de pruebas para un método de ordenacion
    string nombre_metodo; // Nombre del metodo de ordenacion
    Ordenacion *estrategia; // puntero al tipo de ordenacion a realizar
};

class TestOrdenacion {
    vector<tOrdenacion> testMetodos; // contiene todos los métodos a estudiar
    int num_pruebas_al_comparar;
    
    double ordenarArray(int v[],int size,int metodo);
    
    void GuardarEnArchivo(Tiempos *T, int size, int metodo);
    void GenerarGrafica(Tiempos *T, int size, int metodo);

    void GuardarEnArchivo(Tiempos **T, int size, vector<int> metodos);
    void GenerarGrafica(Tiempos **T, int size, vector<int> metodos);
public:
    TestOrdenacion(); //añade los métodos de ordenacion a probar al vector testMetodos
    ~TestOrdenacion();

    void comprobarMetodos(); // Comprueba que los metodos de ordenacion funcionan bien

    //Compara todos los metodos de ordenacion entre si. 
    //Permite las opciones de crear el fichero de datos y la gráfica correspondiente.
    //met: indice de los métodos de testMetodos a comparar
    void compararMetodos(vector<int> met);

    //Estudia un metodo de ordenacion concreto. 
    //Permite las opciones de crear el fichero de datos y la gráfica correspondiente.
    void estudiarMetodo(int m); // el método a estudiar es testMetodos[m-1]
    
    vector<tOrdenacion> getTestMetodos() {
        return testMetodos;
    }
    
};

#endif	/* TESTORDENACION_H */

