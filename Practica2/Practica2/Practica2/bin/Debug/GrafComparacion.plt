set title "Comparación Algoritmos"
set key top left vertical inside
set grid
set xlabel "Talla (n)
set ylabel "Tiempo (ms)
plot "Exahustiva.dat" using 1:2 with lines, "Divide y Vencerás.dat" using 1:2 with lines
set terminal pdf
set output "GrafComparacion.pdf"
replot
pause 5 "Pulsa enter para continuar"