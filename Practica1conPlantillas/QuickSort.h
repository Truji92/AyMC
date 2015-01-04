/* 
 * File:   QuickSort.h
 * Author: alejandro
 *
 */

#ifndef QUICKSORT_H
#define	QUICKSORT_H

#include "Ordenacion.h"

template<class T>
class QuickSort : public Ordenacion<T> {
private:
    
    int partition(T *t, int p, int r);
    void quicksort(T t[], int ini, int fin);
public:
    void ordenar(T t[], int ini, int fin);
};

#include "QuickSort.cpp"

#endif	/* QUICKSORT_H */

