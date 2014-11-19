/* 
 * File:   QuickSort.h
 * Author: alejandro
 *
 */

#ifndef QUICKSORT_H
#define	QUICKSORT_H

#include "Ordenacion.h"

class QuickSort : public Ordenacion {
private:
    
    int partition(int *t, int p, int r);
    void quicksort(int t[], int ini, int fin);
public:
    void ordenar(int t[], int ini, int fin);
};



#endif	/* QUICKSORT_H */

