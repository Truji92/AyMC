
#include "Conjunto.h"
#include "Insercion.h"
#include "Burbuja.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "Shell.h"
#include "FicherosYGraficas.h"
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
    cout << "\n ## Pulsa enter para continuar ## \n";
    cin.get();
    cin.get();
#else
    system("PAUSE");
#endif
}

template<class T>
    TestOrdenacion<T>::TestOrdenacion() {
        tOrdenacion<T> metodo1, metodo2, metodo3, metodo4, metodo5;
       
        metodo1.nombre_metodo = "Insercion";
        metodo1.estrategia = new Insercion<T>();
        metodo1.num_pruebas = 1000;
        testMetodos.push_back(metodo1);
        metodo2.nombre_metodo = "Burbuja";
        metodo2.estrategia = new Burbuja<T>();
        metodo2.num_pruebas = 1000;
        testMetodos.push_back(metodo2);
        metodo3.nombre_metodo = "MergeSort";
        metodo3.estrategia = new MergeSort<T>();
        metodo3.num_pruebas = 1000;
        testMetodos.push_back(metodo3);
        metodo4.nombre_metodo = "QuickSort";
        metodo4.estrategia = new QuickSort<T>();
        metodo4.num_pruebas = 1000;
        testMetodos.push_back(metodo4);
        metodo5.nombre_metodo = "Shell";
        metodo5.estrategia = new Shell<T>();
        metodo5.num_pruebas = 1000;
        testMetodos.push_back(metodo5);
        
        num_pruebas_al_comparar = 5000;
        
}

    template<class T>
double TestOrdenacion<T>::ordenarArray(T v[], int size, int metodo) {
    struct timeval ti, tf;
    double tiempo;
    gettimeofday(&ti, NULL); // Instante inicial 
    testMetodos[metodo].estrategia->ordenar(v, 0, size);
    gettimeofday(&tf, NULL); // Instante final 
    tiempo = (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec) / 1000.0;
    return tiempo;
}
template<class T>
void TestOrdenacion<T>::comprobarMetodos() {
    int talla;
    cout << endl << endl << "Introduce la talla: ";
    cin>>talla;
    system(CLEAR);
    for (int metodo = 0; metodo < testMetodos.size(); metodo++) {
        Conjunto<T> *v = new Conjunto<T>(talla);
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
template<class T>
void TestOrdenacion<T>::compararMetodos(vector<int> met) {
    int tallaIni = 100,
        tallaFin = 1000,
        incTalla = 100;
    
    Tiempos **array_tiempos = new Tiempos*[met.size()];
    for (int i = 0; i < met.size(); i++) {
        array_tiempos[i] = new Tiempos[(tallaFin - tallaIni) / incTalla + 1];
    }
    Conjunto<T> *conjunto;
    Conjunto<T> *conjclon;

    for (int i = tallaIni; i <= tallaFin; i += incTalla) {

        double t[met.size()];
        for (int j = 0; j < met.size(); j++)
            t[j] = 0;
        for (int j = 0; j < num_pruebas_al_comparar; j++) {
            conjunto = new Conjunto<T>(i);
            conjunto->generaVector();
            conjclon = new Conjunto<T>(i);
            conjclon->clonar(*conjunto);
            for (int metodo = 0; metodo < met.size(); metodo++) {
                t[metodo] += ordenarArray(conjclon->getDatos(), i, met[metodo]);
                conjclon->clonar(*conjunto);
            }
            delete conjunto;
            delete conjclon;
        }
        for (int metodo = 0; metodo < met.size(); metodo++) {
            t[metodo] /= num_pruebas_al_comparar;
            array_tiempos[metodo][i / incTalla - 1] = Tiempos(i, t[metodo]);
        }

    }

    system(CLEAR);
    cout << "Comparando metodos de busqueda \n\n";

    cout << "\tTalla  ";
    for (int i = 0; i < met.size(); i++) {
        cout << " \t Ti(" << testMetodos[met[i]].nombre_metodo << ") ";
    }
    cout << "\n\n";

    for (int i = 0; i < (tallaFin - tallaIni) / incTalla + 1; i++) {
        cout << "\t" << array_tiempos[0][i].elementos;
        for (int j = 0; j < met.size(); j++) {
            cout << "\t\t " << array_tiempos[j][i].tiempo;
        }
        cout << endl;
    }

    FicherosYGraficas<T>::GuardarEnArchivo(array_tiempos, (tallaFin - tallaIni) / incTalla + 1, met);
    pause();

}
template<class T>
void TestOrdenacion<T>::estudiarMetodo(int m) {
    int tallaIni = 100,
        tallaFin = 1000,
        incTalla = 100;
    
    Tiempos *array_tiempos = new Tiempos[(tallaFin - tallaIni) / incTalla + 1];
    Conjunto<T> *conjunto;

    for (int i = tallaIni; i <= tallaFin; i += incTalla) {
        double t = 0;
        for (int j = 0; j < testMetodos[m].num_pruebas; j++) {
            conjunto = new Conjunto<T>(i);
            conjunto->generaVector();
            int key = rand() % i + 1;
            t += ordenarArray(conjunto->getDatos(), i, m);
            delete conjunto;
        }
        t /= testMetodos[m].num_pruebas;
        array_tiempos[i / incTalla - 1] = Tiempos(i, t);
    }

    system(CLEAR);
    cout << "Busqueda " << testMetodos[m].nombre_metodo << " . Tiempos de ejecucion promedio\n\n";
    cout << "\tTalla(n)\tTiempos\n\n";
    for (int i = 0; i < (tallaFin - tallaIni) / incTalla + 1; i++) {
        cout << "\t" << array_tiempos[i].elementos << "\t\t" << array_tiempos[i].tiempo << endl;
    }

    FicherosYGraficas<T>::GuardarEnArchivo(array_tiempos, (tallaFin - tallaIni) / incTalla + 1, m);
    pause();
}
template<class T>
TestOrdenacion<T>::~TestOrdenacion<T>() {
    for (int i = 0; i < testMetodos.size(); i++) {
        delete testMetodos[i].estrategia;
    }
}



