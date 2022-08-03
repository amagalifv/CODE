#include <iostream>
using namespace std;

#define MAX_L 20
#define MAX_C 30
#define MAX_A 50

typedef struct {
    int isbn;
    string nombre;
    short int categoria;
    int autorCod;
    int anioPubli;
}ST_LIBROS;

typedef struct {
    short int codCate;
    string nombre;
}ST_CATE;

typedef struct {
    int codAutor;
    string nombre;
    int fechaNac;
}ST_AUTOR;

void ordenarAutores(ST_AUTOR autores[MAX_A], int dimeA){
    int j=0;
    ST_AUTOR aux;
    int i=0;
    bool ordenado = false;

    while (i < dimeA && !ordenado){
        ordenado= true;

        for (int j = 0; j < dimeA-i-1 ; j++){
            if (autores[j].nombre>autores[j+1].nombre){
                aux = autores[j];
                autores[j]=autores[j+1];
                autores[j+1]=aux;
                ordenado = false;
            }
        }
        i++;
    }

    return;
}

int busquedaBinaria(ST_AUTOR autores[MAX_A], int dimeA, string x){
    int inicio=0;
    int fin = dimeA-1;

    while(fin >= inicio){
        int mitad =inicio + (fin - inicio)/2;

        if (autores[mitad].nombre==x){
            return mitad;
        }

        if (autores[mitad].nombre>x){
            fin=mitad - 1;
        }else{
            inicio=mitad+1;
        }
    }

    return -1;
}

void cargar(ST_LIBROS libros[MAX_L], int dimeL, ST_AUTOR autores[MAX_A], int dimeA){

    string nombreAutor;
    int posAutor=0;

    ordenarAutores(autores, dimeA);

    for (int i = 0; i < dimeL; i++) {

        cout<<"Ingrese el isbn del libro a registrar"<<endl;
        cin>>libros[i].isbn;

        cout<<"Ingrese el nombre del libro a registrar"<<endl;
        cin>>libros[i].nombre;

        cout<<"Ingrese la categoria del libro a registrar"<<endl;
        cin>>libros[i].categoria;

        cout<<"Ingrese el autor del libro a registrar"<<endl;
        cin>>nombreAutor;
        posAutor=busquedaBinaria(autores,dimeA, nombreAutor);

        if (posAutor>-1){
            libros[i].autorCod=autores[posAutor].codAutor;
        }

        cout<<"Ingrese la anio de publicacion del libro a registrar"<<endl;
        cin>>libros[i].anioPubli;
    }

    return;
}

void ordenarLib (ST_LIBROS libros[MAX_L], int dimeL) {
    int j=0;
    int i=0;
    ST_LIBROS aux;
    bool ordenado = false;

    while (i < dimeL && !ordenado){
        ordenado= true;

        for (int j = 0; j < dimeL-i-1 ; j++){
            if (libros[j].autorCod >libros[j+1].autorCod){
                aux = libros[j];
                libros[j]=libros[j+1];
                libros[j+1]=aux;
                ordenado = false;
            }
        }
        i++;
    }

    return;
}

void ordenarAutorCod (ST_AUTOR autores[MAX_A], int dimeA) {
    int j=0;
    ST_AUTOR aux;
    int i=0;
    bool ordenado = false;

    while (i < dimeA && !ordenado){
        ordenado= true;

        for (int j = 0; j < dimeA-i-1 ; j++){
            if (autores[j].codAutor>autores[j+1].codAutor){
                aux = autores[j];
                autores[j]=autores[j+1];
                autores[j+1]=aux;
                ordenado = false;
            }
        }
        i++;
    }

    return;


return;
}

int busquedaBinariaCod(ST_AUTOR autores[MAX_A], int dimeA, int x){
    int inicio=0;
    int fin = dimeA-1;

    while(fin >= inicio){
        int mitad =inicio + (fin - inicio)/2;

        if (autores[mitad].codAutor==x){
            return mitad;
        }

        if (autores[mitad].codAutor>x){
            fin=mitad - 1;
        }else{
            inicio=mitad+1;
        }
    }

    return -1;
}

void corteControl(ST_LIBROS libros[MAX_L], int dimeL, ST_AUTOR autores[MAX_A], int dimeA, ST_CATE categorias[MAX_C]){
    int i = 0;
    int contadorAu= 0;
    int contadorBiblio= 0;
    int key;
    string key2;
    int posAutor=0;
    string nomb;

    ordenarAutorCod(autores, dimeA);

    while(i < dimeL) {

        key = libros[i].autorCod;
        key2= libros[i].nombre;

        contadorAu = 0;

        while(i < dimeL && key == libros[i].autorCod) {

            posAutor=busquedaBinariaCod(autores,dimeA, libros[i].autorCod);

            if (posAutor>-1){
                nomb=autores[posAutor].nombre;
            }

            cout<<"Autor: "<<libros[i].autorCod<<" - "<<nomb<<endl;

            while (i < dimeL && key == libros[i].autorCod && key2==libros[i].nombre ) {

                contadorAu++;
                contadorBiblio++;
                i++;
            }

            cout<<libros[i].nombre<<"\t\t"<<categorias[ libros[i].categoria - 20 ].nombre<<"\t\t"<<libros[i].anioPubli<<endl;
            cout<<endl;
        }
        cout<<"cantidad de obras del autor: "<< contadorAu <<endl;

    }
    cout<<"cantidad de obras de la biblioteca: "<< contadorBiblio <<endl;

    return;
}


int main () {
    ST_LIBROS libros[MAX_L];
    ST_CATE categorias[MAX_C];
    ST_AUTOR autores[MAX_A];
    int dimeL=20;
    int dimeC=30;
    int dimeA=50;
    int decisionUsuario=0;

    cout<<"Ingrese 1 para cargar o 2 para visualizar los datos"<<endl;
    cin>>decisionUsuario;
    if (decisionUsuario==1){
        cout<<"---------------CARGA DE DATOS---------------"<<endl;
        cargar(libros, dimeL, autores, dimeA);
    }else{
        if (decisionUsuario==2){
            cout<<"---------------IMPRESION---------------"<<endl;
            ordenarLib(libros, dimeL);
            corteControl(libros, dimeL, autores, dimeA,categorias);
        }
    }

    system("pause");
    return 0;
}



