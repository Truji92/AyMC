set title "Comparación métodos de ordenación "
set key top left vertical inside
set grid
set xlabel "Talla (n)
set ylabel "Tiempo (micros)
plot "Insercion.dat" using 1:2 with lines, "Burbuja.dat" using 1:2 with lines, "MergeSort.dat" using 1:2 with lines, "QuickSort.dat" using 1:2 with lines, "Shell.dat" using 1:2 with lines
set terminal pdf
set output "GrafComparacion.pdf"
replot
pause 5 "Pulsa enter para continuar"