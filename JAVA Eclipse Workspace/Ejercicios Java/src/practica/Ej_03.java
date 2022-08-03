package practica;
import javax.swing.JOptionPane;

public class Ej_03 {
	public static void main (String[] args) {
		
		String nombre;
		
		nombre=JOptionPane.showInputDialog(null, "Ingrese su nombre");
		System.out.println("Bienvenido "+nombre);
	}
}
