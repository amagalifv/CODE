#include <iostream>
using namespace std;

#define MAX_C 200

typedef struct {
    string codCliente;
    string nombre;
    string mail;
    int recomendaciones;
}ST_CLIENTE;

typedef struct {
    int totRecomendacion;
    int totCampania;
    int totOtros;
}ST_ENCUESTA;

void ordenarPorCodCliente (ST_CLIENTE clientes[MAX_C]) {



    return;
}

int busquedaBinaria(ST_CLIENTE clientes[MAX_C], string valor){
    return -1;
}

void encuesta (ST_CLIENTE clientes[MAX_C], ST_ENCUESTA &encuesta, int cantEncuestas) {
    int respLocal;
    string codRecomendacion;
    int posCliente;

    for (int i = 0; i < cantEncuestas; i++) {
    
        cout<<"¿como conocio el local? 1-Recomendacion, 2-Campaña publicitaria o 3-otros"<<endl;
        cin>>respLocal;
        
        switch (respLocal){
            case 1:
                encuesta.totRecomendacion++;
                cout<<"Indique el nro de cliente que se lo recomendo"<<endl;
                cin>>codRecomendacion;

                posCliente=busquedaBinaria(clientes, codRecomendacion);

                if (posCliente>-1){
                    clientes[posCliente].recomendaciones++;
                }
                
                break;

            case 2:
                encuesta.totCampania++;
                break;
            
            case 3:
                encuesta.totOtros++;
                break;
        
            default:
                break;
        }
    }

    return;
}

void ordenarPorRecomendaciones (ST_CLIENTE clientes[MAX_C]) {



    return;
}

void corteControl (ST_CLIENTE clientes[MAX_C]) {

    int i = 0;
    int contador= 0;
    string key;
    int j=1;

    cout <<"-------------------------------------------------------------------"<< endl;
    cout << "Rankin de Clientes Premiados: "<< endl;
    
    while(i < 3) {

        key = clientes[i].codCliente;

        contador = 0;

        while(i < 3 && key == clientes[i].codCliente) {

            contador++;
            
            i++; 
        }

        cout << j <<"° El Cliente: " << key << " se lo recomendo a " << contador << endl;
        j++;
    }

    cout <<"-------------------------------------------------------------------"<< endl;

    return;
}

void imprimirSatisfactorio (ST_ENCUESTA encuesta, int cantEncuestas) {
    float porcentaje;
    
    porcentaje=(encuesta.totCampania*100)/cantEncuestas;
    
    if (porcentaje>=65){
        cout<<"LA CAMPAÑA PUBLICITARIA FUE EFECIVA"<<endl;
    }else{
        cout<<"La campaña publicitaria no llega al 65% "<<endl;
    }

    return;
}

int main () {
    ST_CLIENTE clientes[MAX_C];
    ST_ENCUESTA encuesta;
    int cantEncuestas=100;
    



 
    system("pause");
    return 0;
}