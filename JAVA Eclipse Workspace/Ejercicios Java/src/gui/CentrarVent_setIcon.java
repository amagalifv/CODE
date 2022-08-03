package gui;

import java.awt.Toolkit;
import java.awt.Image;
import javax.swing.*;

public class CentrarVent_setIcon {

	public static void main(String[] args) {
		miVentana2 ventana2=new miVentana2();

	}
}

	class miVentana2 extends JFrame{
		
		public miVentana2() {
			setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			setVisible(true);
			setBounds(200, 200, 500, 300);
// primeras 2 coord para ubicacion y segundas 2 para tamaño de la vent
			setResizable(false);//hace que no pueda ser redimensionable
			//setExtendedState(Frame.MAXIMIZED_BOTH);//se abre en pantalla completa
			Toolkit miPantalla=Toolkit.getDefaultToolkit();
			this.setTitle("Sistema de Registro de Pacientes");
			Image icono=miPantalla.getImage("src/gui/icono.png");
			setIconImage(icono);
		}
}

