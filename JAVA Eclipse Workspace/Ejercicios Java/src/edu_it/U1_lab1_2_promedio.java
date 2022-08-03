package edu_it;
import javax.swing.*;

/*
 * Promedio de 4 numeros ingresados por teclado 
 */

public class U1_lab1_2_promedio {

	public static void main(String[] args) {
		
		String cin1 = JOptionPane.showInputDialog("Ingrese el primer numero");
		double num1 = Double.parseDouble(cin1);
		
		String cin2 = JOptionPane.showInputDialog("Ingrese el segundo numero");
		double num2 = Double.parseDouble(cin2);
		
		String cin3 = JOptionPane.showInputDialog("Ingrese el tercer numero");
		double num3 = Double.parseDouble(cin3);
		
		String cin4 = JOptionPane.showInputDialog("Ingrese el cuarto numero");
		double num4 = Double.parseDouble(cin4);
		
		double resultado =0.0;
		
		resultado=(num1+num2+num3+num4);
		resultado/=4;
		System.out.println("Promedio: " + resultado);

	}

}
