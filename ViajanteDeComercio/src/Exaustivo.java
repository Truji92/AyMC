
import java.io.File;
import java.util.LinkedList;
import java.util.Stack;

class Exaustivo extends Algoritmo {

    /*La solucion final es la lista de ciudades ordenadas
     * 
     */
    public Exaustivo(File f) {
        super(f);

    }

    //Metodo principal de ejecucion
    public void start() {
        Tini = System.currentTimeMillis();
        int i;
        int inicial = 0;
        super.setSolucion(new int[super.getDimension()]);
        super.setCoste_solucion(Integer.MAX_VALUE);

        Nodo.setVariables(super.getCostes_table(), super.getDimension());
        Stack<Nodo> hijos = new Stack<>();
        LinkedList<Integer> a = new LinkedList<>();
        a.add(inicial);
        System.out.println(a);
        Nodo esteNodo = new Nodo(a);
        hijos.addAll(esteNodo.hijos());
        System.out.println(hijos);
        esteNodo = hijos.pop();
        boolean salir = false;
        while (hijos.size() >= 0 && !salir) {
            if (!esteNodo.isFinal()) {
                if (esteNodo.getCoste() < super.getCoste_solucion()) {
                    hijos.addAll(esteNodo.hijos());
                }
            } else {
                if(esteNodo.getCoste() < super.getCoste()) {
                    super.setCoste_solucion(esteNodo.getCoste());
                    super.setSolucion(esteNodo.getCamino());
                }
            }
            if (hijos.size() == 0) {
                salir = true;
            } else {
                esteNodo = hijos.pop();
            }
        }
        Tfin = System.currentTimeMillis();
        tiempo = Tfin - Tini;
    }
        
        

}

class Nodo {

    static int max;
    static int[][] costes;

    LinkedList<Integer> camino;
    int coste;

    public Nodo(LinkedList<Integer> elCamino) {
        camino = elCamino;
        coste = 0;
        for (int i = 0, j = 1; i < camino.size() - 1; i++, j++) {
            coste += costes[camino.get(i)][camino.get(j)];
        }
    }

    public static void setVariables(int[][] losCostes, int elMax) {
        costes = losCostes;
        max = elMax;
    }

    public LinkedList<Nodo> hijos() {
        int este;
        LinkedList<Nodo> hijos = new LinkedList<>();
        for (int i = 0; i < this.max; i++) {
            if (!enElCamino(i)) {
                LinkedList<Integer> aux = (LinkedList<Integer>) camino.clone();
                aux.add(i);
                hijos.add(new Nodo(aux));
            }
        }
        return hijos;
    }

    private boolean enElCamino(int num) {
        for (Integer camino1 : camino) {
            if (camino1 == num) {
                return true;
            }
        }
        return false;
    }

    public boolean isFinal() {
        return camino.size() == max;
    }

    int getCoste() {
        return coste;
    }

    int[] getCamino() {
        int[] a = new int[camino.size()];
        for (int i = 0; i < camino.size(); i++) {
            a[i] = camino.get(i);
        }
        return a;
    }
}
	//Carga los datos del fichero en las matrices vx y vy

