package edu_it;

import javax.swing.JOptionPane;

/*
 * Se requiere un sistema que agregue personas a una lista y se pidan los siguientes datos: nombre, apellido, tipo de documento, numero de
 * documento y edad.
 * Al final de pedir los datos debe mostrar por consola todos los datos introducidos e indicar si la persona es mayor o menor de edad
 */

class Persona{
	private String name;
	private String lastName;
	private String tipoDoc;
	private int numDoc;
	private int age;
	
	Persona () {
		numDoc=0;
		age=0;
	}
	
	Persona (String nombre, String apellido, int numDoc, int edad) {
		name=nombre;
		lastName=apellido;		
		this.numDoc=numDoc;
		age=edad;
	}
	
	// --------GETTERS---------
	public String getName () {
		return name;
	}
	public String getLast () {
		return lastName;
	}
	public String getTipoDoc () {
		return tipoDoc;
	}
	public int getNumDoc () {
		return numDoc;
	}
	public int getAge () {
		return age;
	}
	
	// --------SETTERS---------
	
	public void setName(String nombre) {
		name=nombre;
	}
	public void setLast(String apellido) {
		lastName=apellido;
	}
	public void setTipoDoc(String tipoDoc) {
		this.tipoDoc=tipoDoc;
	}
	public void setNumDoc(int numDoc) {
		this.numDoc=numDoc;
	}
	public void setEdad(int edad) {
		age=edad;
	}
	
	// // --------METHODS---------
	public void mensajeMayorDeEdad() {
		
		if(age>=18) {
			//JOptionPane.showMessageDialog(null, "Es mayor de edad");
			System.out.println("Es mayor de edad");
		} else {
			System.out.println("Es menor de edad");
		}
	}
	
	public void imprimirRegistro () {
		System.out.println("\nNombre    : "+lastName+", "+name+"\nTipo Doc  : "+tipoDoc+"\nN° Doc    : "+numDoc+"\nEdad      : "+age);
	}
}


public class U2_lab1 {

	public static void main(String[] args) {
		
		Persona persona1 = new Persona();
		
		persona1.setLast(JOptionPane.showInputDialog("Apellido: "));
		persona1.setName(JOptionPane.showInputDialog("Nombre: "));
		
		
		String tiposDoc[] = {"DNI","LC","LD", "CI"};
		Object td = (JOptionPane.showInputDialog(null,"Tipo de Documento","Input",1, null, tiposDoc, 0));
		persona1.setTipoDoc((String) td);
		
		persona1.setNumDoc(Integer.parseInt(JOptionPane.showInputDialog("N° de documento: ")));
		persona1.setEdad(Integer.parseInt(JOptionPane.showInputDialog("Edad: ")));
		
		//// --------IMPRESIONES---------
		persona1.mensajeMayorDeEdad();
		persona1.imprimirRegistro();
		

	}

}
