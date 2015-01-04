/* 
 * File:   Ordenacion.h
 * Author: alejandro
 *
 */

#ifndef ORDENACION_H
#define	ORDENACION_H

using namespace std;

template<class T>
class Ordenacion {
public:
    /**
     * Contructor vacío
     */
    Ordenacion(){}
    
    /**
     * Destructor
     */
    virtual ~Ordenacion(){}
    
    /**
     * Método que deberá implementar cada clase hija
     * @param t Vector a ordenar
     * @param ini posicion del primer elemento
     * @param fin posicion ultimo elemento
     */
    virtual void ordenar(T t[], int ini, int fin) {}
};


#endif	/* ORDENACION_H */

