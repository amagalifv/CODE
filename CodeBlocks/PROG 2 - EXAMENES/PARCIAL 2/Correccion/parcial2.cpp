///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
# include<cstring>

using namespace std;

# include "parcial2.h"

int main(){
    Pasajero reg;
    /*for(int i=0;i<6;i++){
        reg.Cargar();
        reg.grabarEnDisco();
    }*/
    for(int i=0;i<6;i++){
        reg.leerDeDisco(i);
        reg.Mostrar();
        cout<<endl;
    }
	system("pause");
	return 0;
}
