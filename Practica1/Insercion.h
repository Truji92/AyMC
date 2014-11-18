/* 
 * File:   Insercion.h
 * Author: alejandro
 *
 */

#ifndef INSERCION_H
#define	INSERCION_H

#include "Ordenacion.h"

class Insercion : public Ordenacion {
public:
    Insercion(){}
    void ordenar(int t[], int ini, int fin);
};

#endif	/* INSERCION_H */

