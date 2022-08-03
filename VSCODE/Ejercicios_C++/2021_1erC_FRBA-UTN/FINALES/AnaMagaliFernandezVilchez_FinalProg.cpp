#include <iostream>
using namespace std;

#define MAX_CAT 30
#define MAX 100

//----A----
typedef struct{
    string nombre;
    int codigo;
    int codCategoria;
    float precio;
}ST_CONTADO;

typedef struct{
    string nombre;
    int codigo;
    int codCategoria;
    float precio3;
    float precio6;
    float precio12;
}ST_CUOTA;

typedef struct{
    int codCategoria;
    string nombreCat;
}ST_CATEGORIA;

typedef struct{
    string nombre;
    int codigo;
    int codCategoria;
    float precioContado;
    float precioCuotas;
}ST_UNIFICADO;

void ordenarPorCodContado (ST_CONTADO contados[MAX]) {

    ST_CONTADO aux;
    int i=0;
    bool ordenado = false;

    while (i < MAX && !ordenado){
        
        ordenado= true; 

        for (int j = 0; j < MAX-i-1 ; j++){
            
            if (contados[j].codigo>contados[j+1].codigo){
                aux = contados[j];
                contados[j]=contados[j+1];
                contados[j+1]=aux;
                ordenado = false; 
            }
        }

        i++;
    }


    return;
}

void ordenarPorCodCuotas (ST_CUOTA cuotas[MAX]) {

    ST_CUOTA aux;
    int i=0;
    bool ordenado = false;

    while (i < MAX && !ordenado){
        
        ordenado= true; 

        for (int j = 0; j < MAX-i-1 ; j++){
            
            if (cuotas[j].codigo>cuotas[j+1].codigo){
                aux = cuotas[j];
                cuotas[j]=cuotas[j+1];
                cuotas[j+1]=aux;
                ordenado = false; 
            }
        }

        i++;
    }


    return;
}

int busquedaBinaria(ST_UNIFICADO unificados[MAX+MAX], int cod){
    int inicio=0;
    int fin = MAX+MAX-1;

    while(fin >= inicio){
        int mitad =inicio + (fin - inicio)/2;

        if (unificados[mitad].codigo==cod){
            return mitad;
        }

        if (unificados[mitad].codigo>cod){
            fin=mitad - 1;
        }else{
            inicio=mitad+1;
        } 
    }

    return -1;
}

void apareo (ST_CONTADO contados[MAX], ST_CUOTA cuotas[MAX],ST_UNIFICADO unificados[MAX+MAX], int &dimeU) {

    int i = 0;
    int j = 0;
    int k = 0;
    int key;
    int pos;

    while(i < MAX) { //el de contado
        unificados[k].codigo = contados[i].codigo;
        unificados[k].nombre = contados[i].nombre;
        unificados[k].codCategoria = contados[i].codCategoria;
        unificados[k].precioContado = contados[i].precio;
        i++;
        k++;
    }

    while(j < MAX) {// el de cuotas

        key=cuotas[j].codigo;

        pos=busquedaBinaria(unificados, key);

        if (pos>-1){

            if (cuotas[j].precio12!=NULL){
                unificados[pos].precioCuotas=cuotas[j].precio12;
            }else{
                if (cuotas[j].precio6!=NULL){
                    unificados[pos].precioCuotas=cuotas[j].precio6;
                }else{
                    if (cuotas[j].precio3!=NULL){
                        unificados[pos].precioCuotas=cuotas[j].precio3;
                    } 
                } 
            }

        }else{
            unificados[k].codigo= cuotas[j].codigo;
            unificados[k].nombre= cuotas[j].nombre;
            unificados[k].codCategoria= cuotas[j].codCategoria;

            if (cuotas[j].precio12!=NULL){
                unificados[k].precioCuotas=cuotas[j].precio12;
            }else{
                if (cuotas[j].precio6!=NULL){
                    unificados[k].precioCuotas=cuotas[j].precio6;
                }else{
                    if (cuotas[j].precio3!=NULL){
                        unificados[k].precioCuotas=cuotas[j].precio3;
                    } 
                } 
            }
            k++;
        }

        j++; 
    }

    dimeU=k;

    return;
}

