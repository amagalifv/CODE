package ejercicios;


/*
 * IMPRIMIR LA TABLA DE VERDAD EN BOOLEANOS Y EN ENTEROS
 */

public class Ejer12_lib102 {

	public static void main(String[] args) {
		
		boolean p,q;
		int P,Q;
		
		System.out.println("\t P\t Q\t AND\t OR\t XOR\t NOT-P\t NOT-Q");
		
		
		p=true;
		q=true;
		System.out.println(" \t"+p+" \t"+q+" \t"+(p&q)+" \t"+(p|q)+" \t"+(p^q)+" \t"+(!p)+" \t"+(!q));
		
		p=true;
		q=false;
		System.out.println(" \t"+p+" \t"+q+" \t"+(p&q)+" \t"+(p|q)+" \t"+(p^q)+" \t"+(!p)+" \t"+(!q));
		
		p=false;
		q=true;
		System.out.println(" \t"+p+" \t"+q+" \t"+(p&q)+" \t"+(p|q)+" \t"+(p^q)+" \t"+(!p)+" \t"+(!q));
		
		p=false;
		q=false;
		System.out.println(" \t"+p+" \t"+q+" \t"+(p&q)+" \t"+(p|q)+" \t"+(p^q)+" \t"+(!p)+" \t"+(!q));
		
		// --------------------- En binario -----------------------------
		
		System.out.println("\n\n\nP\tQ\tAND\tOR\tXOR\tNOT-P\tNOT-Q");
		
		P=0B0;
		Q=0B0;
		System.out.print(P+" \t"+Q+" \t"+(P&Q)+" \t"+(P|Q)+" \t");
		if((P==0 & Q==0) || (P==1 & Q==1)) {System.out.print(0+" \t");}else {System.out.print(1+" \t");}
		if(P==0) {System.out.print(1+" \t");}else {System.out.print(0+" \t");}
		if(Q==0) {System.out.print(1+" \n");}else {System.out.print(0+" \n");}
		
		P=0B1;
		Q=0B0;
		System.out.print(P+" \t"+Q+" \t"+(P&Q)+" \t"+(P|Q)+" \t");
		if((P==0 & Q==0) || (P==1 & Q==1)) {System.out.print(0+" \t");}else {System.out.print(1+" \t");}
		if(P==0) {System.out.print(1+" \t");}else {System.out.print(0+" \t");}
		if(Q==0) {System.out.print(1+" \n");}else {System.out.print(0+" \n");}
		
		P=0B0;
		Q=0B1;
		System.out.print(P+" \t"+Q+" \t"+(P&Q)+" \t"+(P|Q)+" \t");
		if((P==0 & Q==0) || (P==1 & Q==1)) {System.out.print(0+" \t");}else {System.out.print(1+" \t");}
		if(P==0) {System.out.print(1+" \t");}else {System.out.print(0+" \t");}
		if(Q==0) {System.out.print(1+" \n");}else {System.out.print(0+" \n");}
		
		P=0B1;
		Q=0B1;
		System.out.print(P+" \t"+Q+" \t"+(P&Q)+" \t"+(P|Q)+" \t");
		if((P==0 & Q==0) || (P==1 & Q==1)) {System.out.print(0+" \t");}else {System.out.print(1+" \t");}
		if(P==0) {System.out.print(1+" \t");}else {System.out.print(0+" \t");}
		if(Q==0) {System.out.print(1+" \n");}else {System.out.print(0+" \n");}
		
	}

}
