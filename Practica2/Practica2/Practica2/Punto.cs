using System;

namespace Practica2 {

	public class Punto {

		private double x;
		private double y;

		public double X {
			get { return x; }
			set { x = value; }
		}

		public double Y {
			get { return y; }
			set { y = value; }
		}

		public Punto (double x, double y) {
			this.x = x;
			this.y = y;
		}

		public double distancia (Punto p) {
			return Math.Sqrt ((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
		}

		public override string ToString () {
			string str;
			str = string.Format ("({0}, {1})", X, Y);
			return str;
		}
	}
}

