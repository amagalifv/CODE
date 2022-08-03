#include <iostream>
using namespace std;

const float IVA = 1.21;

int pedirNum (string mensaje);
int tiempoAmin (int consumo);
void facturacion (char plan, int consumoEnMin, float &totConsumoxAb);

int main () {
    //datos entrada
    int celular=0;
    string nombreAbon;
    string direccion;
    int consumoHHMM=0;
    char plan;
    int turno;
    //datossalida
    int consumoEnMin=0;
    int minExedidos=0;
    float pesosAabonar=0;
    float totConsumoTotal=0;
    //Por cada turno
    string nombreAbonFacturaMasCara;
    string nombreMinExedMaj;
    int telMinExedMaj;
    int cantMinExedMaj;
    //Al final
    float totalFacturado;
    int turnoMenorMinConsumo;
    int posicionMenorMinConsumo;


    for (int i = 0; i < 2; i++){
        cout <<"Ingrese un turno: maniana 1, tarde 2, noche 3, 0 para pasar a otro turno"<< endl;
        cin>> turno;
        while (turno != 0){
            celular= pedirNum ("Ingrese el numero de celular del abonado");

            cout<<"Ingrese el nombre del abonado"<<endl;
            cin >> nombreAbon;

            cout<<"Ingrese la direccion del abonado"<<endl;
            cin >> direccion;

            consumoHHMM=pedirNum("Ingrese el consumo del  abonado en formato HHMM");

            cout<<"Ingrese el plan del abonado"<<endl;
            cin >> plan;

            consumoEnMin= tiempoAmin(consumoHHMM);

            facturacion(plan, consumoEnMin, pesosAabonar);



        }
    }

    system("pause");
    return 0;
}

int pedirNum (string mensaje){
    int num;
    cout << mensaje << endl;
    cin >> num;

    return num;
}

int tiempoAmin (int consumo){
    return (consumo/100)*60+(consumo%100);
}

void facturacion (char plan, int consumoEnMin, float &totConsumoxAb){
    float costoXmin;
    int minExtra;

    switch (plan){
        case 'A':
            if (consumoEnMin-300<0){
                minExtra=0;
            }else{
                minExtra=consumoEnMin-300;
            }

            totConsumoxAb=(70+(minExtra*0.09))*IVA;
            break;

        case 'B':
            if (consumoEnMin-200<0){
                minExtra=0;
            }else{
                minExtra=consumoEnMin-200;
            }

            totConsumoxAb=(55+(minExtra*0.15))*IVA;
            break;

        case 'C':
            if (consumoEnMin-100<0){
                minExtra=0;
            }else{
                minExtra=consumoEnMin-100;
            }

            totConsumoxAb=(40+(minExtra*0.21))*IVA;
        break;

        case 'D':
            if (consumoEnMin-60<0){
                minExtra=0;
            }else{
                minExtra=consumoEnMin-60;
            }

            totConsumoxAb=(28+(minExtra*0.29))*IVA;
        break;

        case 'E':
            if (consumoEnMin-40<0){
                minExtra=0;
            }else{
                minExtra=consumoEnMin-40;
            }
        totConsumoxAb=(19+(minExtra*0.37))*IVA;
        break;
    }
}