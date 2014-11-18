/* 
 * File:   Ordenacion.h
 * Author: alejandro
 *
 */

#ifndef ORDENACION_H
#define	ORDENACION_H

class Ordenacion {
public:
    Ordenacion();
    virtual ~Ordenacion();
    virtual void ordenar(int t[], int ini, int fin);
};


#endif	/* ORDENACION_H */

