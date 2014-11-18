#include "Shell.h"
#include <iostream>
using namespace std;

void Shell::ordenar(int t[], int ini, int fin) {
    fin--; //Para facilitar la llamada (todos igual)
    int i, j, inc, temp, TAM = fin + 1;
    for (inc = TAM / 2; inc > 0; inc /= 2) {
        for (i = inc; i < TAM; i++) {
            temp = t[i];
            for (j = i; j >= inc; j -= inc) {
                if (temp < t[j - inc]) {
                    t[j] = t[j - inc];
                } else {
                    break;
                }
            }
            t[j] = temp;
        }
    }
}

