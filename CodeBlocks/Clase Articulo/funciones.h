#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <iostream>
#include <cstring>

void cargarCadena(char *pal, int tam){
  int i;
  fflush(stdin);
  for(i=0;i<tam;i++){
      pal[i]=cin.get();
	  if(pal[i]=='\n') break;
	  }
  pal[i]='\0';
  fflush(stdin);
}



int buscarRegistros(int dniBusc){
    FILE *p;
    Cliente reg;
    p=fopen("cliente.dat", "rb");
    int i;

    if(p==NULL){cout<<"ERROR DE ARCHIVO";};

    while(fread(&reg, sizeof reg, 1, p)==1){

        if(reg.getDni()==dniBusc){
            fclose(p);
            return i;
        }
        i++;
    }
    fclose(p);

    return -1;
}

int menuC(){
    Cliente cli("Pepe");


    while(true){
        int opc;
        cout<<"-------------MENU-------------\n";
        cout<<"OPCION 1: CARGAR CLIENTE      \n";
        cout<<"OPCION 2: MOSTRAR CLIENTES    \n";
        cout<<"OPCION 3: BUSCAR CLIENTE      \n";
        cout<<"OPCION 0: EXIT                \n";
        cout<<"-------------MENU-------------\n";
        cin>>opc;
        system("cls");

        switch(opc){

            case 1: cli.Cargar();
                    if(cli.CargarRegistro()!=1){
                        cout<<"ERROR EN CARGA\n";
                        return -1;
                    }else{cout<<"CARGA EXITOSA\n";}
                break;

            default:
                return 0;
                break;
        }
    }


    return 0;
}

#endif // FUNCIONES_H_INCLUDED
