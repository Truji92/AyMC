/*
Programa que visualiza por consola el resultado de operaciones básicas en un conjunto de enteros con tamaño máximo limitado.
 */
#include <iostream>
#include <cstdlib>
using namespace std;
#include "ConjuntoInt.h"
void menu(void);
///////////// Programa principal ////////////

int main(void) {
    menu(); //muestra las opciones del programa
    cout << endl << "Fin Programa" << endl << endl;
    system("pause");
    return 0;
}

///////////// Definición función Menú///////////

void menu(void) {
    conjuntoInt cjt;
    cjt.vaciar();
    int opcion = 1;
    while (opcion != 0) {
        system("cls");
        cout << "Opciones: \n\n1.- Insertar_valores. \n2.- Buscar un valor en el vector. \n3.- Mostrar_vector. \n4.- Ordenar. \n0.- Salir\n" << endl;
        cin>>opcion;
        switch (opcion) {
            case 0: break;
            case 1:
            {
                int valor;
                cout << "Insertar el valor ";
                cin >> valor;
                cjt.insertar(valor); // lo almacena en el array
                cout << "Insertado el " << valor << endl;
                break;
            }
            case 2:
            {
                int valor;
                cout << "Insertar el valor a buscar ";
                cin >> valor;
                cout << "Se encuentra el " << valor << " ? " << (cjt.miembro(valor) ? "SI" : "NO") << endl;
                break;
            }
            case 3:
            {
                cout << "Visualizacion del vector: ";
                cjt.escribe();
                cout << endl;
                break;
            }
            case 4:
            {
                cout << "Ordenacion del vector: ";
                cjt.escribe();
                cout << endl;
                cjt.ordena();
                cout << "Vector ordenado: ";
                cjt.escribe();
                cout << endl;
                break;
            }
            default:
            {
                cout << "Opcion no " << opcion << " no valida. " << endl;

            }
        }
        system("pause");
    }
}
