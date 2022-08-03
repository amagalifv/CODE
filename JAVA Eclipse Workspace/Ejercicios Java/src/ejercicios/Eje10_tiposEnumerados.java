package ejercicios;

import java.util.*;

public class Eje10_tiposEnumerados {
	
	enum talla {
		
		SMALL("S"), MEDIUM ("M"), LARGE("L"),EXTRALARGE("XL");
		private String abrev;
		
		private talla (String abrev) {
			this.abrev=abrev;
		}
	}
	
	public static void main(String[] args) {
		
		Scanner entrada= new Scanner(System.in);
		
		System.out.println("Ingrese un talle: SMALL, MEDIUM,LARGE,EXTRALARGE");
		
		String entradaDatos= entrada.next().toUpperCase();
		
		talla laTalla=Enum.valueOf(talla.class, entradaDatos);
		
		
		
	}

}

