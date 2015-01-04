// Clase conjunto de enteros con tama�o máximo limitado.
#ifndef CONJUNTO_H
#define CONJUNTO_H
///////////// Declaración de la clase conjuntoInt ////////////
template<class T>
class Conjunto {
private:
    int tamano;
    int nelementos;
    T *datos;
public:
    Conjunto (int max= 0); //Constructor, por defecto tamaño 0;
    ~Conjunto (); //Destructor, liberar memoria;
    void vaciar();
    void insertar(T n);
    bool miembro(T n);
    void ordena(int tam);
    void ordena();
    void escribe(int tam);
    void escribe();
    void clonar(Conjunto &c);
    void generaVector ();
    T* getDatos();
};

#include "Conjunto.cpp"
#endif //CONJUNTO_H