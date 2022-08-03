#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void imprimirMenu (int $op){
cout<<"        MENÚ DE BIENVENIDA          "<<endl;
cout<<"    INDIQUE LA OPCION QUE DESEE     "<<endl;
cout<<"------------------------------------"<<endl;
cout<<" 1-CARGAR VALORES EN MATRIZ         "<<endl;
cout<<" 2-BUSCAR EL MAXIMO DE LA FILA      "<<endl;
cout<<" 3-DEVOLVER LA POSICIÓN DEL MÁXIMO  "<<endl;
cout<<" 4-LA SUMA DE LA FILA               "<<endl;
cout<<" 5-CANTIDAD DE POSITIVOS DE LA FILA "<<endl;
cout<<" 6-TOTAL SUMA MATRIZ                "<<endl;
cout<<" 7-SALIR                            "<<endl;
cin>>op;
}
void cargarMatriz(ínt mtrz[][]);

int pedirFila(){
    int aux;

    cout<<"Ingrese la fila: ";
    cin>>aux;

    return aux;
}

//MATRICES
// PUNTO 1
int maxFila(int mtrz[10][10], int fila){
    int max;
    max=mtrz[fila][0];

    for (int i=1; i<10 ; i++) {
        if (mtrz[fila][i]>max) {
            max=mtrz[fila][i];
        }
    }

    return max;
}
// PUNTO 2
int posMaxFila(int mtrz[10][10], int fila){
    int max=0;
    int posMax=0;
    max=mtrz[fila][0];

    for (int i=1; i<10 ; i++) {
        if (mtrz[fila][i]>max) {
            max=mtrz[fila][i];
            posMax=i;
        }
    }

    return posMax;
}
// PUNTO 3
int sumaDeFila(int mtrz[10][10], int fila){
    int acum=0;

    for (int i=0; i<10 ; i++) {
        acum+=mtrz[fila][i];
    }

    return acum;
}
// PUNTO 4
int contarPositivosDeFila(int mtrz[10][10], int fila){
    int acumPisitivos=0;

    for (int i=0; i<10 ; i++) {
        if (mtrz[fila][i]>0) {
            acumPisitivos++;
        }
    }

    return acumPisitivos;
}
// PUNTO 5
int sumaDeMatriz(int mtrz[10][10]){
    int acum=0;

    for (int j=0; j<10; j++) {
        for (int i=0; i<10 ; i++) {
        acum+=mtrz[i][j];
        }
    }

    return acum;
}

#endif // FUNCIONES_H_INCLUDED
