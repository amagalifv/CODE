package gui;
import javax.swing.*; 

public class creaVentana {

	public static void main(String[] args) {
		miVentana ventana1=new miVentana();//crea objeto ventana
		
		/*
		 * PUEDE HACERSE EN EL CONTRUCTOR O DESDE EL MAIN DE ESTA FORMA
		 * ventana1.setVisible(true);//para hacer visible la ventana
		 * ventana1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//termina el prog cuando se cierra 
		 */
	}

}

class miVentana extends JFrame{
	
	public miVentana() {
		setVisible(true);//para hacer visible la ventana
		setSize(500,300); // da tamaño a la ventana
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//termina el prog cuando se cierra 
		setLocation(500, 300);//pone la ventana en coords (x,y) la centra
	}
}
