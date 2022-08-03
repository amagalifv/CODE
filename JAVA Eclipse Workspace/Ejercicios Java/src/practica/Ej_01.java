package practica;

import javax.swing.JOptionPane;

/* Pide 2 numeros enteros por teclado y te da la opción de elegir qué operación realizar,
 *  luego muestra el resultado de la operación elegida
 */

public class Ej_01 {
	
	public static void main(String[] args) {
		int num1;
		int num2;
		int result=0;
		double resultDivi=0;
		
		num1=Integer.parseInt(JOptionPane.showInputDialog(null, "Ingrese el primer numero: "));
		num2=Integer.parseInt(JOptionPane.showInputDialog(null, "Ingrese el segundo numero: "));
		
		int opcion;
		opcion=Integer.parseInt(JOptionPane.showInputDialog(null, "Ingrese la operación a realizar:\n"
				+ "- 1 - para suma \n - 2 - para resta \n - 3 - para multiplicación\n "
				+ "- 4 - para división\n - 5 - para módulo\n"));
		
		switch (opcion) {
			case 1: 
				result=num1+num2;
				break;
			case 2:
				result=num1-num2;
				break;
			case 3: 
				result=num1*num2;
				break;
			case 4: 
				resultDivi=(double)num1/num2;
				break;
			case 5: 
				result=num1%num2;
				break;
		}
		
		if(opcion==4) {
			System.out.println("El resultado es "+resultDivi);
		} else {
			System.out.println("El resultado es "+result);
		}
	
	}
}

