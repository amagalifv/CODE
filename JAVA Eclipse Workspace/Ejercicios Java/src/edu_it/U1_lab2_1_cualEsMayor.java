package edu_it;

/*
 * Declare e inicie 3 variables enteras y compare cual de las 3 es la mayor.
 */

public class U1_lab2_1_cualEsMayor {

	public static void main(String[] args) {
		
		int num1=1, num2=2, num3=2;
		
		if (num1>=num2 && num1>=num3) {
			System.out.println("El mayor numero es " + num1);
		} else if (num2>=num1 && num2>=num3) {
			System.out.println("El mayor numero es " + num2);
		} else {
			System.out.println("El mayor numero es " + num3);
		}

	}

}
