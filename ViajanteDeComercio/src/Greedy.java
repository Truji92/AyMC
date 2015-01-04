
import java.io.File;

class Greedy extends Algoritmo {

    /*
     *La solucion final es la lista de ciudades ordenadas
     */
    //Constructor
    public Greedy(File f) {
        super(f);
    }

    //Inicializa la tabla visitados al valor que se le pase
    private void inicializar_visitados(boolean t[][], boolean b) {
        int n = super.getDimension();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                t[i][j] = b;
            }
        }
    }

    //Inicializa la columna column de visitados a b
    private void actualiza_columna_visitados(boolean t[][], boolean b, int column) {
        int n = super.getDimension();
        for (int i = 0; i < n; i++) {
            t[i][column] = b;
        }
    }

    //Metodo principal de ejecucion
    @Override
    public void start() {
        int i;
        int primerInicial = seleccionNodoInicial();
        int inicial = 0;
        int temp = 2147483647;  //Mayor valor de un int en java (representado por 32 bits)
        int i_temp = 0; //Indice (ciudad) del coste elegido
        int n = super.getDimension();
        super.setSolucion(new int[super.getDimension()]);
        super.setCoste_solucion(0);
        boolean visitados[][] = new boolean[n][n];
        inicializar_visitados(visitados, false);
        super.setSolucionAt(0, inicial);
        actualiza_columna_visitados(visitados, true, inicial);
        super.setCoste_solucion(0);
        
        i = 1;
        while (i < n) {
            i_temp = siguienteMenor(inicial, visitados);
            super.setSolucionAt(i, i_temp);
            super.setCoste_solucion(super.getCoste_solucion() + super.getCostes(inicial, i_temp));
            actualiza_columna_visitados(visitados, true, i_temp);
            inicial = i_temp;
            i++;
        }
        //Algoritmo Voraz
        super.setCoste_solucion(super.getCoste_solucion() + super.getCostes(inicial, 0));
        // coste al nodo inicial
    }
    
    private int siguienteMenor(int punto, boolean visitados[][]) {
        int i;
        int min = 0;
        int costeMinimo = Integer.MAX_VALUE;
        
        for (i = 0; i < super.getDimension(); i++) {
            if (super.getCostes(punto, i) < costeMinimo && visitados[punto][i] == false) {
                costeMinimo = super.getCostes(punto,i);
                min = i;
            }
        }
        return min;
    }
    
    private int seleccionNodoInicial() {
        int sumastotales[] = new int[super.getDimension()];
        for (int i = 0; i < super.getDimension(); i++) {
            for (int j = 0; j < super.getDimension(); j++) {
                sumastotales[i] = super.getCostes(i, j);
            }
        }
        
        int nodoPeor = 0;
        int costePeor = sumastotales[0];
        for (int i = 1; i < sumastotales.length; i++) {
            if (costePeor < sumastotales[i]) {
                costePeor = sumastotales[i];
                nodoPeor = i;
            }
        }
        return nodoPeor;
    }
}
