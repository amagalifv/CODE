package ejercicios;

import javax.swing.JOptionPane;

public class Eje7_while {

	public static void main(String[] args) {
		
		String clave="Juan";
		String pass="";
		
		while(clave.equals(pass)==false) {
			pass=JOptionPane.showInputDialog("Introduce la contraseņa");
			
			if(clave.equals(pass)==false) {
				System.out.println("Contraseņa Incorrecta");
			}
		}
		System.out.println("Contraseņa correcta - Acceso permitido");
	}

}
