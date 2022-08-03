package practica;
import javax.swing.JOptionPane;

/* Pide 2 numeros enteros por teclado e indica cual es mayor
 * En caso de ser iguales lo especifica
 */

public class Ej_02 {

	public static void main(String[] args) {
		
		int num1;
		int num2;
		
		num1=Integer.parseInt(JOptionPane.showInputDialog(null, "Ingrese el primer numero: "));
		num2=Integer.parseInt(JOptionPane.showInputDialog(null, "Ingrese el segundo numero: "));
		
		
		if(num1>num2) {
			System.out.println("El mayor es "+num1);
		} else if (num1<num2) {
			System.out.println("El mayor es "+num2);
		} else {
			System.out.println("Son iguales");
		}
	}

}

