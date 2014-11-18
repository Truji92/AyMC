set title "Tiempos medios para el algoritmo de ordenación Burbuja"
set key top left vertical inside
set grid
set xlabel "Talla (n)"
set ylabel "Tiempo (micros)"
y(x)=a+b*x+c*x*x
fit y(x) "Burbuja.dat" using 1:2 via a,b,c
plot "Burbuja.dat" using 1:2 title"Burbuja_real", y(x) title "Burbuja_teorico"
set terminal pdf
set output "Burbuja.pdf"
replot
pause 5 "Pulsa enter para continuar"