void encontrarRankinMajPrecioCont (ST_UNIFICADO unificados[], int dimeU,ST_UNIFICADO $maj1,ST_UNIFICADO $maj2,ST_UNIFICADO $maj3) {
    ST_UNIFICADO maj1;
    ST_UNIFICADO maj2;
    ST_UNIFICADO maj3;
    maj1.precioContado=0;
    maj2.precioContado=0;
    maj3.precioContado=0;

    for (int i = 0; i < dimeU; i++) {
        
        if (unificados[i].precioContado>maj1.precioContado){
            maj3=maj2;
            maj2=maj1;
            maj1=unificados[i];
        }else{
            if (unificados[i].precioContado>maj2.precioContado){
                maj2=maj3;
                maj2=unificados[i];
            }else{
                if (unificados[i].precioContado>maj3.precioContado){
                    maj3=unificados[i];
                }   
            }   
        }
    }

    return;
}

int busquedaBinariaD(ST_CATEGORIA categorias[MAX_CAT], int codCat){
    int inicio=0;
    int fin = MAX_CAT-1;

    while(fin >= inicio){
        int mitad =inicio + (fin - inicio)/2;

        if (categorias[mitad].codCategoria==codCat){
            return mitad;
        }

        if (categorias[mitad].codCategoria>codCat){
            fin=mitad - 1;
        }else{
            inicio=mitad+1;
        } 
    }

    return -1;
}

void imprimirD (ST_UNIFICADO maj1,ST_UNIFICADO maj2,ST_UNIFICADO maj3,ST_CATEGORIA categorias[MAX_CAT]){

    int pos;

    cout<<"---------------------RANKIN---------------------"<<endl;
    cout<<"1°:"<<endl;
    cout<<"Codigo de producto: "<<maj1.codigo<<endl;
    cout<<"Nombre: "<<maj1.nombre<<endl;
    cout<<"Codigo de categoria: "<<maj1.codCategoria<<endl;
    
    pos=busquedaBinariaD(categorias,maj1.codCategoria);
    if (pos>-1){
        cout<<"Nombre de la categoria: "<<categorias[pos].nombreCat<<endl;
    }

    if (maj1.precioCuotas!=NULL){
        cout<<"Precio cuotas: "<<maj1.precioCuotas<<endl; 
    }
    cout<<"Precio contado: "<<maj1.precioContado<<endl;    

    cout<<"------------------------------------------"<<endl;

    cout<<"2°:"<<endl;
    cout<<"Codigo de producto: "<<maj2.codigo<<endl;
    cout<<"Nombre: "<<maj2.nombre<<endl;
    cout<<"Codigo de categoria: "<<maj2.codCategoria<<endl;
    
    pos=busquedaBinariaD(categorias,maj2.codCategoria);
    if (pos>-1){
        cout<<"Nombre de la categoria: "<<categorias[pos].nombreCat<<endl;
    }

    if (maj2.precioCuotas!=NULL){
        cout<<"Precio cuotas: "<<maj2.precioCuotas<<endl; 
    }
    cout<<"Precio contado: "<<maj2.precioContado<<endl;

    cout<<"------------------------------------------"<<endl;

    cout<<"3°:"<<endl;
    cout<<"Codigo de producto: "<<maj3.codigo<<endl;
    cout<<"Nombre: "<<maj3.nombre<<endl;
    cout<<"Codigo de categoria: "<<maj3.codCategoria<<endl;
    
    pos=busquedaBinariaD(categorias,maj3.codCategoria);
    if (pos>-1){
        cout<<"Nombre de la categoria: "<<categorias[pos].nombreCat<<endl;
    }

    if (maj3.precioCuotas!=NULL){
        cout<<"Precio cuotas: "<<maj3.precioCuotas<<endl; 
    }
    cout<<"Precio contado: "<<maj3.precioContado<<endl;


    return;
}

int main () {
    ST_CONTADO contados[MAX];
    ST_CUOTA cuotas[MAX];
    ST_CATEGORIA categorias[MAX_CAT];
    ST_UNIFICADO unificados[MAX+MAX];
    int dimeU;
    ST_UNIFICADO maj1;
    ST_UNIFICADO maj2;
    ST_UNIFICADO maj3;

    //----B----
    ordenarPorCodContado(contados);
    ordenarPorCodCuotas(cuotas);
    apareo(contados,cuotas,unificados,dimeU);

    //----C----
    encontrarRankinMajPrecioCont(unificados,dimeU,maj1,maj2,maj3);

    //----D----
    imprimirD(maj1,maj2,maj3,categorias);
 
    system("pause");
    return 0;
}