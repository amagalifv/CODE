#include <iostream>
using namespace std;



int main () {

    int matrizA[28][15][10]={0};
    int matrizMin[28][15][10]={0};
    int dni;
    int minCons;
    int centroS;
    int especialidad;
    int diaFeb;

    cout<<"Ingrese el dni del paciente"<<endl;
    cin>>dni;

    while (dni!=0){
        // PIDO DATOS
        cout<<"Ingrese el centro de salud"<<endl;
        cin>>centroS;
        cout<<"Ingrese la espacialidad"<<endl;
        cin>>especialidad;
        cout<<"Ingrese el dia de febrero en que fue atendido"<<endl;
        cin>>diaFeb;
        cout<<"Ingrese la cantidad de MINUTOS que duró la consulta"<<endl;
        cin>>minCons;

        // LOS CARGO EN LA matrizA
        matrizA[diaFeb-1][especialidad-1][centroS-1]+=1;
        matrizMin[diaFeb-1][especialidad-1][centroS-1]+=minCons;

        //PIDO DNI PARA VOLVER A ENTRAR AL WHILE
        cout<<"Ingrese el dni del paciente"<<endl;
        cin>>dni;
    }


    system("pause");
    return 0;
}