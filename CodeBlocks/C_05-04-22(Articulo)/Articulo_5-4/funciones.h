#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <cstring>

void cargarDiezArts(Articulo *v,int tam){

    for (int i=0; i<tam; i++) {
        v[i].Cargar();
    }
}

void mostrarArts(Articulo *v,int tam){

    for (int i=0; i<tam; i++) {
        v[i].Mostrar();
    }
}

int buscarCodigo(Articulo *v,int tam, const char*cod){

    for (int i=0; i<tam; i++) {

        if(strcmp(v[i].getCodigo(),cod)==0){
            return i;
        }
    }
    return -1;
}

void buscarStockMenor(Articulo *v,int tam, int stock){

    for (int i=0; i<tam; i++) {

        if(v[i].getStock()<=stock){
            v[i].Mostrar();
        }
    }
}

void actualizarPrecio(Articulo *v,int tam, int porcent){
    float decim=((float)porcent/100)+1;
    float num;

    for (int i=0; i<tam; i++) {
        num=v[i].getPrecio()*decim;
        v[i].setPrecio(num);
    }
}

#endif // FUNCIONES_H_INCLUDED
