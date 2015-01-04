/* 
 * File:   Burbuja.h
 * Author: alejandro
 *
 */

#ifndef BURBUJA_H
#define	BURBUJA_H

#include "Ordenacion.h"

template<class T>
class Burbuja : public Ordenacion<T> {
public:
    void ordenar(T t[], int ini, int fin);
};

#include "Burbuja.cpp"
#endif	/* BURBUJA_H */

