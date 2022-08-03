#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <iostream>
#include <cstdlib>
using namespace std;

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

int buscarPosDni(int dni){
  FILE *pCli;
  Cliente cli;
  int devol=1;
  int i=0;

  pCli=fopen(AR_CLIENTES,"rb");
  if (pCli==NULL){return -2;}

  while (devol==1) {
    devol=fread(&cli ,sizeof(Cliente),1,pCli);
    if (cli.getDni()==dni) {
      return i;
      fclose(pCli);
    }
    i++;
  }
  fclose(pCli);
  return -1;
}

void listarClientes(){
  Cliente cli;
  int i=0;

  while (cli.leerDeDisco(i)==1) {
    cli.Mostrar();
    i++;
  }
}

void listarDniMayores(int dni){
    FILE *pCli;
    Cliente cli;

    pCli=fopen(AR_CLIENTES,"rb");
    if (pCli==NULL){return;}

    while (fread(&cli ,sizeof(Cliente),1,pCli)==1) {
        if (cli.getDni()>dni) {
            cli.Mostrar();
        }
    }
    fclose(pCli);
}


void listarMenores(Fecha fNac){
    FILE *pCli;
    Cliente cli;

    pCli=fopen(AR_CLIENTES,"rb");
    if (pCli==NULL){return;}

    while (fread(&cli ,sizeof(Cliente),1,pCli)==1) {

        if (cli.getFechaNac().getConsol()<fNac.getConsol()) {
            cli.Mostrar();
        }
    }
    fclose(pCli);
}

#endif // FUNCIONES_H_INCLUDED
