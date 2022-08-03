#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

/*
1) Hacer funciones que reciban los mismos parámetros y realicen las mismas acciones que las siguientes funciones de la librería string.h:
- int strcmp(char *, char *)
- void strcpy(char*, char *)
- int strlen(char *)
- char * strcat(char *, char *)
*/
void mostrarCadena (char* vchar){
    int i=0;

    while(vchar[i]!='\0'){
        cout<<vchar[i];
        i++;
    }

}

int stringCompare(char* vchar1, char* vchar2){
    int i=0;

    while (vchar1[i]!='\0' && vchar2[i]!='\0'){

        if (vchar1[i]>vchar2[i]) {
            return 1;
        }

        if (vchar1[i]<vchar2[i]) {
            return -1;
        }

        i++;
    }

    return 0;
}

int stringLength(char* vchar){
    int i=0;

    while (vchar[i]!='\0') {
        i++;
    }
    return i;
}

void stringCopy (char* vchar1, char* vchar2){
    int i=0;

    while(vchar2[i]!='\0'){
        vchar1[i]=vchar2[i];
        i++;
    }
}

char* stringConcatenate (char* vchar1, const char* vchar2){
    int long1, long2;
    long1=strlen(vchar1);
    long2=strlen(vchar2);
    int j=0;

    for (int i=long1; i<long1+long2; i++) {
        vchar1[i]=vchar2[j];
        j++;

        if (i==long1+long2-1){
            vchar1[long1+long2]='\0';
        }
    }

}

int main () {
    char* vChar1="Ana_Magali"; //declaro la variable puntero y escribe eso en vec de char
    char vChar2[30]="Fernandez Vilchez";//declaro vector de 20 char y cargo
    int cantChar;
    char* p;

    //cantChar=stringLength(vChar1);
    //cout<<"Cantidad de char de vChar1: "<<cantChar<<endl;

    //cantChar=stringCompare(vChar1, vChar2);
    //cout<<"Compara: "<<cantChar<<endl;

    //stringCopy(p, vChar2);
    //mostrarCadena(p);
    //cout<<endl;

    //p=strcat(vChar2, ", Ana Magali");
    p=stringConcatenate(vChar2, ", Ana Magali");
    mostrarCadena(vChar2);
    cout<<endl;

    system("pause");
    return 0;
}