#include <iostream>
using namespace std;

#define MAX_PROD 100

typedef struct{
    int codigo;
    int stock;
}ST_PRODUCTOS;

typedef struct{
    int nroPedido;
    long int nroCliente;
    int codigo;
    int cantPedida;
}ST_PEDIDOS;

void actualizarStock (ST_PRODUCTOS listProd[MAX_PROD], ST_PEDIDOS pedidos[MAX_PROD], int dimesionPed, ST_PEDIDOS pedidosNoRealz[], int &dimensionNoRealz) {
  int clave;

    for (int i = 0; i < dimesionPed; i++) {
        
        clave= pedidos[i].codigo -1;
        
        if (listProd[clave].stock >= pedidos[i].cantPedida) {
            //--A--
            listProd[clave].stock=listProd[clave].stock-pedidos[i].cantPedida;
            //--B--
            cout<<pedidos[i].nroPedido<<"\t\t"<<pedidos[i].nroCliente<<"\t\t"<<pedidos[i].codigo<<"\t\t"<<pedidos[i].cantPedida<<endl;

        }else{
            //--C--
            pedidosNoRealz[dimensionNoRealz]=pedidos[i];
            dimensionNoRealz++;
        }    
    }

    return;
}

int main () {
    ST_PRODUCTOS listProd[MAX_PROD];
    ST_PEDIDOS pedidos[MAX_PROD];



 
    system("pause");
    return 0;
}