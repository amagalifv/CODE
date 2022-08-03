#include <iostream>
using namespace std;

#define MAX_S 150
#define MAX_C 100
#define MAX_I 500

typedef struct{
    string codigo;
    string nombre;
    int horaIni;
    int horaFin;
    int capMin;
}ST_CONGRESO;

typedef struct{
    int codSimp;
    int dni;
    string apellido;
    int fechaNac;
}ST_INSCRIPCION;

typedef struct{
    int codigo;
    string codCongr;
    string nombre;
    int horaIni;
    int horaFin;
    int inscriptos;
}ST_SIMPOSIO;

void ordenarInsc (ST_INSCRIPCION inscripciones[MAX_I],int dimeI) {
    int j=0;
    ST_INSCRIPCION aux;
    int i=0;
    bool ordenado = false;

    while (i < dimeI && !ordenado){
        ordenado= true;  

        for (int j = 0; j < dimeI-i-1 ; j++){
            if (inscripciones[j].codSimp>inscripciones[j+1].codSimp){
                aux = inscripciones[j];
                inscripciones[j]=inscripciones[j+1];
                inscripciones[j+1]=aux;
                ordenado = false;
            }
        }
        i++;
    }
 


    return;
}

void cargarSimpo (ST_INSCRIPCION inscripciones[MAX_I],int dimeI,ST_SIMPOSIO simposios[MAX_S]) {
    int i = 0;
    int contador = 0;
    int key;

    while(i < dimeI) {

        key = inscripciones[i].codSimp;

        contador = 0;

        while(i < dimeI && key == inscripciones[i].codSimp) {

            contador++;
            
            i++; 
        }

        simposios[key-100].inscriptos=contador;
    }
    
    return;
}

int busqBinCod (ST_CONGRESO congresos[MAX_C],int dimeC, string x) {
    int inicio=0;
    int fin = dimeC-1;

    while(fin >= inicio){
        int mitad =inicio + (fin - inicio)/2;

        if (congresos[mitad].codigo==x){
            return mitad;
        }

        if (congresos[mitad].codigo>x){
            fin=mitad - 1; 
        }else{
            inicio=mitad+1;
        } 
    }
    
    return -1;
}

void ordenarSimp (ST_SIMPOSIO simposios[MAX_S],int dimeS) {
    int j=0;
    ST_SIMPOSIO aux;
    int i=0;
    bool ordenado = false;

    while (i < dimeS && !ordenado){
        ordenado= true;  

        for (int j = 0; j < dimeS-i-1 ; j++){
            if (simposios[j].codCongr>simposios[j+1].codCongr){
                aux = simposios[j];
                simposios[j]=simposios[j+1];
                simposios[j+1]=aux;
                ordenado = false;
            }
        }
        i++;
    }

    return;
}

void validarDatosSimp (ST_SIMPOSIO simposios[MAX_S],int dimeS,ST_CONGRESO congresos[MAX_C],int dimeC) {
    int i = 0;
    int contadorVal = 0;
    string key;
    int key2;
    int pos;

    while(i < dimeS) {

        key = simposios[i].codCongr;

        contadorVal = 0;

        while ( i < dimeS && key == simposios[i].codCongr ) {

            key2=simposios[i].codigo;
            cout<<"Congreso: "<<congresos[pos].codigo<<"-"<<congresos[pos].nombre<<"\t\t"<<endl;
            
            while( i < dimeS && key == simposios[i].codCongr && key2 == simposios[i].codigo) {
            
                pos=busqBinCod(congresos, dimeC,simposios[i].codCongr);
                
                if (pos>-1){
                    
                    if (simposios[i].horaIni>congresos[pos].horaIni && simposios[i].horaFin<congresos[pos].horaFin && simposios[i].inscriptos>congresos[pos].capMin && simposios[i].nombre != ""){
                        contadorVal++;

                    }else{
                        cout<<simposios[i].codigo<<"\t\t"<<simposios[i].nombre<<"\t\t"<<"Invalido"<<endl;  
                    }
                }
            
                i++;
            }
        }
        cout<<"Cantidad validos: "<<contadorVal<<endl;
    }
    
    return;
}

int main () {
    ST_CONGRESO congresos[MAX_C];
    ST_INSCRIPCION inscripciones[MAX_I];
    ST_SIMPOSIO simposios[MAX_S];
    int dimeC;
    int dimeI;
    int dimeS;

    // --------------------Parte A--------------------
    ordenarInsc(inscripciones, dimeI);
    cargarSimpo(inscripciones, dimeI,simposios);

    // --------------------Parte B y C --------------------
    ordenarSimp(simposios,dimeS);
    validarDatosSimp(simposios,dimeS,congresos,dimeC);
 
    system("pause");
    return 0;
}