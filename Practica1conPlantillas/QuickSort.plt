set title "Tiempos medios para el algoritmo de ordenación QuickSort"
set key top left vertical inside
set grid
set xlabel "Talla (n)"
set ylabel "Tiempo (micros)"
y(x)=a+b*x+c*x*log(x)/log(2)
fit y(x) "QuickSort.dat" using 1:2 via a,b,c
plot "QuickSort.dat" using 1:2 title"QuickSort_real", y(x) title "QuickSort_teorico"
set terminal pdf
set output "QuickSort.pdf"
replot
pause 5 "Pulsa enter para continuar"