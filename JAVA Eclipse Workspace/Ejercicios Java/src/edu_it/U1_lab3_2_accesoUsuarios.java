package edu_it;
import java.util.Objects;

/*
 * REalice un programa q indique usuario y contraseña con maximo 3 intentos, si supera los 3 
 * intentos con datos inválidos mostrar un msj indicando que se ha bloqueado el usuario.
 */

import javax.swing.*;

public class U1_lab3_2_accesoUsuarios {

	public static void main(String[] args) {
		
		int i=0;
		boolean bandera=true;
		String usuario = "Admin";
		String contrasenia = "123";
		
		String inUsuario;
		String inContrasenia;
		
		while ( bandera == true && i<3 ) {
			
			inUsuario = JOptionPane.showInputDialog("Usuario: ");
			inContrasenia = JOptionPane.showInputDialog("Contraseña: ");
			
			if (Objects.equals(usuario, inUsuario) && Objects.equals(contrasenia, inContrasenia)) {
				bandera = false;
				JOptionPane.showMessageDialog(null, "Acceso Confirmado", "Access Acepted", 1);
			} else {
				JOptionPane.showMessageDialog(null, "Usuario o Contraseña Incorrecta", "Alerta",2);
			}
			
			i++;
			
		}
		
		if(i==3) {
			JOptionPane.showMessageDialog(null, "Usuario Bloqueado", "Error",0);
		}
		
	}

}
