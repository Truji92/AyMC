import java.io.*;
import java.util.*;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

class Greedy extends Algoritmo{
	
	/*
	 *La solucion final es la lista de ciudades ordenadas
	 */
	
	
	
	//Constructor
	public Greedy(File f) {
		super( f);
	}
	
	
	//Inicializa la tabla visitados al valor que se le pase
	private void inicializar_visitados(boolean t[][], boolean b) {
		int n = super.getDimension();
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				t[i][j] = b;
			}
		}
	}
	
	
	//Inicializa la columna column de visitados a b
	private void actualiza_columna_visitados(boolean t[][], boolean b, int column) {
		int n = super.getDimension();
		for(int i=0;i<n;i++) {
			t[i][column] = b;
		}
	}
	
	
	//Metodo principal de ejecucion
	public void start() {
        int i;
        int inicial = 0;
        int temp = 2147483647;  //Mayor valor de un int en java (representado por 32 bits)
        int i_temp = 0; //Indice (ciudad) del coste elegido
        int n = super.getDimension();
        super.setSolucion(new int[super.getDimension()]);
		super.setCoste_solucion(0);
        boolean visitados[][] = new boolean[n][n];
        inicializar_visitados(visitados,false);
        super.setSolucionAt(0, inicial);
        actualiza_columna_visitados(visitados,true,inicial);
        super.setCoste_solucion(0);
       
        //Algoritmo Voraz
        super.setCoste_solucion(super.getCoste_solucion() + super.getCostes(inicial,0)); 
        // coste al nodo inicial
	}
	
	
	

}
