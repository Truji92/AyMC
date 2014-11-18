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
#include <fstream>
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

void dibujar(string archivo){
#ifdef __linux__
    string comando = "gnuplot ";
    comando.append(archivo);
    system(comando.c_str());
#else
    system(archivo.c_str());
#endif
}

    TestOrdenacion::TestOrdenacion() {
        tOrdenacion metodo1, metodo2, metodo3, metodo4, metodo5;
        
        metodo1.nombre_metodo = "Insercion";
        metodo1.estrategia = new Insercion();
        metodo1.num_pruebas = 300;
        testMetodos.push_back(metodo1);
        metodo2.nombre_metodo = "Burbuja";
        metodo2.estrategia = new Burbuja();
        metodo2.num_pruebas = 300;
        testMetodos.push_back(metodo2);
        metodo3.nombre_metodo = "MergeSort";
        metodo3.estrategia = new MergeSort();
        metodo3.num_pruebas = 300;
        testMetodos.push_back(metodo3);
        metodo4.nombre_metodo = "QuickSort";
        metodo4.estrategia = new QuickSort();
        metodo4.num_pruebas = 300;
        testMetodos.push_back(metodo4);
        metodo5.nombre_metodo = "Shell";
        metodo5.estrategia = new Shell();
        metodo5.num_pruebas = 300;
        testMetodos.push_back(metodo5);
        
        num_pruebas_al_comparar = 300;

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
    int tallaIni = 100,
        tallaFin = 1000,
        incTalla = 100;
    
    Tiempos **array_tiempos = new Tiempos*[met.size()];
    for (int i = 0; i < met.size(); i++) {
        array_tiempos[i] = new Tiempos[(tallaFin - tallaIni) / incTalla + 1];
    }
    ConjuntoInt *conjunto;
    ConjuntoInt *conjclon;

    for (int i = tallaIni; i <= tallaFin; i += incTalla) {

        double t[met.size()];
        for (int j = 0; j < met.size(); j++)
            t[j] = 0;
        for (int j = 0; j < num_pruebas_al_comparar; j++) {
            conjunto = new ConjuntoInt(i);
            conjunto->generaVector();
            conjclon = new ConjuntoInt(i);
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

    GuardarEnArchivo(array_tiempos, (tallaFin - tallaIni) / incTalla + 1, met);
    pause();

}

void TestOrdenacion::estudiarMetodo(int m) {
    int tallaIni = 100,
        tallaFin = 1000,
        incTalla = 100;
    
    Tiempos *array_tiempos = new Tiempos[(tallaFin - tallaIni) / incTalla + 1];
    ConjuntoInt *conjunto;

    for (int i = tallaIni; i <= tallaFin; i += incTalla) {
        double t = 0;
        for (int j = 0; j < testMetodos[m].num_pruebas; j++) {
            conjunto = new ConjuntoInt(i);
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

    GuardarEnArchivo(array_tiempos, (tallaFin - tallaIni) / incTalla + 1, m);
    pause();
}

TestOrdenacion::~TestOrdenacion() {
    for (int i = 0; i < testMetodos.size(); i++) {
        delete testMetodos[i].estrategia;
    }
}


void TestOrdenacion::GenerarGrafica(Tiempos *T, int size, int metodo) {
    char res;
    do {
        cout << "Generar Grafica? (s/n): ";
        cin >>res;
    }while (res != 's' && res != 'n');

    string nombrefichero;
    if (res == 's') {
        nombrefichero = testMetodos[metodo].nombre_metodo;
        string ficheroDatos = nombrefichero + ".dat";
        nombrefichero += ".plt";

        ofstream salida(nombrefichero.c_str());

        salida << "set title \"Tiempos medios para el algoritmo de ordenación " << testMetodos[metodo].nombre_metodo << "\"\n";
        salida << "set key top left vertical inside\n"<<"set grid\n"<< "set xlabel \"Talla (n)\"\n"<<"set ylabel \"Tiempo (micros)\"\n";
        if (metodo == 2 || metodo == 3)  //QuickSort y MergeSort
            salida << "y(x)=a+b*x+c*x*log(x)/log(2)\n" << "fit y(x) \"" << ficheroDatos<< "\" using 1:2 via a,b,c\n";
        if (metodo == 0 || metodo == 1 || metodo == 4) //insercion burbuja y shell
            salida << "y(x)=a+b*x+c*x*x\n"<< "fit y(x) \""<<ficheroDatos<< "\" using 1:2 via a,b\n";


        salida << "plot \"" << ficheroDatos << "\" using 1:2 title\""<<testMetodos[metodo].nombre_metodo<<"_real\", y(x) title \"" << testMetodos[metodo].nombre_metodo << "_teorico\"\n";

        salida << "set terminal pdf\n";
        salida << "set output \"" << testMetodos[metodo].nombre_metodo << ".pdf\"\n";
        salida << "replot\n";
        salida << "pause 5 \"Pulsa enter para continuar\"";


        salida.close();
        dibujar(nombrefichero);

    }
}

void TestOrdenacion::GenerarGrafica(Tiempos **T, int size, vector<int> metodos) {
    char res;
    do {
        cout << "Generar Grafica? (s/n): ";
        cin >>res;
    }while (res != 's' && res != 'n');

    string ficheroDatos;
    string ficheroGraf;
    if (res == 's') {
        ficheroGraf = "GrafComparacion.plt";
        ofstream salida(ficheroGraf.c_str());

        salida << "set title \"Comparación métodos de ordenación " << "\"\n";
        salida << "set key top left vertical inside\n"<<"set grid\n"<< "set xlabel \"Talla (n)\n"<<"set ylabel \"Tiempo (micros)\n";


        ficheroDatos = testMetodos[metodos[0]].nombre_metodo + ".dat";
        salida << "plot \"" << ficheroDatos << "\" using 1:2 with lines";
        for (int met = 1; met < metodos.size(); met++) {
            ficheroDatos = testMetodos[metodos[met]].nombre_metodo + ".dat";
            salida << ", \"" << ficheroDatos << "\" using 1:2 with lines";
        }

        salida << "\nset terminal pdf\n";
        salida << "set output \"GrafComparacion.pdf\"\n";
        salida << "replot\n";
        salida << "pause 5 \"Pulsa enter para continuar\"";
        salida.close();
        dibujar(ficheroGraf);

    }
}

void TestOrdenacion::GuardarEnArchivo(Tiempos **T, int size, vector<int> metodos) {
    char res;
    do {
        cout << "Guardar en fichero? (s/n): ";
        cin >>res;
    }while (res != 's' && res != 'n');

    string nombrefichero;
    if (res == 's') {
        for (int met = 0; met < metodos.size(); met++) {
            nombrefichero = testMetodos[metodos[met]].nombre_metodo + ".dat";
            ofstream salida(nombrefichero.c_str());

            for(int i=0;i<size;i++){
                salida<<T[met][i].elementos<<"\t"<<T[met][i].tiempo<<endl;
            }
            salida.close();
        }
        cout << "\t-> Ficheros ";
        for (int met = 0; met < metodos.size(); met++)
            cout << testMetodos[metodos[met]].nombre_metodo << ".dat ";
         cout << "generados\n";

        GenerarGrafica(T, size, metodos);
    }

}

void TestOrdenacion::GuardarEnArchivo(Tiempos *T, int size, int metodo) {
    char res;
    do {
        cout << "Guardar en fichero? (s/n): ";
        cin >>res;
    }while (res != 's' && res != 'n');

    string nombrefichero;
    if (res == 's') {
        nombrefichero = testMetodos[metodo].nombre_metodo + ".dat";

        ofstream salida(nombrefichero.c_str());
        for(int i=0;i<size;i++){
            salida<<T[i].elementos<<"\t"<<T[i].tiempo<<endl;
        }
        salida.close();

        cout << "\t-> Fichero "<<nombrefichero<< " generado\n";

        GenerarGrafica(T,size,metodo);
    }
}
