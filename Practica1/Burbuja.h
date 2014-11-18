/* 
 * File:   Burbuja.h
 * Author: alejandro
 *
 */

#ifndef BURBUJA_H
#define	BURBUJA_H

#include "Ordenacion.h"

class Burbuja : public Ordenacion {
public:
    Burbuja(){}
    void ordenar(int t[], int ini, int fin);
};


#endif	/* BURBUJA_H */

