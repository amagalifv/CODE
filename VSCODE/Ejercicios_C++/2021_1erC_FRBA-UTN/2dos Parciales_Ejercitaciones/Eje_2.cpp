#include <iostream>
using namespace std;

#define MAX_U 1000
#define MAX_J 100

#define MAX_R 100

typedef struct{
    int codigo;
    string nombre;
}ST_JUEGOS;

typedef struct{
    short int codGamer;
    string nombre;
    int fechaReg;
}ST_GAMERS;

typedef struct{
    int codJuego;
    int codGamer;
}ST_RELACION;

void cargarJuegosPUP (ST_JUEGOS juegos[], int dimension) {
    juegos[0]={101,"JAGA"};
    juegos[1]={100,"PLANTAS"};
    juegos[2]={103,"ZOMBIES"};
    juegos[3]={102,"WARRIORS"};

    return;
}

void cargarGamers (ST_GAMERS gamers[], int dimension) {
    
    gamers[0]={1,"Pepe",20210501};
    gamers[1]={2,"Juana",20210502};
    gamers[2]={3,"Julieta",20210512};
    gamers[3]={4,"Pedro",20210503};

    return;
}

void cargarRelacion (ST_RELACION relacion[], int dimension) {

    relacion[0]={100,1};
    relacion[1]={100,2};
    relacion[2]={101,2};
    relacion[3]={102,1};
    relacion[4]={102,3};
    relacion[5]={103,3};
    relacion[6]={103,4};

    return;
}

void ordenarVec (ST_JUEGOS juegos[], int dimension) {
    int i=0;
    ST_JUEGOS aux;
    bool ordenado = false;

    while (i < dimension && !ordenado){
        ordenado= true; 

        for (int j = 0; j < dimension-i-1 ; j++){
           
            if (juegos[j].codigo>juegos[j+1].codigo){
                aux = juegos[j];
                juegos[j]=juegos[j+1];
                juegos[j+1]=aux;
                ordenado = false;
            }
        }
        i++;
    }

    return;
}

int buscarUsuario (ST_GAMERS gamers[], int dimension, int x) {
    int inicio=0;
    int fin = dimension-1;

    while(fin >= inicio){
        int mitad =inicio + (fin - inicio)/2;

        if (gamers[mitad].codGamer==x){
            return mitad;
        }

        if (gamers[mitad].codGamer>x){
            fin=mitad - 1;
         }else{
            inicio=mitad+1;
         } 
    }
    
    return -1;
}

void corteDeControl (ST_JUEGOS juegos[], ST_GAMERS gamers[], int dimencionG, ST_RELACION relacion[], int dimencionR) {
    int i = 0;
    int contadorGamers = 0;
    int key;
    int pos;
    int posCod=0;

    while(i < dimencionR) {

        key = relacion[i].codJuego;
        contadorGamers = 0;
        posCod=relacion[i].codJuego-100;
        cout<<"Juego: "<<juegos[posCod].nombre<<endl;

        while(i < dimencionR && key == relacion[i].codJuego) {

            pos=buscarUsuario(gamers,dimencionG, relacion[i].codGamer);
            if (pos>-1) {
                cout<<gamers[pos].nombre<<" - "<<gamers[pos].fechaReg<<endl;
            }

            contadorGamers++;
            i++; 
        }
        cout <<"----------------------------------"<<endl;
        cout << "Cant. total de usuarios del juego: " <<contadorGamers << endl;
        cout<<endl;
    }
    return;

}



int main () {
    ST_JUEGOS juegos[MAX_J];
    ST_GAMERS gamers[MAX_U];
    ST_RELACION relacion[MAX_R];

    cargarJuegosPUP(juegos, 4);
    //ordenar juegos
    ordenarVec(juegos, 4);
    
    cargarGamers(gamers, 4);
    cargarRelacion(relacion, 7);

    //Corte de control con impresion
    corteDeControl(juegos, gamers, 4, relacion, 7);
 
    system("pause");
    return 0;
}