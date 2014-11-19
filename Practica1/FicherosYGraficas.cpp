
#include "FicherosYGraficas.h"

TestOrdenacion* FicherosYGraficas::test = NULL;

void FicherosYGraficas::dibujar(string archivo){
#ifdef __linux__
    string comando = "gnuplot -p ";
    comando.append(archivo);
    system(comando.c_str());
#else
    system(archivo.c_str());
#endif
}

void FicherosYGraficas::GenerarGrafica(Tiempos *T, int size, int metodo) {
    char res;
    do {
        cout << "Generar Grafica? (s/n): ";
        cin >>res;
    }while (res != 's' && res != 'n');

    string nombrefichero;
    if (res == 's') {
        nombrefichero = test->getTestMetodos()[metodo].nombre_metodo;
        string ficheroDatos = nombrefichero + ".dat";
        nombrefichero += ".plt";

        ofstream salida(nombrefichero.c_str());

        salida << "set title \"Tiempos medios para el algoritmo de ordenación " << test->getTestMetodos()[metodo].nombre_metodo << "\"\n";
        salida << "set key top left vertical inside\n"<<"set grid\n"<< "set xlabel \"Talla (n)\"\n"<<"set ylabel \"Tiempo (micros)\"\n";
        if (metodo == 2 || metodo == 3|| metodo == 4)  //Shell QuickSort y MergeSort
            salida << "y(x)=a+b*x+c*x*log(x)/log(2)\n" << "fit y(x) \"" << ficheroDatos<< "\" using 1:2 via a,b,c\n";
        if (metodo == 0 || metodo == 1 ) //insercion burbuja
            salida << "y(x)=a+b*x+c*x*x\n"<< "fit y(x) \""<<ficheroDatos<< "\" using 1:2 via a,b,c\n";


        salida << "plot \"" << ficheroDatos << "\" using 1:2 title\""<<test->getTestMetodos()[metodo].nombre_metodo<<"_real\", y(x) title \"" << test->getTestMetodos()[metodo].nombre_metodo << "_teorico\"\n";

        salida << "set terminal pdf\n";
        salida << "set output \"" << test->getTestMetodos()[metodo].nombre_metodo << ".pdf\"\n";
        salida << "replot\n";
        salida << "pause 5 \"Pulsa enter para continuar\"";


        salida.close();
        dibujar(nombrefichero);

    }
}

void FicherosYGraficas::GenerarGrafica(Tiempos **T, int size, vector<int> metodos) {
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


        ficheroDatos = test->getTestMetodos()[metodos[0]].nombre_metodo + ".dat";
        salida << "plot \"" << ficheroDatos << "\" using 1:2 with lines";
        for (int met = 1; met < metodos.size(); met++) {
            ficheroDatos = test->getTestMetodos()[metodos[met]].nombre_metodo + ".dat";
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

void FicherosYGraficas::GuardarEnArchivo(Tiempos **T, int size, vector<int> metodos) {
    char res;
    do {
        cout << "Guardar en fichero? (s/n): ";
        cin >>res;
    }while (res != 's' && res != 'n');

    string nombrefichero;
    if (res == 's') {
        for (int met = 0; met < metodos.size(); met++) {
            nombrefichero = test->getTestMetodos()[metodos[met]].nombre_metodo + ".dat";
            ofstream salida(nombrefichero.c_str());

            for(int i=0;i<size;i++){
                salida<<T[met][i].elementos<<"\t"<<T[met][i].tiempo<<endl;
            }
            salida.close();
        }
        cout << "\t-> Ficheros ";
        for (int met = 0; met < metodos.size(); met++)
            cout << test->getTestMetodos()[metodos[met]].nombre_metodo << ".dat ";
         cout << "generados\n";

        GenerarGrafica(T, size, metodos);
    }

}

void FicherosYGraficas::GuardarEnArchivo(Tiempos *T, int size, int metodo) {
    char res;
    do {
        cout << "Guardar en fichero? (s/n): ";
        cin >>res;
    }while (res != 's' && res != 'n');

    string nombrefichero;
    if (res == 's') {
        nombrefichero = test->getTestMetodos()[metodo].nombre_metodo + ".dat";

        ofstream salida(nombrefichero.c_str());
        for(int i=0;i<size;i++){
            salida<<T[i].elementos<<"\t"<<T[i].tiempo<<endl;
        }
        salida.close();

        cout << "\t-> Fichero "<<nombrefichero<< " generado\n";

        GenerarGrafica(T,size,metodo);
    }
}