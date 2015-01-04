

template<class T>
void Insercion<T>::ordenar(T t[], int ini, int fin) {
    int size = fin - ini;
    for (int i = 1; i < size; i++) {
        int x = t[i];
        int j = i - 1;

        while (j >= 0 && x < t[j]) {
            t[j + 1] = t[j];
            j--;
        }

        t[j + 1] = x;
    }
}
