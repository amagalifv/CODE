package poo_empleados;
import java.util.*;

class Empleados implements Comparable {

	private final String nombre; // LA  PALABRA "FINAL" ES PARA QUE UNA VEZ INGRESADO NO PUEDA CAMBIARSE 
	private double sueldo;
	private Date altaContrato;
	private int Id;
	private static int IdSiguiente=1001;//STATIC PARA QUE SOLO LA CLASE TENGA UNA COPIA DE ESA VARIABLE, NO LA INSANCIA DEL OBJETO CLASE EMPLEADO
	
	public Empleados (String nom, double sue, int anio, int mes, int dia) {
		nombre=nom;
		sueldo=sue;
		GregorianCalendar fecha = new GregorianCalendar(anio,mes-1,dia); 
		altaContrato=fecha.getTime();
		Id=IdSiguiente;
		IdSiguiente++;
	} // CONSTRUCTOR
	
	public String getNombre() {
		return nombre;
	}
	
	public double getSueldo() {
		return sueldo;
	}
	
	public Date getFecha() {
		return altaContrato;
	}
	
	public void setSubirSueldo(double porcentaje) {
		double aumento=sueldo*porcentaje/100;
		sueldo+=aumento;
	}
	
	public int compareTo(Object miObjeto) {
		
		Empleados otroEmpleado=(Empleados)miObjeto;
		
		if(this.sueldo<otroEmpleado.sueldo) {
			return -1;
		}
		if(this.sueldo>otroEmpleado.sueldo) {
			return 1;
		}
		return 0;
	}
}
