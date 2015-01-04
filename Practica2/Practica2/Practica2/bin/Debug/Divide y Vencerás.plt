set title "Tiempos medios para el algoritmo Divide y Vencerás
set key top left vertical inside
set grid
set xlabel "Talla (n)"
set ylabel "Tiempo (micros)
y(x)=a+b*x+c*x*log(x)/log(2)
fit y(x) "Divide y Vencerás.dat" using 1:2 via a,b,c

plot "Divide y Vencerás.dat" using 1:2 title"Divide y Vencerás_real", y(x) title "Divide y Vencerás_teorico
set terminal pdf
set output "Divide y Vencerás.pdf
replot
pause 5 "Pulsa enter para continuar"
