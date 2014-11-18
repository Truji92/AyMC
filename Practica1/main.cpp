#include <iostream>
#include <cstdlib>
#include "TestOrdenacion.h"

using namespace std;

#ifdef __linux__
#define CLEAR "clear"
#else
#define CLEAR "cls"
#endif


int Menu() {

    int opcion;
    do {
        system(CLEAR);
        cout << "\n\t\t*** Estuido de Metodos de Ordenación ***\n\n"
             << "\t\t1- Probar los metodos de ordenación" <<  endl
             << "\t\t2- Obtener el caso medio de un metodo" << endl
             << "\t\t3- Comparar metodos" << endl
             << "\t\t0- Salir" << endl
             << "\t\t--------------------"
             << "\n\t\t >>> ";
             cin >> opcion;
    } while (opcion < 0 || opcion > 3);
    return opcion;
}


int subMenuCasoMedio(TestOrdenacion &test) {
    int opcion;

    do{
        cout << "\n\t\t*** Metodo a estudiar para el caso medio ***" << endl;
        for (int i = 0; i < test.getTestMetodos().size(); i++)
            cout << "\t\t"<<i+1<<"- " << test.getTestMetodos()[i].nombre_metodo << endl;
        
        cout << "\n\t\t >>> ";
        cin >> opcion;
    } while (opcion < 0 || opcion > test.getTestMetodos().size());
    return opcion - 1;
}

void subRutinaComparacion(TestOrdenacion &test){
    vector<int> metodos;



    system(CLEAR);
    cout <<  "\n\t\t *** Comparacion de metodos de ordenación" << endl << endl;
    for (int i = 0; i < test.getTestMetodos().size(); i++)
        cout << "\t\t " <<i+1<<"- "<< test.getTestMetodos()[i].nombre_metodo << endl;
    
    cout << "\t\t---------------------\n";
    int aux;
    int i = 1;
    do {
        do {
            if (i <= 2)
                cout << "\n\t\t Introduzca metodo" << i << ": ";
            else
                cout << "\n\t\t Introduzca metodo" << i << " (o 0 para terminar): ";
            cin >> aux;
        } while (aux == 0 && i <= 2);
        if (aux <= 5 && aux >= 1) {
            metodos.push_back(aux-1);
            i++;
        }
    } while (aux != 0);

    test.compararMetodos(metodos);

}


int main()
{
    int opcion;
    TestOrdenacion test;

    do {
        opcion = Menu();
        switch (opcion){
        case 1:
            test.comprobarMetodos();
            break;
        case 2:
            test.estudiarMetodo(subMenuCasoMedio(test));
            break;
        case 3:
            subRutinaComparacion(test);
            break;
        }
    } while (opcion != 0);

    return 0;
}
