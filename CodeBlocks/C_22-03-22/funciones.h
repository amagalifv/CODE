#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include<stdlib.h>

///PROTOTIPOS
void ponerCeroMatriz(int mat[20][31], int fila, int col);
void mostrarMatriz(int mat[][31], int fila, int col);
bool ingresarDatosAccesos(float vMat[], int m[20][31]);
void puntoA(float vMat[]);
void puntoB(float vMat[]);
int buscarMaximo(float v[], int tam);
void puntoC(int m[20][31]);

void cargarMaterias(char nombres[][30]);
void cargarCadena(char *pal, int tam);
void mostrarMatrizCaracteres(char m[][30], int cant);

///FIN PROTOTIPOS
void cargarCadena(char *pal, int tam){
  int i;
  fflush(stdin); //stdin es el buffer de entrada
  for(i=0;i<tam;i++){
      pal[i]=cin.get();
	  if(pal[i]=='\n') break;
	  }
  pal[i]='\0';
  fflush(stdin);
}


void ponerCeroMatriz(int mat[20][31], int fila, int col){
    int i,j;
    for(i=0;i<fila;i++){
        for(j=0;j<col;j++){
            mat[i][j]=0;
        }
    }

}

void mostrarMatriz(int mat[20][31], int fila, int col){
    int i,j;
    for(i=0;i<fila;i++){
        for(j=0;j<col;j++){
            cout<<mat[i][j]<<"\t";
        }
        cout<<endl;
    }

}

void ingresarDatosAccesos(float vMat[], int m[20][31]){
    int legajo,dia,mes,nroMat;
    float cantHoras;
    cout<<"LEGAJO: ";
    cin>>legajo;
    while(legajo!=0){
        cout<<"DIA: ";
        cin>>dia;
        cout<<"MES: ";
        cin>>mes;
        cout<<"MATERIA: ";
        cin>>nroMat;
        cout<<"HORAS: ";
        cin>>cantHoras;
        //punto a y b
        vMat[nroMat-1]+=cantHoras;
        //punto c
        if(mes==3)  m[nroMat-1][dia-1]++;
        cout<<"LEGAJO: ";
        cin>>legajo;
    }


}
void puntoA(float vMat[]){
    int i;
    cout<<"MATERIAS SIN ACCESO"<<endl;
    for(i=0;i<20;i++){
        if(vMat[i]==0){
            cout<<i+1<<endl;
        }
    }

}
void puntoB(float vMat[]){
    int matMax;
    matMax=buscarMaximo(vMat,20);
    cout<<"LA MATERIA CON MAS ACCESOS FUE: "<<matMax+1<<endl;
}

int buscarMaximo(float v[], int tam){
    int i, posMax=0;

    for(i=1;i<tam;i++){
        if(v[i]>v[posMax]){
            posMax=i;
        }
    }
    return posMax;
}

void puntoC(int m[20][31]){}

void cargarMaterias(char nombres[][30]){
    int i, numeroMateria;
    for(i=0;i<5;i++){
        cout<<"NUMERO DE MATERIA: ";
        cin>>numeroMateria;
        cout<<"NOMBRE DE MATERIA: ";
        cargarCadena(nombres[numeroMateria-1],29);
    }
}

void mostrarMatrizCaracteres(char m[][30], int cant){
    int i;
    for(i=0;i<cant;i++){
        cout<<m[i]<<endl;
    }

}
#endif // FUNCIONES_H_INCLUDED
