package ejercicios;

import java.util.Scanner;

import javax.swing.JOptionPane;

public class Eje6_switch {

	public static void main(String[] args) {
		
		Scanner entrada = new Scanner(System.in);
		
		System.out.println("1-Cuadrado\n 2-Rect�ngulo\n 3-Tri�ngulo\n 4-C�rculo\n ");
		
		int figura = entrada.nextInt();
		
		switch(figura) {
		
			case 1:
				int lado=Integer.parseInt(JOptionPane.showInputDialog("Introduce un lado"));
				
				System.out.println("El �rea del cuadrado es "+ Math.pow(lado,2));
		
				break;
				
			case 2:
				
				int baseR=Integer.parseInt(JOptionPane.showInputDialog("Introduce la base"));
				
				int alturaR=Integer.parseInt(JOptionPane.showInputDialog("Introduce la altura"));
				
				System.out.println("El �rea del rect�ngulo es "+ baseR*alturaR);
				
				break;
				
			case 3:
				
				int base=Integer.parseInt(JOptionPane.showInputDialog("Introduce la base"));
				
				int altura=Integer.parseInt(JOptionPane.showInputDialog("Introduce la altura"));
				
				System.out.println("El �rea del rect�ngulo es "+ (base*altura)/2);
				
				break;
				
			case 4:
				int radio=Integer.parseInt(JOptionPane.showInputDialog("Introduce el radio"));
				
				System.out.print("El area del c�rculo es ");
				System.out.printf("%1.2f", Math.PI*(Math.pow(radio, 2)));
				
				break;
			
			default:
				System.out.println("La opci�n no es correcta");
		}
	}

}
