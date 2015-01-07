set title "Tiempos medios para el algoritmo Divide y Vencerás
set key top left vertical inside
set grid
set xlabel "Talla (n)"
set ylabel "Tiempo (micros)
y(x)=a+c*x**b
fit y(x) "Divide y Vencerás.dat" using 1:2 via a,b,c

plot "Divide y Vencerás.dat" using 1:2 title"Divide y Vencerás_real", y(x) title "Divide y Vencerás_teorico
set terminal pdf
set output "Divide y Vencerás potencia.pdf
replot
pause 5 "Pulsa enter para continuar"
