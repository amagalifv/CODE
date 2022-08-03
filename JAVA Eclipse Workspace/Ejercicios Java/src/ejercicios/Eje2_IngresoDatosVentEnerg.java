package ejercicios;
import javax.swing.*;

public class Eje2_IngresoDatosVentEnerg {
	
	public static void main(String[] args) {
		
		String nombreUsuario = JOptionPane.showInputDialog("Nombre: ");
		
		String edad = JOptionPane.showInputDialog("Edad: ");
		
		int edadInt = Integer.parseInt(edad);
		
		System.out.println("Hola " + nombreUsuario + ". El año que viene tendrás " 
		+ (edadInt+1) + " años");
	}
}
