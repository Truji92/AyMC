#ifndef SHELL_H
#define SHELL_H

#include "Ordenacion.h"


class Shell : public Ordenacion
{
    public:
        Shell(){}
        void ordenar(int t[], int ini, int fin);
    protected:
    private:
};

#endif // SHELL_H
