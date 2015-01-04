/* 
 * File:   Insercion.h
 * Author: alejandro
 *
 */

#ifndef INSERCION_H
#define	INSERCION_H

#include "Ordenacion.h"

template<class T>
class Insercion : public Ordenacion<T> {
public:
    void ordenar(T t[], int ini, int fin);
};

#include "Insercion.cpp"
#endif	/* INSERCION_H */

