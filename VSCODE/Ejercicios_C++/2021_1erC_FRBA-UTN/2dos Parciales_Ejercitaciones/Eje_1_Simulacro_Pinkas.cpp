#include <iostream>
using namespace std;

#define DIM 3
const int nroMagico=15;

void cargarSudoku (int sudoku[DIM][DIM], int dimen) {
    for (int i = 0; i < dimen; i++) {
    
        for (int j = 0; j < dimen; j++) {
            cout<<"Ingrese el primer numero del Sudoku"<<endl;
            cin>>sudoku[j][i];
        }
    }

    return;
}

void imprimirSudoku (int sudoku[DIM][DIM], int dimen) {
    for (int i = 0; i < dimen; i++) {
    
        for (int j = 0; j < dimen; j++) {
            cout<<sudoku[j][i]<<" - ";
        }
        cout<<endl;
    }
    return;
}

void siEsMagico (int sudoku[DIM][DIM], int dimen, const int nroMagico) {
    int sumFila=0;
    int i=0;
    bool filas=false;
    int sumColum=0;
    bool columnas=false;
    bool primeraEntA=true;
    bool primeraEntB=true;
    int sumaDiagPrincipal=0;
    int sumaDiagSecund=0;

    
    while (i<dimen && sumFila==nroMagico || primeraEntA==true) {
        sumFila=0;
        primeraEntA=false;
        
        for (int j = 0; j < dimen; j++) {
            sumFila+=sudoku[j][i];
        }
        i++;
    }

    if (i==dimen-1) {
        filas=true;
    }

    
    int j=0;
    while (j<dimen && sumColum==nroMagico || primeraEntB==true) {
        sumColum=0;
        primeraEntB=false;
        
        for (int i = 0; i < dimen; i++) {
            sumColum+=sudoku[j][i];
        }
        j++;
    }

    if (j==dimen-1) {
        columnas=true;
    }

    for (int i = 0; i < filas; i++) {
    
        for (int j = 0; j < columnas; j++) {
        
            if (i=j){
                sumaDiagPrincipal+=sudoku[j][i];
            }  
        }
    }

    for (int i = 0; i < filas; i++) {
    
        for (int j = 0; j < columnas; j++) {
        
            if (i+j==dimen){
                sumaDiagSecund+=sudoku[j][i];
            }  
        }
    }

    if (columnas==true && filas==true && sumaDiagPrincipal==15 && sumaDiagSecund==15){
        cout<<"Es magico"<<endl;
    }else{
        cout<<"No es magico"<<endl;
    }
    
    return;
}

int main () {
    int sudoku[DIM][DIM];
    int dimension;

    cout<<"Ingrese la dimension del cuadrado"<<endl;
    cin>>dimension;

    cargarSudoku(sudoku, dimension);

    cout<<"-------------------IMPRESION CUADRADO-------------------"<<endl;
    imprimirSudoku(sudoku, dimension);

    siEsMagico(sudoku, dimension, nroMagico);

    system("pause");
    return 0;
}