package ejercicios;

import javax.swing.JOptionPane;

public class Eje7_while {

	public static void main(String[] args) {
		
		String clave="Juan";
		String pass="";
		
		while(clave.equals(pass)==false) {
			pass=JOptionPane.showInputDialog("Introduce la contraseña");
			
			if(clave.equals(pass)==false) {
				System.out.println("Contraseña Incorrecta");
			}
		}
		System.out.println("Contraseña correcta - Acceso permitido");
	}

}
