#ifndef FICHEROSYGRAFICAS_H
#define	FICHEROSYGRAFICAS_H
using namespace std;
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "TestOrdenacion.h"

class FicherosYGraficas {
    static TestOrdenacion *test;
    
    static void dibujar(string archivo);
public:
    
    /**
     * Funcion que debe llamarse antes de utilizar la clase para definir 
     * la clase TestOrdenacion con la que trabajará y por tanto los nombres 
     * de los algoritmos que imprimira en archivos y gráficas
     * @param _test Istancia de TestOrdenacion con la que trabajar
     */
    static void setTest(TestOrdenacion *_test) {
        test = _test;
    }
    
    /**
     * Guarda en un archivo los datos de una prueba
     * @param T array que contiene tallas y tiempos
     * @param size tamaño de T
     * @param metodo metodo que se esta analizando
     */
    static void GuardarEnArchivo(Tiempos *T, int size, int metodo);
    /**
     * Dibuja en una gráfica los datos de una prueba
     * @param T array que contiene tallas y tiempos
     * @param size tamaño de T
     * @param metodo metodo que se esta analizando
     */
    static void GenerarGrafica(Tiempos *T, int size, int metodo);

    
    /**
     * Guarda en un archivo los datos de una comparación
     * @param T tabla de dos dimensiones con los datos de las pruebas
     * @param size tamaño de T
     * @param metodos Diferentes metodos que se estan comparando
     */
    static void GuardarEnArchivo(Tiempos **T, int size, vector<int> metodos);
    static void GenerarGrafica(Tiempos **T, int size, vector<int> metodos);
};


#endif	/* FICHEROSYGRAFICAS_H */

