package edu_it;
import java.util.Arrays;
import java.util.Objects;
import javax.swing.JOptionPane;

/*
 * Genere un prog que solicite la cantidad de registros, notas y nombre de cada alumno
 * DEbe mostrar cual es la nota mayor y menor ingresada indicando quien fue que obtuvo cada una de ellas
 * Ordenar las notas con su respectivo nombre
 */

class Alumno implements Comparable {
	
	private String nombre;
	private String apellido;
	private int nota;
	
	Alumno (String nombre, String apellido, int nota) {
		this.nombre=nombre;
		this.apellido=apellido;
		this.nota=nota;
	}
	
	Alumno(){
		nombre=null;
		apellido=null;
		nota=0;
	}
	
	public void setAlumno (String nombre, String apellido, int nota) {
		this.nombre=nombre;
		this.apellido=apellido;
		this.nota=nota;
	}
	
	
	public int getNota () {
		return nota;
	}
	
	public String getNombre () {
		return nombre;
	}
	
	public String getApellido () {
		return apellido;
	}
	
	@Override
	public int compareTo(Object o) {
		Alumno otroAlu = (Alumno) o;
		if(this.nota<otroAlu.nota) {
			return -1;
		}
		if (this.nota>otroAlu.nota) {
			return 1;
		}
		return 0;
	}
}

// ---------------------MAIN------------------------------

public class U1_labF_notasAlumn {

	public static void main(String[] args) {
		
		String cantAlu = JOptionPane.showInputDialog("Ingrese cantidad de Alumnos a listar");
		int cant = Integer.parseInt(cantAlu);
		
		Alumno listadoAlu [] = new Alumno[cant];
		
		for (int i=0 ; i<cant ; i++) {
			
			listadoAlu [i] =  new Alumno(JOptionPane.showInputDialog("Nombre: "),JOptionPane.showInputDialog("Apellido: "),Integer.parseInt(JOptionPane.showInputDialog("Nota: ")));
		}
		
		// IMPRESION
		System.out.println("Nota  Apellido  Nombre");
		for (int j=0 ; j<cant ; j++ ) {
			System.out.println(listadoAlu [j].getNota() + "\t" + listadoAlu [j].getNombre()+"\t"+listadoAlu [j].getApellido());	
		}
		
		Arrays.sort(listadoAlu);
		
		// IMPRESION
		System.out.println("Nota  Apellido  Nombre");
		for (int j=0 ; j<cant ; j++ ) {
			System.out.println(listadoAlu [j].getNota() + "\t" + listadoAlu [j].getNombre()+"\t"+listadoAlu [j].getApellido());	
		}
		
		// IMPRESION MAX
		System.out.print("\nEL MAXIMO ES: ");	
		System.out.println(listadoAlu [cant-1].getNota() + "," + listadoAlu [cant-1].getNombre()+listadoAlu [cant-1].getApellido());	
		
		// IMPRESION MIN
		System.out.print("\nEL MINIMO ES: ");
		System.out.println(listadoAlu [0].getNota() + "," + listadoAlu [0].getNombre()+listadoAlu[0].getApellido());	
	}

	


}
