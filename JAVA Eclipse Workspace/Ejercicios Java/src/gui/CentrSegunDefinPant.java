package gui;
import javax.swing.*;
import java.awt.Toolkit;
import java.awt.*;

public class CentrSegunDefinPant {

	public static void main(String[] args) {
		
		miVentana3 ventana3 = new miVentana3();
		
		ventana3.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		ventana3.setVisible(true);
		ventana3.setResizable(false);

	}

}

class miVentana3 extends JFrame{
	
	public miVentana3() {
		Toolkit miPantalla = Toolkit.getDefaultToolkit();
		Dimension tamPantalla = miPantalla.getScreenSize(); //dimension class
		int altPant = tamPantalla.height;
		int anchPant = tamPantalla.width;
		setSize(anchPant/2,altPant/2);
		setLocation(altPant/4, altPant/4);
	}
	
}
