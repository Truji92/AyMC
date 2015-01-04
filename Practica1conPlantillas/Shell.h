#ifndef SHELL_H
#define SHELL_H

#include "Ordenacion.h"

template<class T>
class Shell : public Ordenacion<T>
{
    public:
        Shell(){}
        void ordenar(T t[], int ini, int fin);
    protected:
    private:
};

#include "Shell.cpp"
#endif // SHELL_H
