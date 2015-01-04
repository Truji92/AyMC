set title "Tiempos medios para el algoritmo Exahustiva
set key top left vertical inside
set grid
set xlabel "Talla (n)"
set ylabel "Tiempo (ms)
y(x)=a+b*x+c*x*x
fit y(x) "Exahustiva.dat" using 1:2 via a,b,c

plot "Exahustiva.dat" using 1:2 title"Exahustiva_real", y(x) title "Exahustiva_teorico
set terminal pdf
set output "Exahustiva.pdf
replot
pause 5 "Pulsa enter para continuar"
