package ejercicios;
import javax.swing.*;

	public class Eje4_casteoYmathRaiz {

		public static void main(String[] args) {
			
			String num1 = JOptionPane.showInputDialog("Introduce un número");
			
			double num2= Double.parseDouble(num1);
			
			System.out.print("La raíz de " + num2 + " es ");
			System.out.printf("%1.2f", Math.sqrt(num2));
		}
}
