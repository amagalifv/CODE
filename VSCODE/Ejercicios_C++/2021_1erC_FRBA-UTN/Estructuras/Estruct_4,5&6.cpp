#include <iostream>
using namespace std;

#define MAX_ALU 100

typedef struct {
 int nroLegajo;
 int codMateria;
 int diaExamen;
 int mesExamen;
 int anioExamen;
 string apellido;
} ST_REG;

void cargarVector (ST_REG registro[], int cantBoletas){
 int i=0;

    cout<<"Ingrese el legajo " << endl;
    cin >> registro[i].nroLegajo;
    cout<<endl; 

    while (registro[i].nroLegajo !=0 && i<cantBoletas) {
    
        cout<<"Ingrese el apellido " << endl;
        cin >> registro[i].apellido;
        cout<<endl;

        cout<<"Ingrese el codigo de materia " << endl;
        cin >> registro[i].codMateria;
        cout<<endl;

        cout<<"Ingrese el dia del examen " << endl;
        cin >>registro[i].diaExamen;
        cout<<endl;

        cout<<"Ingrese el mes del examen " << endl;
        cin >> registro[i].mesExamen;
        cout<<endl;

        cout<<"Ingrese el anio del examen " << endl;
        cin >> registro[i].anioExamen;
        cout<<endl;

        i++;

        cout<<"Ingrese el legajo " << endl;
        cin >> registro[i].nroLegajo;
        cout<<endl;
    }

 return;    
}

void ordBurbujeo(ST_REG registro[], int cantBoletas){
 ST_REG aux;
 int i=0;
 bool ordenado = false;

 while (i < cantBoletas && !ordenado){
     ordenado= true; 

     for (int j = 0; j < (cantBoletas-i-1) ; j++){

        if (registro[j].nroLegajo>registro[j+1].nroLegajo){
             aux = registro[j];
             registro[j]=registro[j+1];
             registro[j+1]=aux;
             ordenado = false;
        }
     }
     i++;
 }
 
}

void imprimir (ST_REG registro[], int cantBoletas) {
    
    for (int i = 0; i < cantBoletas; i++){ 

        cout<<"Legajo: " <<registro[i].nroLegajo<< endl;
        cout<<endl;

        cout<<"Apellido: " << registro[i].apellido <<endl;
        cout<<endl;

        cout<<"Materia: " << registro[i].codMateria <<endl;
        cout<<endl;

        cout<<"Fecha examen: " <<registro[i].diaExamen<<"/"<< registro[i].mesExamen <<"/"<<registro[i].anioExamen<<endl;
        cout<<endl;
    }

return;
}

void imprimirUnaMateria(ST_REG registro[], int cantBoletas, int codMatPed) {

    for (int i = 0; i < cantBoletas; i++) {
        
        if (registro[i].codMateria==codMatPed) {
            cout<<registro[i].nroLegajo<<"\t\t"<<registro[i].apellido<<"\t\t"<<registro[i].diaExamen<<"\t\t"<<registro[i].codMateria<<endl;
        }
    }
    return;
}

void anexarVectores (ST_REG registro[MAX_ALU], int cantBoletas, ST_REG registroAnt[MAX_ALU], int &dimAnt){
    int j=0;
    int i=0;

    for (i = dimAnt ; i < dimAnt+cantBoletas ; i++) {
        registroAnt[i]=registro[j];
        j++;
    }
    dimAnt=i;

    return;
}

int main () {
    ST_REG registro[MAX_ALU];
    int cantBoletas;
    int codMatPed;
    ST_REG registroAnt[MAX_ALU];
    int dimAnt;

    cout<<"Ingrese la cantidad de boletas a registrar";
    cin>>cantBoletas;

    cargarVector(registro, cantBoletas);

    imprimir (registro, cantBoletas);

    ordBurbujeo (registro, cantBoletas);

    imprimir (registro, cantBoletas);

    cout<<"-----------------------EJERCICIO 5-----------------------"<<endl;
    cout<<"Ingrese el codigo de materia que desea visualizar"<<endl;
    cin>>codMatPed;
    cout<<"-----------------------IMPRESION-----------------------"<<endl;
    imprimirUnaMateria(registro, cantBoletas,codMatPed);

    cout<<"-----------------------EJERCICIO 6-----------------------"<<endl;
    anexarVectores(registro, cantBoletas, registroAnt, dimAnt);
    
    system("pause");
    return 0;
}