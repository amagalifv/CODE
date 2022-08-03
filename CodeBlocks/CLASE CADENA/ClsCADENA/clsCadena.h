#ifndef CLSCADENA_H_INCLUDED
#define CLSCADENA_H_INCLUDED

# include<iostream>
#include <cstring>
using namespace std;

//agregar "algo" a cadena

class Cadena{
    private:
        char *pCad;
        int _dime;
    public:
        Cadena(const char *texto){
            _dime=strlen(texto)+1;
            pCad = new char[_dime];
            if (pCad==NULL){return;}
            strcpy(pCad, texto);
            pCad[_dime-1]='\0';
        }
        ~Cadena(){delete pCad;}

        void Mostrar(){cout<<pCad<<endl;}

        bool operator==(Cadena &texto){
            if (strcmp(pCad, texto.pCad)==0){return true;}
            return false;
        }
        bool operator==(const char *texto){
            if (strcmp(pCad, texto)==0){return true;}
            return false;
        }
        void operator= (const char *texto){
            delete pCad;

            _dime=strlen(texto)+1;
            pCad = new char[_dime];
            if (pCad==NULL){return;}
            strcpy(pCad, texto);
            pCad[_dime-1]='\0';
        }
        bool operator> (Cadena &texto){
            if (strcmp(pCad,texto.pCad)>0){
                return true;
            }
            return false;
        }
        bool operator> (char *texto){
            if (strcmp(pCad,texto)>0){
                return true;
            }
            return false;
        }
        bool operator> (int &tamanio){
            if (tamanio>_dime){
                return true;
            }
            return false;
        }


    // GETTERS
        int getDimension(){return _dime;}
    // SETTERS
        void setpCad(const char *textoNuevo){
            delete pCad;

            _dime=strlen(textoNuevo)+1;
            pCad = new char[_dime];
            if (pCad==NULL){return;}
            strcpy(pCad, textoNuevo);
            pCad[_dime-1]='\0';
        }

        int contarCaracter (char letra);
        bool buscarCaracter (char letra);
        void ConvertirMayuscula();

};

int Cadena::contarCaracter (char letra){
    int cont=0;

    for (int i=0; i<_dime; i++) {
        if(pCad[i]==letra){cont++;}
    }
    return cont;
}

bool Cadena::buscarCaracter (char letra){
    for (int i=0; i<_dime; i++) {
        if(pCad[i]==letra){return true;}
    }
    return false;
}

void Cadena::ConvertirMayuscula(){
    for (int i=0; i<_dime; i++) {
        if(96<pCad[i] && pCad[i]<123){
            pCad[i]=pCad[i]-32;
        }
    }
}


#endif // CLSCADENA_H_INCLUDED
