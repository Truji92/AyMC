set title "Tiempos medios para el algoritmo de ordenación Insercion"
set key top left vertical inside
set grid
set xlabel "Talla (n)"
set ylabel "Tiempo (micros)"
y(x)=a+b*x+c*x*x
fit y(x) "Insercion.dat" using 1:2 via a,b,c
plot "Insercion.dat" using 1:2 title"Insercion_real", y(x) title "Insercion_teorico"
set terminal pdf
set output "Insercion.pdf"
replot
pause 5 "Pulsa enter para continuar"