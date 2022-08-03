#include <iostream>
using namespace std;

// SIMULACRO PRIMER PARCIAL PINKAS

void buscarMinMax(float temp, float &minTemp, float &maxTemp){
    
    if (temp>maxTemp){
        maxTemp=temp;
    }else{
        if (temp<minTemp){
            minTemp=temp;
        }
    }

    return;
}

float calcularProm(float sum, int i){
    float prom=0;

    prom=sum/i;

    return prom;
}

void imprimir(float x, string mensaje){
    cout<<mensaje<<x<<endl;

    return;
}

int main () {
    float minTemp=100;
    float maxTemp=-100;
    float temperatura;
    int humedad;
    float sumHumedad;
    int iHumedad;
    float promHumedad;
    char ingreso;

    cout<<"Ingrese T para registrar temperatura, H para humedad y F para finalizar los registros"<<endl;
    cin>>ingreso;

    while ( ingreso != 'F') {
        
        if (ingreso == 'T'){

            cout<<"Ingrese la temperatura a registrar"<<endl;
            cin>>temperatura;
            buscarMinMax(temperatura, minTemp, maxTemp);

        } else {

            if (ingreso == 'H'){

                cout<<"Ingrese la humedad a registrar"<<endl;
                cin>>humedad;
                sumHumedad+=humedad;
                iHumedad++;

            }else{

                cout<<"Entrada inválida"<<endl;

            }
        }
        
        cout<<"Ingrese T para registrar temperatura, H para humedad y F para finalizar los registros"<<endl;
        cin>>ingreso;
    }

    promHumedad=calcularProm(sumHumedad, iHumedad);

    imprimir(promHumedad, "La humedad promedio es ");
    imprimir(minTemp, "La temperatura minima es ");
    imprimir(maxTemp, "La temperatura maxima es ");
 
    system("pause");
    return 0;
}

/*
void function miFuncionConErrores(INT n1, INT n2){
    FLOAT resultado = -1;
    
    if(n1 < n2){
        resultado = n1 / n2
    }else{
        resultado = n1 - n2;
    }

    return resultado;
}

    CON N2 != DE 0 !!!!!

*/