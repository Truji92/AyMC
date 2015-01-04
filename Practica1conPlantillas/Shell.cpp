

using namespace std;

template<class T>
void Shell<T>::ordenar(T t[], int ini, int fin) {
    fin--; 
    int i, j, inc, temp, TAM = fin + 1;
    for (inc = TAM / 2; inc > 0; inc /= 2) {
        for (i = inc; i < TAM; i++) {
            temp = t[i];
            for (j = i; j >= inc; j -= inc) {
                if (temp < t[j - inc]) {
                    t[j] = t[j - inc];
                } else {
                    break;
                }
            }
            t[j] = temp;
        }
    }
}

