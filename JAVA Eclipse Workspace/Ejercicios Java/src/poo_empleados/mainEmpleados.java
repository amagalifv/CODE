package poo_empleados;
import java.util.Arrays;

public class mainEmpleados {

	public static void main(String[] args) {
		
		Empleados misEmpleados[] = new Empleados[5];
		
		Jefes jefeRRHH = new Jefes ("Juan", 300000,2020,9,25);
		jefeRRHH.setIncentivo(3000);
		misEmpleados[1]= new Empleados ("Pepe", 40000, 2021,12,3);
		misEmpleados[0]= new Empleados ("Maria", 80000, 2020,11,2);
		misEmpleados[3]= new Empleados ("Pedro", 120000, 2019,9,15);
		misEmpleados[2]=jefeRRHH; //POLIMORFISMO.PRINCIPIO DE SUSTITUCION
		misEmpleados[4]= new Jefes ("Alberto", 400000, 2019,10,31);
		Jefes jefeVentas=(Jefes) misEmpleados[4];// CASTEO LA VARIABLE DE TIPO EMPLEADOS A JEFES (CASTING) PARA PODER APLICARLE EL INCENTIVO 
		jefeVentas.setIncentivo(4000); 
		
		/*for(int i=0 ; i<3 ; i++ ) {
			misEmpleados[i].setSubirSueldo(5);
		} LO QUE SIGUE ES EL FOR MEJORADO!!! */
		
		for(Empleados e: misEmpleados) {
			e.setSubirSueldo(5);
		}
		
		//ORDENAMIENTO
		Arrays.sort(misEmpleados);
		// para hacerlo, Empleado s tiene q implements Comparable
		
		// IMPRESION
		System.out.print("  Nombre\t|\tSueldo\t|\tFecha Contrato\n");
		for(Empleados e: misEmpleados) {
			System.out.print("  "+e.getNombre()+" "+e.getSueldo()+" "+e.getFecha()+"\n");
		}
	}
	
}
