# include<iostream>
# include<cstdlib>
# include<cstring>
using namespace std;

#include "Cls_y_Funcs.h"

const char *AR_CLASENUEVA = "nuevaclase.dat";

class NuevaClass{
    private:
        int i;

    public:
        int getI(){return;}

        void setI (int){;}

        void Mostrar();
        void Cargar();
        bool leerDeDisco(int);
        bool grabarEnDisco();
};

bool NuevaClass::leerDeDisco(int pos){
    FILE *pCls;
    int leyo;

    pCls=fopen(AR_CLASENUEVA ,"rb");
    if (pCls==NULL){return -1;}

    fseek(pCls, sizeof(NuevaClass)*pos,SEEK_SET);
    leyo=fread(this ,sizeof(NuevaClass),1,pCls);
    fclose(pCls);

    return leyo;
}

bool NuevaClass::grabarEnDisco(){
    FILE *pCls;
    bool escribio;

    pCls=fopen(AR_CLASENUEVA ,"ab");
    if (pCls==NULL){return false;}

    escribio=fwrite(this ,sizeof(NuevaClass),1,pCls);
    fclose(pCls);
    return escribio;
}

int main(){
    
    cout<<"H"<<endl;
    
    system("pause");
    return 0;
}
