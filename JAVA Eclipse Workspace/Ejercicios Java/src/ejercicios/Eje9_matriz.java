package ejercicios;

public class Eje9_matriz {
	
	public static void main(String[] args) {
		
		double interes=1.1;
		double ganancias[][]= new double [6][5];
		
		for (int i=0;i<6;i++) {
			 ganancias[i][0]=10000;
			 
			 for(int j=1;j<5;j++) {
				 ganancias[i][j]=ganancias[i][j-1]*interes;
			 }
			 interes+=0.01;
		}
		
		// IMPRESION
		
		for(int j=0;j<5;j++) {
			for(int i=0;i<6;i++) {
				System.out.printf("%1.2f",ganancias[i][j]);
				System.out.print(" ");
			}
			System.out.println();
		}
	}
}

