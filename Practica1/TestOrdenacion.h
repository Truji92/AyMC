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

/**
 * Struct utilizado para facilitar el manejo de medidas de 
 * tiempo para cada cantidad de elementos
 */
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
public:
    /**
     * Añade los métodos de ordenacion a probar al vector testMetodos
     */
    TestOrdenacion(); 
    ~TestOrdenacion();
    
    /**
     * Comprueba que los metodos de ordenacion funcionan bien
     */
    void comprobarMetodos(); 

    /**
     * Compara todos los metodos de ordenacion entre si. 
     * Permite las opciones de crear el fichero de datos y la gráfica correspondiente.
     * met: indice de los métodos de testMetodos a comparar
     */
    void compararMetodos(vector<int> met);
    
    /**
     * Estudia un metodo de ordenacion concreto. 
     * Permite las opciones de crear el fichero de datos y la gráfica correspondiente.
     */
    void estudiarMetodo(int m); 
    
    /**
     * Facilita la creación de los menús permitiendo acceder
     * a los nombres de algoritmos fuera de esta clase
     * @return vecto con los metodos a analizar
     */
    vector<tOrdenacion> getTestMetodos() {
        return testMetodos;
    }
    
};

#endif	/* TESTORDENACION_H */

