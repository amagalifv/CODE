package ejercicios;
import java.util.*;

public class Eje1_ingresoDatos {

	public static void main(String[] args) {
		Scanner entrada = new Scanner(System.in);
		
		System.out.println("Nombre: ");
		
		String nombre_usuario=entrada.nextLine();
		
		System.out.println("Edad: ");
		
		int edad=entrada.nextInt();
		
		System.out.println("Hola "+ nombre_usuario + ". El a�o que viene tendr�s "
		+ (edad+1) +" a�os.");

	}

}
