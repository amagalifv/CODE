#include <iostream>
#include <cstdlib>
using namespace std;

/*
ASIGNACION DINAMICA DE MEMORIA
proceso q permite solicitar memoria adic al SSOO en TIEMPO DE EJECUCION
nos permite utilizar la memoria EXACTA q necesitamos y una vez utilizada DEBEMOS liberarla (DELETE VARIABLE)
nos permite usar una mayor cant de memoria en comparacion con la manera "convencional"
MEMORIA STACK(procesos de programas) vs MEMORIA HIP (memoria libre del SSOO)
cada variable q declaramos es memoria stack, incluso el main. Ésta es limitada, de superarla se genera una excepción(stack overflow o desvordamiento de pila)
*/

int main () {
    float *vec = nullptr;//declaro el puntero
    int tam=5000000; //el tamano
    vec= new float [tam]; //acá solicito la memoria para crear el vector con la palabra NEW

    if(vec!= nullptr){

        for (int i=0; i<tam; i++) {
            vec[i]=0;
        }
    }
    cout<<vec[tam-1]<<endl;
    delete vec; //para liberar la memoria que ya no uso

    system("pause");
    return 0;
}