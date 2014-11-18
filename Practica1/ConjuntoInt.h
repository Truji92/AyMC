// Clase conjunto de enteros con tama�o máximo limitado.

///////////// Declaración de la clase conjuntoInt ////////////

class ConjuntoInt {
private:
    int tamano;
    int nelementos;
    int *datos;
public:
    ConjuntoInt (int max= 0); //Constructor, por defecto tamaño 0;
    ~ConjuntoInt (); //Destructor, liberar memoria;
    void vaciar();
    void insertar(int n);
    bool miembro(int n);
    void ordena(int tam);
    void ordena();
    void escribe(int tam);
    void escribe();
    void clonar(ConjuntoInt &c);
    void generaVector ();
    int* getDatos();
};
