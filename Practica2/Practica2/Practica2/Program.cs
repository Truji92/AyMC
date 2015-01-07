using System;
using System.Collections.Generic;
using System.Threading;
using System.IO;

namespace Practica2 {

	class MainClass {

		public 	static void Main (string[] args) {
			/*************************************
			 * PARA MEDICION DIRECTA 
			 * ***********************************
			HiloMain main = new HiloMain ();
			Thread hilo = new Thread (main.principal, 1 * 1024 * 1024 * 1024); //1gb stack
			hilo.Start ();
			**************************************/

			/*************************************
			* PARA GRAFICAS
			* ***********************************/
			HiloMain main = new HiloMain ();
			Thread hilo = new Thread (main.generaGrafica, 1 * 1024 * 1024 * 1024);
			hilo.Start ();
		}
	}

	class HiloMain {
		public void principal () {

			DistanciaMinima distMinima = new DistanciaMinima ();

			Punto[] puntos;
			puntos = new Punto[1000000];

			TimeSpan start;
			TimeSpan stop;

			Random rnd = new Random ();

			Console.WriteLine ("Generando puntos");
			for (int i = 0; i < puntos.Length; i++) {
				puntos [i] = new Punto (rnd.NextDouble () * 10000000, rnd.NextDouble () * 10000000);
				//Console.WriteLine ("x: {0:F1} y: {1:F1}", puntos [i].X, puntos [i].Y);
			}
			/*for (int i = 0; i < puntos.Length; i++) {
				if (i % 2 == 0)
					puntos [i] = new Punto (i, -i);
				else
					puntos [i] = new Punto (-i, i);
				//Console.WriteLine ("x: {0:F1} y: {1:F1}", puntos [i].X, puntos [i].Y);
			}
		*/

			double dist = 0;

			start = new TimeSpan (DateTime.Now.Ticks);
			//dist = distMinima.exhaustiva (puntos);
			stop = new TimeSpan (DateTime.Now.Ticks);
			Console.WriteLine ("La distacia minima exhaustiva es: {0:F1}", dist);
			Console.WriteLine ("Tiempo: {0:F1} minutos", stop.Subtract (start).TotalMilliseconds / 1000 / 60);

			try {
				Console.WriteLine ("Inicio DyV");
				start = new TimeSpan (DateTime.Now.Ticks);
				dist = distMinima.DyV_cuatroCuadrantes (puntos);
				stop = new TimeSpan (DateTime.Now.Ticks);
				Console.WriteLine ("La distancia minima con DyV es: {0:F1}", dist);
				Console.WriteLine ("Tiempo: {0:F1} minutos", stop.Subtract (start).TotalMilliseconds / 1000 / 60);
			} catch (Exception e) {
				Console.WriteLine (e.Message);
			}


		}

		public void generaGrafica () {
			int[] tallas = { 50, 500, 1000, 3000, 5000, 10000 };
			int numeroRepeticiones = 100; //Veces que se repetirá para cada talla de cara a obtener una media

			double[] medidas = new Double[tallas.Length];
			for (int i = 0; i < medidas.Length; i++) {
				medidas [i] = 0;
			}

			DistanciaMinima distMinima = new DistanciaMinima ();

			Punto[] puntos;

			TimeSpan start;
			TimeSpan stop;

			Random rnd = new Random ();

			for (int talla = 0; talla < tallas.Length; talla++) {
				for (int i = 0; i < numeroRepeticiones; i++) {
					puntos = new Punto[tallas [talla]];

					//Generacion de puntos
					for (int j = 0; j < puntos.Length; j++) {
						puntos [j] = new Punto (rnd.NextDouble () * 10000000, rnd.NextDouble () * 10000000);
					} 

					start = new TimeSpan (DateTime.Now.Ticks);
					//distMinima.DyV_cuatroCuadrantes (puntos);
					distMinima.exhaustiva (puntos);
					stop = new TimeSpan (DateTime.Now.Ticks);

					medidas [talla] += stop.Subtract (start).TotalMilliseconds;
				}

				medidas [talla] /= numeroRepeticiones;
			}

			//crearArchivoDatos ("Divide y Vencerás", medidas, tallas);
			//crearArchivoPlot ("Divide y Vencerás");
			crearArchivoDatos ("Exahustiva", medidas, tallas);
			crearArchivoPlot ("Exahustiva");
		}

		private void crearArchivoDatos (string metodo, Double[] medidas, int[] tallas) {
			try {
				StreamWriter salida = new StreamWriter (metodo + ".dat");

				for (int i = 0; i < medidas.Length; i++) {
					salida.WriteLine (tallas [i] + " " + medidas [i]);
				}

				salida.Close ();
			} catch (Exception e) {
				Console.WriteLine ("Exception: " + e.Message);
			}
		}

		private void crearArchivoPlot (string metodo) {
		
			string nombrefichero;
			string ficheroDatos;
			nombrefichero = metodo + ".plt";
			ficheroDatos = metodo + ".dat";

			try {

				StreamWriter salida = new StreamWriter (nombrefichero);

				salida.WriteLine ("set title \"Tiempos medios para el algoritmo " + metodo);
				salida.WriteLine ("set key top left vertical inside\n" + "set grid\n" + "set xlabel \"Talla (n)\"\n" + "set ylabel \"Tiempo (ms)");

				if (metodo == "Exahustiva")
					salida.WriteLine ("y(x)=a+b*x+c*x*x\n" + "fit y(x) \"" + ficheroDatos + "\" using 1:2 via a,b,c\n");
				else
					salida.WriteLine ("y(x)=a+b*x+c*x*log(x)/log(2)\n" + "fit y(x) \"" + ficheroDatos + "\" using 1:2 via a,b,c\n");

				salida.WriteLine ("plot \"" + ficheroDatos + "\" using 1:2 title\"" + metodo + "_real\", y(x) title \"" + metodo + "_teorico");
				salida.WriteLine ("set terminal pdf");
				salida.WriteLine ("set output \"" + metodo + ".pdf");
				salida.WriteLine ("replot");
				salida.WriteLine ("pause 5 \"Pulsa enter para continuar\"");

				salida.Close ();

				Console.WriteLine ("ARCHIVO GENERADO");
			} catch (Exception e) {
				Console.WriteLine ("Exception: " + e.Message);
			}
		}
	}
}
