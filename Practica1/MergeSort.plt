set title "Tiempos medios para el algoritmo de ordenación MergeSort"
set key top left vertical inside
set grid
set xlabel "Talla (n)"
set ylabel "Tiempo (micros)"
y(x)=a+b*x+c*x*log(x)/log(2)
fit y(x) "MergeSort.dat" using 1:2 via a,b,c
plot "MergeSort.dat" using 1:2 title"MergeSort_real", y(x) title "MergeSort_teorico"
set terminal pdf
set output "MergeSort.pdf"
replot
pause 5 "Pulsa enter para continuar"