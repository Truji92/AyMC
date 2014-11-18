set title "Tiempos medios para el algoritmo de ordenación Shell"
set key top left vertical inside
set grid
set xlabel "Talla (n)"
set ylabel "Tiempo (micros)"
y(x)=a+b*x+c*x*x
fit y(x) "Shell.dat" using 1:2 via a,b,c
plot "Shell.dat" using 1:2 title"Shell_real", y(x) title "Shell_teorico"
set terminal pdf
set output "Shell.pdf"
replot
pause 5 "Pulsa enter para continuar"