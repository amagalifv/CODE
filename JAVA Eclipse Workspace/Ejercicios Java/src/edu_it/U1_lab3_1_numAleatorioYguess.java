package edu_it;
import java.util.Scanner;

/*
 * Crear un numero aleatorio y dejar adivinar al usuario adivinar
 */

public class U1_lab3_1_numAleatorioYguess {

	public static void main(String[] args) {
		
		int numAleatorio = (int) (Math.random()*10);
		
		Scanner entrada = new Scanner (System.in);
		int num=0;
		
		
		System.out.println("Adivine el número del 1 al 10...");
		num=entrada.nextInt();
		
		while (num != numAleatorio) {
			
			System.out.println("No adivinaste...");
			
			System.out.println("Adivine el número del 1 al 10...");
			num=entrada.nextInt();
		}
		
		System.out.println("~ ¡¡¡ Adivinaste !!! ~");
	}

}
