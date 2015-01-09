
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

class Algoritmo {

    /*La solucion final es la lista de ciudades ordenadas
     * 
     */
    private final File fich;
    private double vx[];
    private double vy[];
    private int costes[][];
    private int solucion[]; //Solucion final
    private int coste_solucion; //Coste de la solucion final
    private int n; //Dimension del dataset
    
    protected long Tini, Tfin, tiempo;

    public Algoritmo(File f) {
        fich = f;

    }

    //Metodo principal de ejecucion
    public void start() {

        System.out.println("Esto no debe salir por consola al sobreescribirlo");

    }

    //Carga los datos del fichero en las matrices vx y vy
    public void cargaDatasetEnMatrices() {
        int i, caux, row, column;
        String linea0 = null;
        String numero;
        char c;
        boolean notnumber;  
        try {
            try (BufferedReader entrada = new BufferedReader(new FileReader(fich))) {
                //Recoge el numero de elementos del dataset
                linea0 = entrada.readLine();
                linea0 = entrada.readLine();
                linea0 = entrada.readLine();
                linea0 = entrada.readLine();
                i = 0;
                while (linea0.charAt(i) != ':') {
                    i++;
                }
                notnumber = false;
                numero = "";
                i++;
                    while (!notnumber) {
                    if (i == linea0.length()) {
                        notnumber = true;
                    } else {
                        c = linea0.charAt(i);
                        if ((c != ' ') && (c != '\n') && (c != '\t')) {
                            numero += c;
                        }
                        i++;
                    }
                }
                if (i == linea0.length()) {
                    n = Integer.parseInt(numero);
                } else {
                    n = 0;
                }
                vx = new double[n];
                vy = new double[n];
                //Relleno los vectores vx y vy
                linea0 = entrada.readLine();
                linea0 = entrada.readLine();
                for (row = 0; row < n; row++) {
                    for (column = 0; column <= 2; column++) {
                        notnumber = false;
                        numero = "";
                        while (!notnumber) {
                            caux = entrada.read();
                            c = (char) caux;
                            if ((c == ' ') || (c == '\n') || (c == '\t')) {
                                if (numero.length() != 0) {
                                    if (column == 1) {
                                        vx[row] = Double.parseDouble(numero);
                                    } else if (column == 2) {
                                        vy[row] = Double.parseDouble(numero);
                                    }
                                    notnumber = true;
                                }
                            } else {
                                numero += c;
                            }
                        }
                    }
                }
            }
        } catch (IOException ex) {
        }
    }

    //Calcula la matriz de costes a partir de los vectores vx y vy
    public void calculaMatrizCostes() {
        int i, j;
        double xd, yd;
        costes = new int[n][n];
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                xd = vx[i] - vx[j];
                yd = vy[i] - vy[j];
                costes[i][j] = (int) Math.round(Math.sqrt((xd * xd) + (yd * yd)));
            }
        }
    }

    //Obtiene la dimension
    protected int getDimension() {
        return n;
    }

    //Devuelve la solucion en un string
    public String getSolucion() {
        String sol = new String();
        for (int i = 0; i < n; i++) {
            sol += solucion[i] + " ";
        }
        return sol;
    }

    public int getCoste() {
        return coste_solucion;
    }

    //Copia la matriz origen en la matriz destino
    private void copiarMatrices(int origen[], int destino[]) {
        for (int i = 0; i < n; i++) {
            destino[i] = origen[i];
        }
    }

    public double[] getVx() {
        return vx;
    }

    public void setVx(double[] vx) {
        this.vx = vx;
    }

    public double[] getVy() {
        return vy;
    }

    public void setVy(double[] vy) {
        this.vy = vy;
    }

    public int getCostes(int x, int y) {
        return costes[x][y];
    }

    public void setCostes(int[][] costes) {
        this.costes = costes;
    }

    protected void setSolucionAt(int indice, int valor) {
        this.solucion[indice] = valor;
    }

    public int getCoste_solucion() {
        return coste_solucion;
    }

    public void setCoste_solucion(int coste_solucion) {
        this.coste_solucion = coste_solucion;
    }

    public void setSolucion(int[] solucion) {
        this.solucion = solucion;
    }
    
    public int[][] getCostes_table() {
        return costes;
    }

}
