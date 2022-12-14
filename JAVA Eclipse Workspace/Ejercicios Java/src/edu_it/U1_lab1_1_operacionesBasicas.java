package edu_it;
import java.util.*;

/*
 *Declare e inicie 2 variables que permitan realizar y mostrar en consola las operaciones basicas matematicas 
 *(suma, resta, division, multiplicacion) 
 */

public class U1_lab1_1_operacionesBasicas {

	public static void main(String[] args) {
		
		Scanner cin = new Scanner (System.in);
		double resultado=0;
		System.out.println("Ingrese la operacion a realizar: suma, resta, division o multiplicacion");
		String operacion = cin.nextLine();
		char caracter = operacion.charAt(0);
		System.out.println("Ingrese el primer numero");
		double num1 = cin.nextDouble();
		System.out.println("Ingrese el segundo numero");
		double num2 = cin.nextDouble();
		
		switch (caracter){
			case 's':
				resultado = num1+num2;
				break;
				
			case 'r':
				resultado = num1-num2;
				break;
				
			case 'd':
				if(num2 != 0)resultado = num1/num2;
				resultado = num1/num2;
				break;
				
			case 'm':
				resultado = num1*num2;
				break;
				
			default:
				System.out.println("Entrada no valida");
				break;
		}
		
		System.out.println("El resultado de la operacion es: "+resultado);
	}

}
