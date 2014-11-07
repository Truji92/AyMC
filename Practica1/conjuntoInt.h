// Clase conjunto de enteros con tama�o máximo limitado.
#define MAXIMO 5  // TAMAÑO MÁXIMO 5

///////////// Declaración de la clase conjuntoInt ////////////

class conjuntoInt {
private:
    int tamano;
    int datos[MAXIMO];
public:
    void vaciar();
    void insertar(int n);
    bool miembro(int n);
    void ordena(int tam);
    void ordena();
    void escribe(int tam);
    void escribe();
    void clonar(conjuntoInt &c);
};
