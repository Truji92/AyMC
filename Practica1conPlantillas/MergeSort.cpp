

template<class T>
void MergeSort<T>::ordenar(T t[], int ini, int fin) {
    T *b = new T[fin - ini];
    mergesort(t, b, ini, fin - 1);
    t = b;
}

template<class T>
void MergeSort<T>::mergesort(T *a, T *b, int low, int high) {
    int pivot;
    if (low < high) {
        pivot = (low + high) / 2;
        mergesort(a, b, low, pivot);
        mergesort(a, b, pivot + 1, high);
        merge(a, b, low, pivot, high);
    }
}

template<class T>
void MergeSort<T>::merge(T *a, T *b, int low, int pivot, int high) {
    int h, i, j, k;
    h = low;
    i = low;
    j = pivot + 1;

    while ((h <= pivot)&&(j <= high)) {
        if (a[h] <= a[j]) {
            b[i] = a[h];
            h++;
        } else {
            b[i] = a[j];
            j++;
        }
        i++;
    }
    if (h > pivot) {
        for (k = j; k <= high; k++) {
            b[i] = a[k];
            i++;
        }
    } else {
        for (k = h; k <= pivot; k++) {
            b[i] = a[k];
            i++;
        }
    }
    for (k = low; k <= high; k++) a[k] = b[k];
}