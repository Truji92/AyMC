
import java.awt.*;
import java.awt.event.*;
import java.io.File;

class MyFrame extends Frame {

    Label lbl1, lbl2, lbl3, lbl4;
    TextField txbsemilla;
    Choice ch1, ch2;
    Panel panel, panel1, panel2;
    Button bt1;
    TextArea txtarea_results;
    String fileName = "noname";

    MyFrame() {
        this.setTitle("TSP");
        this.setLayout(new BorderLayout());
        this.setSize(700, 430);
        this.setBackground(Color.WHITE);
        panel = new Panel();
        panel1 = new Panel();
        panel2 = new Panel();

        txtarea_results = new TextArea();
        txtarea_results.setEditable(false);
        bt1 = new Button();
        bt1.setLabel("Pulsa para Ejecutar el algoritmo");
        bt1.setSize(1, 1);
        bt1.addActionListener(new Listener_bt1());
        lbl1 = new Label("Selecciona el dataset: ");
        lbl1.setAlignment(Label.LEFT);
        lbl1.setBackground(Color.WHITE);
        lbl2 = new Label("Selecciona el algoritmo: ");
        lbl2.setAlignment(Label.LEFT);
        lbl2.setBackground(Color.WHITE);

        lbl4 = new Label("");
        lbl4.setAlignment(Label.LEFT);
        lbl4.setBackground(Color.WHITE);
        ch1 = new Choice();
        ch2 = new Choice();
        ch1.add("Berlin52Reducido");
        ch1.add("berlin52");
        ch1.add("ch150");
        ch1.add("d567");
        ch2.add("Greedy");
        ch2.add("Exaustivo");
        panel.setLayout(new GridLayout(2, 1));
        panel1.setLayout(new GridLayout(4, 2));
        panel1.setBackground(Color.WHITE);
        panel1.add(lbl1);
        panel1.add(ch1);
        panel1.add(lbl2);
        panel1.add(ch2);

        panel1.add(bt1);
        panel1.add(lbl4);
        panel2.setBackground(Color.WHITE);
        panel2.add(txtarea_results);
        panel.add(panel1);
        panel.add(panel2);
        this.add(panel);

        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(1);
            }
        });
    }

    class Listener_bt1 implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent e) {

            lbl4.setText("Procesando, espere por favor...");
            txtarea_results.setText(null);
            int i1 = ch1.getSelectedIndex();
            int i2 = ch2.getSelectedIndex();

            File fichero = new File("");
            switch (i1) {
                case 0:
                    fichero = new File("berlin52lim.tsp");
                    break;
                case 1:
                    //ch130.tsp
                    fichero = new File("berlin52.tsp");
                    break;
                case 2:
                    //a280.tsp
                    fichero = new File("ch150.tsp");
                    break;
                case 3:
                    //p654.tsp
                    fichero = new File("d657.tsp");
                    break;
            }
            switch (i2) {
                case 0:
                    //Greedy
                    Greedy gr = new Greedy(fichero);
                    gr.cargaDatasetEnMatrices();
                    gr.calculaMatrizCostes();
                    gr.start();
                    txtarea_results.append("La soluci�n es " + gr.getSolucion());
                    txtarea_results.append("\ny el coste " + gr.getCoste());
                    txtarea_results.append("\n en un tiempo de " + gr.tiempo + " ms");
                    lbl4.setText("");
                    break;
                case 1:
                    //Exaustivo
                    Exaustivo objsh = new Exaustivo(fichero);
                    objsh.cargaDatasetEnMatrices();
                    objsh.calculaMatrizCostes();
                    objsh.start();
                    txtarea_results.append("La soluci�n es " + objsh.getSolucion());
                    txtarea_results.append("\ny el coste " + objsh.getCoste());
                    txtarea_results.append("\n en un tiempo de " + objsh.tiempo / 1000  + " segundos");
                    lbl4.setText("");
                    break;

            }
        }
    }

}

public class tsp {

    public static void main(String[] args) {
        new MyFrame().setVisible(true);
    }

}
