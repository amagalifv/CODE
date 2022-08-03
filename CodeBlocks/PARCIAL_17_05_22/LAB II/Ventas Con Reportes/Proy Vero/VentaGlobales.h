#ifndef VENTAGLOBALES_H_INCLUDED
#define VENTAGLOBALES_H_INCLUDED

#include "Articulo.h"
#include "ArticuloGlobales.h"
#include "ClienteGlobales.h"
#include "Fecha.h"
#include "funciones.h"
#include "Venta.h"

using namespace std;

///PROTOTIPOS DE FUNCIONES GLOBALES DE LA CLASE VENTA
void menuVentas();

int proximaVenta();
int buscarVentaPorId(int idVenta);
void agregarVenta();
void listarVentaPorId();
void listarTodasLasVentas();
void modificarCantidad();
void cargaMasivaVentasInicio();
bool habilitarVentaProducto(char *auxChar);
bool validarCodigoArticulo(const char *pCodArticulo);
int consultarStock(const char *auxChar);
bool validarStock(const char *auxChar, int auxInt);
bool validarMinimo(int auxInt);
float calcularImporte(int auxInt, const char *auxChar);
///FIN PROTOTIPOS DE FUNCIONES GLOBALES DE LA CLASE VENTA

///FUNCIONES GLOBALES DE LA CLASE VENTA
void menuVentas(){
    int opc=0;

    cout<<"**** MENU VENTAS ****"<<endl<<endl;
    cout<<"1. AGREGAR VENTA"<<endl;
    cout<<"2. LISTAR VENTA POR ID"<<endl;
    cout<<"3. LISTAR TODAS LAS VENTAS"<<endl;
    cout<<"4. MODIFICAR CANTIDAD"<<endl;
    cout<<"****************************"<<endl;
    cout<<"0. VOLVER AL MENU PRINCIPAL"<<endl<<endl;
    cout<<"SELECCIONES UNA DE LAS OPCIONES: ";
    cin>>opc;
    system("cls");

    switch (opc){
        //1. AGREGAR VENTA
        case 1: agregarVenta();
            system("pause");
            break;

        //2. LISTAR VENTA POR ID
        case 2: listarVentaPorId();
            system("pause");
            break;

        //3. LISTAR TODAS LAS VENTAS
        case 3: listarTodasLasVentas();
            system("pause");
            break;

        //"4. MODIFICAR CANTIDAD
        case 4: modificarCantidad();
            system("pause");
            break;

        case 0: return;

        default:
            break;
    }
}
int buscarVentaPorId(int idVenta){
    ///DEVUELVE LA POSICION DEL ARCHIVO DEL ARTICULO BUSCADO POR ID
    Venta reg;
    int posDisco=0;

    while(reg.leerDeDisco(posDisco)==1){
        if(reg.getIdVenta()==idVenta){
            return posDisco;
        }
        posDisco++;
    }

    posDisco=-1;

    return posDisco;
}
void agregarVenta(){
    ///AGREGA UNA NUEVA VENTA AL ARCHIVO
    Venta reg;
    int posDni=0;
    int dniCliente;
    char codProd[5]={0};
    int cantUnidades=0;
    float Importe;

    cout<<"DNI DEL CLIENTE (0 para cancelar): ";
    cin>>dniCliente;

    if(dniCliente==0){
        cout<<"Operacion cancelada!"<<endl;
        return;
    }

    posDni=buscarClientePorDni(dniCliente);

    while(posDni==-1){
        cout<<"Ese cliente no existe, reingrese el dni: ";
        cin>>dniCliente;
        posDni=buscarClientePorDni(dniCliente);
    }

    cout<<"CODIGO DEL ARTICULO: ";
    cargarCadena(codProd,5);

    while(!habilitarVentaProducto(codProd)){
        cargarCadena(codProd,5);
    }

    cout<<"CANT DE UNIDADES: ";
    cin>>cantUnidades;

    while(!validarStock(codProd, cantUnidades)){
        cin>>cantUnidades;
    }

    Importe=calcularImporte(cantUnidades, codProd);

    reg.Cargar(dniCliente, codProd, cantUnidades, Importe);

    actualizarStock(cantUnidades, codProd);

    if(reg.grabarEnDisco()==1){
        cout<<"Venta agregada exitosamente."<<endl;
    }
}
void listarVentaPorId(){
    ///LISTA TODAS LAS VENTAS POR ID SIN RESTRICCIONES
    Venta reg;
    int posDisco=0;
    int auxInt=0;

    cout<<"INGRESE EL CODIGO DE VENTA A LISTAR: ";
    cin>>auxInt;
    cout<<endl;

    posDisco=buscarVentaPorId(auxInt);

    if(posDisco==-1){
        cout<<"No existe ese codigo de venta."<<endl;
    }
    else{
        cout<<"***** VENTA ENCONTRADA *****"<<endl;
        reg.leerDeDisco(posDisco);
        reg.Mostrar();
    }
}
void listarTodasLasVentas(){
    ///LISTA TODAS LAS VENTAS SIN RESTRICCIONES
    Venta reg;
    int posDisco=0;
    int contador=0;

    cout<<"**** LISTADO DE VENTAS ****"<<endl<<endl;

    while(reg.leerDeDisco(posDisco)==1){
        reg.Mostrar();
        contador++;
        posDisco++;
    }

    cout<<"Total "<<contador<< " ventas."<<endl;
}
void modificarCantidad(){
    ///MODIFICA LA CANTIDAD DE ARTICULOS DE UNA VENTA
    Venta regVenta;
    Articulo regArticulo;
    int posDiscoVenta=0;
    int posDiscoArticulo=0;
    int auxInt=0;
    int cantidad=0;
    float importe=0;
    float precioUnitario=0;
    const char *articulo;
    int aDescontar=0;

    cout<<"INGRESE EL CODIGO DE VENTA A BUSCAR (0 para cancelar): ";
    cin>>auxInt;

    if(auxInt==0){
        cout<<"Operacion cancelada!"<<endl;
        return;
    }

    posDiscoVenta=buscarVentaPorId(auxInt);

    if(posDiscoVenta==-1){
        cout<<"No existe ese codigo de venta."<<endl;
    }
    else{
        regVenta.leerDeDisco(posDiscoVenta);

        //busco el codigo del articulo con el codigo obtenido del objeto venta para luego leerlo y modificarlo
        //no se valida porque si ya est� en la venta, el c�digo existe. Ya se valid� antes.
        posDiscoArticulo=buscarArticuloPorCodigo(regVenta.getCodArticulo());
        regArticulo.leerDeDisco(posDiscoArticulo);

        articulo=regVenta.getCodArticulo();

        cout<<"**** DATOS DE LA VENTA A MODIFICAR ****"<<endl;
        regVenta.Mostrar();
        cout<<"***************************************"<<endl<<endl;

        //calculo el precio unitario para ajustar luego el importe
        cantidad=regVenta.getCantUnidades();
        importe=regVenta.getImporte();
        precioUnitario=importe/cantidad;

        //pido la cantidad a actualizar en la venta
        cout<<"Indique la nueva cantidad: ";
        cin>>auxInt;

        //si la cantidad de la venta es mayor a la nueva cantidad, directamente ajusto stock.
        if(auxInt<=cantidad){
            int stockActual=regArticulo.getStock();
            int diferencia= cantidad-auxInt;

            regArticulo.setStock(stockActual+diferencia);
        }
        else{
            //verifico si hay stock del producto a actualizar, si la cantidad a actulizar es mayor al stock vuelvo
            //a pedirla, previamente muestro stock diponible.
            aDescontar=auxInt-cantidad;

            while (!validarStock(articulo, abs(aDescontar))){
                cin>>auxInt;
                aDescontar=auxInt-cantidad;
            }
            regArticulo.setStock(regArticulo.getStock()-aDescontar);
        }

        //actualizo cantidad e importe en el objeto Venta
        regVenta.setCantUnidades(regVenta.getCodArticulo(), auxInt);
        regVenta.setImporte(precioUnitario*auxInt);


        //En base al resultado de la grabaci�n del dato muestro el registro modificado o no.
        if(regVenta.grabarEnDisco(posDiscoVenta) && regArticulo.grabarEnDisco(posDiscoArticulo)==1){
            cout<<endl<<"Actualizacion exitosa!"<<endl;
            cout<<"**** DATOS DE LA VENTA MODIFICADA ****"<<endl;
            regVenta.Mostrar();
            cout<<"***************************************"<<endl<<endl;
        }
        else{
            cout<<"No se pudo modificar la cantidad"<<endl;
        }
    }
}
void cargaMasivaVentasInicio(){
    Venta reg;
    int posDisco=-1;
    int auxInt;

    cout<<"CODIGO DEL CLIENTE: ";
    cin>>auxInt;

    while(auxInt!=-9){
        reg.Cargar(auxInt);
        if(reg.grabarEnDisco(posDisco)==1){
            cout<<"Venta agregada exitosamente."<<endl;
        }

        cout<<"CODIGO DEL CLIENTE: ";
        cin>>auxInt;
    }
}
bool habilitarVentaProducto(char *auxChar){
    ///VERIFICA SI EL PRODUCTO ES VALIDO Y SI TIENE STOCK POSITIVO
    int stockDisponible=0;
    bool articuloValido=validarCodigoArticulo(auxChar);

    if(articuloValido){
        stockDisponible=consultarStock(auxChar);
        if(stockDisponible==0){
            cout<<"No hay stock del articulo, seleccione otro: ";
        }
    }

    while(!articuloValido || stockDisponible==0){

        while (!articuloValido){
            cout<<"Codigo invalido, ingrese otro codigo: ";
            return false;
        }

        while(stockDisponible==0){
            return false;
        }
    }
    return true;
}
bool validarCodigoArticulo(const char *pCodArticulo){
    ///VERIFICA SI EL COD DEL ARTICULO EXISTE
    Articulo reg;
    int posDisco=0;

    posDisco=buscarArticuloPorCodigo(pCodArticulo);

    if(posDisco==-1){
        return false;
    }

    return true;
}
int consultarStock(const char *auxChar){
    ///DEVUELVE EL STOCK DEL PRODUCTO
    Articulo reg;
    int posDisco=0;
    int stockDisponible=0;

    posDisco=buscarArticuloPorCodigo(auxChar);

    if(posDisco!=-1){
        reg.leerDeDisco(posDisco);

        stockDisponible=reg.getStock();

        // if(stockDisponible==0){
        //     cout<<"No hay stock del articulo, seleccione otro: ";
        // }
    }

    return stockDisponible;
}
bool validarStock(const char *auxChar, int cantUnidades){
    ///VERIFICA SI SE PUEDE VENDER LA CANTIDAD DE STOCK INGRESADA
    int stockDisponible=0;

    stockDisponible=consultarStock(auxChar);

    if(stockDisponible==0){
        cout<<"No hay stock del articulo, operacion cancelada."<<endl;
        return false;
    }

    if (!validarMinimo(cantUnidades)){
        return false;
    }

    if(cantUnidades>stockDisponible){
        cout<<"Stock insuficiente. Stock disponible: "<<stockDisponible<<" unidades."<<endl;
        cout<<"Escriba nuevamente la cantidad: ";
        return false;
    }

    return true;
}
bool validarMinimo(int cantUnidades){
    ///VERIFICA SI LA CANTIDAD A VENDER ES POSITIVA
    if(cantUnidades<1){
        while(cantUnidades<1){
            cout<<"Cantidad invalida, debe ser de al menos 1 unidad."<<endl;
            cout<<"Escriba nuevamente la cantidad: ";
            return false;
        }
    }

    return true;
}
float calcularImporte(int cantUnidades, const char *pCodArticulo){
    ///DEVUELVE EL IMPORTE CALCULADO (PRECIO UNITARIO ARTICULO * CANTIDAD)
    Articulo regArticulo;
    int posDiscoArticulo=0;
    float importe=0;
    float precioUnitario=0;

    //busco la posicion de lo que busco dentro de los articulos
    posDiscoArticulo=buscarArticuloPorCodigo(pCodArticulo);

    //cargo los datos en la variable y la uso para buscar el precio
    regArticulo.leerDeDisco(posDiscoArticulo);

    //asigno valores a variables con los datos obtenidos
    precioUnitario=regArticulo.getPrecio();
    importe=cantUnidades*precioUnitario;

    return importe;
}
///FIN FUNCIONES GLOBALES DE LA CLASE VENTA

#endif // VENTAGLOBALES_H_INCLUDED
