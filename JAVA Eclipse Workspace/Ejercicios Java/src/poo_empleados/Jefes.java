package poo_empleados;

public class Jefes extends Empleados{
	
	public Jefes (String nom, double sue, int anio, int mes, int dia){
		
		super(nom,sue,anio,mes,dia); // LLAMA CONSTRUCTOR DE CLASE PADRE
	} //CONSTRUCTOR DE JEFES
	
	private double incentivo;
	
	public void setIncentivo (double b) {
		incentivo=b;
	}
	
	public double getSueldo () {
		 double sueldoJefe=super.getSueldo();
		 
		 return sueldoJefe+incentivo;
	}
}

