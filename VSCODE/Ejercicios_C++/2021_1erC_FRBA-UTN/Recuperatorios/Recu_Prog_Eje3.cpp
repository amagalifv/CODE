#include <iostream>
using namespace std;

#define MAX 3

typedef struct{
    int fila;
    int columna;
}ST_POSICION;

void buscar(char casino [MAX][MAX], char valor, ST_POSICION &posicion, string mensaje){
    
    cout<<mensaje;
    for (int j = 0; j < MAX; j++) {
        
        for (int i = 0; i < MAX; i++){
            
            if (casino[i][j] == valor){
                posicion.fila=i;
                posicion.columna=j;
                cout<<"se encontro en la posicion "<<posicion.fila<<","<<posicion.columna<<endl;
            
            }
    
        }
    }
    cout<<endl;

    return;
}

void imprimirAlerta (ST_POSICION guardia, ST_POSICION ladron) {

    if (guardia.fila==ladron.fila || guardia.columna==ladron.columna){
        cout<<"Ok"<<endl;
    }else{
        cout<<"ALARMA!!!!"<<endl;
    }

    return;
}

int main () {
    char casino [MAX][MAX]={{'G','x','x'},{'x','$','x'},{'x','L','x'}};
    ST_POSICION guardia;
    ST_POSICION ladron;
    ST_POSICION dinero;
   
    
    buscar(casino, 'G', guardia,"El guardia ");
    buscar(casino, '$', ladron, "El dinero ");
    buscar(casino, 'L', dinero, "El ladron ");

    imprimirAlerta(guardia,ladron);
 
    system("pause");
    return 0;
}