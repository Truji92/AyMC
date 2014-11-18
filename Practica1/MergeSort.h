#ifndef MERGESORT_H
#define MERGESORT_H

#include "Ordenacion.h"


class MergeSort : public Ordenacion
{
    public:
        void mergesort(int *a, int*b, int low, int high);
        void merge(int *a, int *b, int low, int pivot, int high);
        void ordenar(int t[], int ini, int fin);
};

#endif // MERGESORT_H
