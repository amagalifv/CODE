#ifndef FUNC_CLIENTES_H_INCLUDED
#define FUNC_CLIENTES_H_INCLUDED
# include<iostream>
# include<cstdlib>
# include<cstring>
using namespace std;

///PROTOTIPOS
int agregarCliente();
int listarClientes();
int grabarRegistroCliente(Cliente);
int buscarClienteDNI(int DNI, bool borrado=false);///devuelve la posici�n que ocupa el registro; si no existe devuelve -1
int listarClientesDNI();
int contarRegistrosCliente();
void cargarArchivoClientesEnVector(Cliente *v, int cant);
void mostrarVectorClientes(Cliente *v, int cant);
void listarClientesDinamico();
void ordenarClientesApe(Cliente *, int);
void ordenarClientesDNI(Cliente *, int);
void ordenarClientesFechaNac(Cliente *, int);


///

int agregarCliente(){///validar que no se repita el cliente en el archivo (exigir siempre un DNI que no est� registrado)
    int DNI;
    Cliente obj;
    int valor;
    cout<<"DNI: ";
    cin>>DNI;
    int encontro=buscarClienteDNI(DNI,1);
    if(encontro==-1){
        obj.Cargar(DNI);
        valor=obj.grabarEnDisco();
        return valor;
    }

    if(encontro==-1){
            cout<<"EL DNI YA EXISTE EN CLIENTES PERO FUE BORRADO"<<endl;
            return encontro;
    }
    cout<<"EL DNI YA EXISTE EN CLIENTES"<<endl;
    return 0;
}

int grabarRegistroCliente(Cliente reg){
    FILE *p;
    int escribio;
    p=fopen("clientes.dat", "ab");
    if(p==NULL)return -1;
    escribio=fwrite(&reg, sizeof(Cliente) ,1, p);
    fclose(p);
    return escribio;
}
/*
int listarClientes(){
    Cliente reg;
    FILE *p;
    int leyo=0;
    p=fopen("clientes.dat", "rb");
    if(p==NULL)return -1;
    while(fread(&reg, sizeof(Cliente) ,1, p)==1){
            reg.Mostrar();
            leyo=1;
            cout<<endl;
    }
    fclose(p);
    return leyo;
}*/

int listarClientes(){
    Cliente reg;
    int leyo=0, pos=0;

    while(reg.leerDeDisco(pos)==1){
            reg.Mostrar();
            leyo=1;
            pos++;
            cout<<endl;
    }
    return leyo;
}

int buscarClienteDNI(int DNI, bool borrado){
    Cliente reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
            if(reg.getDNI()==DNI){
                if(reg.getEstado()==true){
                    return pos;
                }
                else{
                    if(borrado==false){
                        return -1;
                    }
                    else{
                        return pos;
                    }
                }
            }
            pos++;
    }
    return -1;
}

int listarClientesDNI(){
    int DNI ,pos;
    Cliente obj;
    cout<<"INGRESE EL DNI DEL CLIENTE: ";
    cin>>DNI;
    pos=buscarClienteDNI(DNI);
    if(pos==-2) return -1;
    obj.leerDeDisco(pos);
    obj.Mostrar();
    return 1;
}

int contarRegistrosCliente(){
    int pos=0;
    Cliente reg;
    while(reg.leerDeDisco(pos))pos++;
    return pos;
}

int contarRegistrosClienteBis(){
    FILE *p;
    p=fopen("clientes.dat","rb");
    if(p==NULL) return -1;
    fseek(p,0,2);
    int cant=ftell(p)/sizeof(Cliente);
    fclose(p);
    return cant;
}

void cargarArchivoClientesEnVector(Cliente *v, int cant){
    for(int pos=0;pos<cant;pos++){
        v[pos].leerDeDisco(pos);
    }
}

void mostrarVectorClientes(Cliente *v, int cant){
    for(int pos=0;pos<cant;pos++){
        v[pos].Mostrar();
        cout<<endl;
    }
}

void listarClientesDinamico(){
    int cant=contarRegistrosCliente();
    if(cant<=0) exit(1);
    Cliente *vec;
    vec=new Cliente[cant];
    if(vec==NULL) exit(2);
    cargarArchivoClientesEnVector(vec,cant);
    ordenarClientesApe(vec, cant);
    mostrarVectorClientes(vec,cant);
    delete vec;
}

void ordenarClientesApe(Cliente *vec, int cantReg){
    int i, j, posMin=0;
    Cliente aux;
    for(i=0;i<cantReg-1;i++){
        posMin=i;
        for(j=i+1;j<cantReg;j++){
            if(strcmp(vec[j].getApellido(), vec[posMin].getApellido())<0){
               posMin=j;
               }
        }
        aux=vec[i];
        vec[i]=vec[posMin];
        vec[posMin]=aux;
    }

}

void ordenarClientesDNI(Cliente *vec, int cantReg){
    int i, j, posMin=0;
    Cliente aux;
    for(i=0;i<cantReg-1;i++){
        posMin=i;
        for(j=i+1;j<cantReg;j++){
            if(vec[j].getDNI()<vec[posMin].getDNI()){
               posMin=j;
            }
        }
        aux=vec[i];
        vec[i]=vec[posMin];
        vec[posMin]=aux;
    }

}
void ordenarClientesFechaNac(Cliente *vec, int cantReg){
    int i, j, posMin=0;
    Cliente aux;
    for(i=0;i<cantReg-1;i++){
        posMin=i;
        for(j=i+1;j<cantReg;j++){
            if(vec[j].getFechanacimiento()<vec[posMin].getFechanacimiento()){ //sobrecargar operador en clase fecha
               posMin=j;
            }
        }
        aux=vec[i];
        vec[i]=vec[posMin];
        vec[posMin]=aux;
    }

}


#endif // FUNC_CLIENTES_H_INCLUDED
