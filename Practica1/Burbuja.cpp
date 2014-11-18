#include "Burbuja.h"

void Burbuja::ordenar(int t[], int ini, int fin) {
    int i, j;
    int aux;
    int size = fin - ini;

    for (i = 0; i < size - 1; i++) {
        for (j = size - 1; j > i; j--) {
            if (t[j] < t[j - 1]) {
                aux = t[j];
                t[j] = t[j - 1];
                t[j - 1] = aux;
            }
        }
    }
}
