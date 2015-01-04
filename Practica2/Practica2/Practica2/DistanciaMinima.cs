using System;
using System.Collections.Generic;

namespace Practica2 {

	public class DistanciaMinima {

		public Random rng = new Random (1);

		#region Cálculo Exhaustivo

		//6 minutos -> 100000
		public double exhaustiva (Punto[] puntos, out Punto p1, out Punto p2, out int pi, out int pj) {

			p1 = puntos [0];
			p2 = puntos [1];
			pi = 0;
			pj = 1;
			double distanciaMin = puntos [0].distancia (puntos [1]);
			double distancia;

			for (int i = 0; i < puntos.Length; i++) {
				for (int j = i; j < puntos.Length; j++) {
					if (i != j) {
						distancia = puntos [i].distancia (puntos [j]);
						if (distanciaMin > distancia) {
							pi = i;
							pj = j;
							p1 = puntos [i];
							p2 = puntos [j];
							distanciaMin = distancia;

						}
					}
				}
			}
			return distanciaMin;
		}

		public double exhaustiva (Punto[] puntos) {
			double distancia;
			double distanciaMinima = Double.PositiveInfinity;
			for (int i = 0; i < puntos.Length; i++) {
				for (int j = i + 1; j < puntos.Length; j++) {
					distancia = puntos [i].distancia (puntos [j]);
					if (distanciaMinima > distancia) {
						distanciaMinima = distancia;

					}
				}
			}
			return distanciaMinima;
		}


		#endregion

		#region Cálculo Divide y Vencerás

		public double DyV_cuatroCuadrantes (Punto[] puntos) {
			return DyV_cuatroCuadrantes (puntos, puntos [0].distancia (puntos [1]));
		}

		public double DyV_cuatroCuadrantes (Punto[] puntos, double distanciaMin) {

			double distanciaMinima = distanciaMin;
			double distancia;
			Punto pivote;

			List<Punto>[] cuadrantes = new List<Punto>[4];
			for (int i = 0; i < 4; i++) {
				cuadrantes [i] = new List<Punto> ();
			}


			if (puntos.Length == 2) {
				distanciaMinima = puntos [0].distancia (puntos [1]);
			} else if (puntos.Length <= 60) {
				distanciaMinima = exhaustiva (puntos);
			} else {

				pivote = partition (puntos, ref cuadrantes);

				foreach (List<Punto> cuadrante in cuadrantes) {
					if (cuadrante.Count > 1) {
						distancia = DyV_cuatroCuadrantes (cuadrante.ToArray (), distanciaMinima);
						if (distanciaMinima > distancia)
							distanciaMinima = distancia;
					}
				}

				#region fronteraX 
				List<Punto> regionX = new List<Punto> ();

				foreach (List<Punto> cuadrante in cuadrantes) {
					foreach (Punto punto in cuadrante) {
						if (Math.Abs (punto.Y - pivote.Y) < distanciaMinima) {
							regionX.Add (punto);
						}
					}
				}

				if (regionX.Count > 1 && regionX.Count < puntos.Length) {
					distancia = DyV_cuatroCuadrantes (regionX.ToArray (), distanciaMinima);
					if (distancia < distanciaMinima) {
						distanciaMinima = distancia;
					}
				}
				#endregion

				#region fronteraY
				List<Punto> regionY = new List<Punto> ();

				foreach (List<Punto> cuadrante in cuadrantes) {
					foreach (Punto punto in cuadrante) {
						if (Math.Abs (punto.X - pivote.X) < distanciaMinima) {
							regionY.Add (punto);
						}
					}
				}

				if (regionY.Count > 1 && regionY.Count < puntos.Length) {
					distancia = DyV_cuatroCuadrantes (regionY.ToArray (), distanciaMinima);
					if (distancia < distanciaMinima) {
						distanciaMinima = distancia;
					}
				}
				#endregion

			}
			return distanciaMinima;
		}

		public Punto partition (Punto[] puntos, ref List<Punto>[] cuadrante) {

			bool particionIncorrecta = true;
			int i = 0;
			Punto pivote = puntos [0];
			//Punto pivote = puntos [rng.Next (0, puntos.Length)];
			while (particionIncorrecta && i <= puntos.Length) {
				if (i > 0) {
					cuadrante [0].Clear ();
					cuadrante [1].Clear ();
					cuadrante [2].Clear ();
					cuadrante [3].Clear ();
				}
				pivote = puntos [i]; 
				foreach (Punto punto in puntos) {
					if (punto.X > pivote.X) {
						if (punto.Y > pivote.Y) {
							cuadrante [0].Add (punto);
						} else {
							cuadrante [1].Add (punto);
						}
					} else {
						if (punto.Y > pivote.Y) {
							cuadrante [3].Add (punto);
						} else {
							cuadrante [2].Add (punto);
						}
					}
				}
				if (cuadrante [0].Count == puntos.Length || cuadrante [1].Count == puntos.Length / 4 ||
				    cuadrante [2].Count == puntos.Length || cuadrante [3].Count == puntos.Length / 4) {
					if (i == puntos.Length)
						throw new Exception ("Imposible particionar");
					i++;
				} else {
					particionIncorrecta = false;
				}
			}

			return pivote;
			
		}

		#endregion

	}
}

