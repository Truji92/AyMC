#include "TestOrdenacion.h"
#include "ConjuntoInt.h"
#include "Insercion.h"
#include "Burbuja.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "Shell.h"
#include <iostream>
#include <cstdlib>
#include <sys/time.h>
using namespace std;

#ifdef __linux__
#define CLEAR "clear"
#else
#define CLEAR "cls"
#endif

void pause() {
#ifdef __linux__
    cin.clear();
    cout << "\n ## Pulsa una tecla para continuar ## \n";
    cin.get();
    cin.get();
#else
    system("PAUSE");
#endif
}


    TestOrdenacion::TestOrdenacion() {
        tOrdenacion metodo1, metodo2, metodo3, metodo4, metodo5;
        
        metodo1.nombre_metodo = "Insercion";
        metodo1.estrategia = new Insercion();
        testMetodos.push_back(metodo1);
        metodo2.nombre_metodo = "Burbuja";
        metodo2.estrategia = new Burbuja();
        testMetodos.push_back(metodo2);
        metodo3.nombre_metodo = "MergeSort";
        metodo3.estrategia = new MergeSort();
        testMetodos.push_back(metodo3);
        metodo4.nombre_metodo = "QuickSort";
        metodo4.estrategia = new QuickSort();
        testMetodos.push_back(metodo4);
        metodo5.nombre_metodo = "Shell";
        metodo5.estrategia = new Shell();
        testMetodos.push_back(metodo5);

}

double TestOrdenacion::ordenarArray(int v[], int size, int metodo) {
    struct timeval ti, tf;
    double tiempo;
    gettimeofday(&ti, NULL); // Instante inicial 
    testMetodos[metodo].estrategia->ordenar(v, 0, size);
    gettimeofday(&tf, NULL); // Instante final 
    tiempo = (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec) / 1000.0;
    return tiempo;
}

void TestOrdenacion::comprobarMetodos() {
    int talla;
    cout << endl << endl << "Introduce la talla: ";
    cin>>talla;
    system(CLEAR);
    for (int metodo = 0; metodo < testMetodos.size(); metodo++) {
        ConjuntoInt *v = new ConjuntoInt(talla);
        v->generaVector();
        cout << endl << endl << "vector inicial para el metodo " << testMetodos[metodo].nombre_metodo << ":" << endl << endl;
        v->escribe();
        ordenarArray(v->getDatos(), talla, metodo);
        cout << endl << endl << "Array ordenado con metodo " << testMetodos[metodo].nombre_metodo << ":" << endl << endl;
        v->escribe();
        cout << endl;
        v->vaciar();
        pause();
        system(CLEAR);
    }
    system(CLEAR);
}

    void TestOrdenacion::compararMetodos(vector<int> met) {
        
    }

    void TestOrdenacion::estudiarMetodo(int m) {
        
    }
    
    TestOrdenacion::~TestOrdenacion() {
        for (int i = 0; i < testMetodos.size(); i++) {
            delete testMetodos[i].estrategia;
        }
    }

