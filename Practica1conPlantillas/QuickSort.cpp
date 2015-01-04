

template<class T>
void QuickSort<T>::ordenar(T t[], int ini, int fin) {
    quicksort(t, ini, fin-1);
}

template<class T>
void QuickSort<T>::quicksort(T t[], int ini, int fin) {
    int pivote;
    if (ini < fin) {
        pivote = partition(t, ini, fin);
        quicksort(t, ini, pivote);
        quicksort(t, pivote+1, fin);
    }
}

template<class T>
int QuickSort<T>::partition(T* t, int p, int r) {
    int piv = t[p];
    int i = p-1;
    int j = r+1;
    do {
        do {
            j--;
        } while (t[j]>piv);
        do {
            i++;
        }while(t[i]<piv);
        if (i < j) {
            int aux = t[i];
            t[i] = t[j];
            t[j] = aux;
        }
    } while(i < j);
    return j;
}
