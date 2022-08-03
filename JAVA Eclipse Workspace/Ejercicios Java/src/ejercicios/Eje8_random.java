package ejercicios;

import java.util.Scanner;

public class Eje8_random {
	
	public static void main(String[] args) {
	
		int numAleatorio = (int)(Math.random()*100);
		
		Scanner entrada= new Scanner(System.in);
		
		int num=-1;
		int intentos=1;
		
		//System.out.println("Número random:"+numAleatorio);
		
		while(num!=numAleatorio && intentos<6) {
			
			System.out.println("Ingresa un numero");
			num=entrada.nextInt();
			
			if(intentos==1) {
				System.out.println("No acertaste, intentelo otra vez");	
			}
			
			if(intentos==2) {
				System.out.print("Te daremos 1 pista: ");
				
				if(numAleatorio>50) {
					System.out.println("es mayor a 50");
				}else {
					System.out.println("es menor o igual a 50");
				}
			}
			
			if(intentos==3) {
				System.out.println("Decena: "+(numAleatorio/10));
			}
			
			if(intentos==4) {
				if(numAleatorio%2==0) {
					System.out.println("Es par");
				}else {
					System.out.println("Es impar");
				}
			}
			
			intentos++;
		}
		
		if(num==numAleatorio) {
			System.out.println("Acertaste!!! Te llevó "+intentos+" intentos");
		}else {
			System.out.println("Perdiste, el numero era "+ numAleatorio);
		}
	}
}

