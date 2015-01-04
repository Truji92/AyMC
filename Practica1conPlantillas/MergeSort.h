#ifndef MERGESORT_H
#define MERGESORT_H

#include "Ordenacion.h"

template<class T>
class MergeSort : public Ordenacion<T>
{
        void mergesort(T *a, T*b, int low, int high);
        void merge(T *a, T *b, int low, int pivot, int high);
    public:
        void ordenar(T t[], int ini, int fin);
};

#include "MergeSort.cpp"
#endif // MERGESORT_H
