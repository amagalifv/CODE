#include <iostream>
using namespace std;

int main () {
 char caracterX;
 int contadorA=0;
 int contadorE=0;
 int contadorI=0;
 int contadorO=0;
 int contadorU=0;
 int cantPalabras=1;
 int cantLetrasAux=0;
 int cantLetrasPalabraMaj=0;

 cout <<"ingrese una oracion por caracter, guion bajo para separar palabras y punto para terminar"<<endl;
 cin>> caracterX;

 while (caracterX != '.'){
 
    switch (caracterX)
    {
    case 'a':
        contadorA=contadorA+1;
        break;
    case 'e':
        contadorE=contadorE+1;
        break;
    case 'i':
        contadorI=contadorI+1;
        break;
    case 'o':
        contadorO=contadorO+1;
        break;
    case 'u':
        contadorU=contadorU+1;
        break;
    case '_':
        cantPalabras=cantPalabras+1;
        break;
    
    default:
        break;
    }

    if (caracterX != '_'){
        cantLetrasAux=cantLetrasAux+1;
        if (cantLetrasAux>cantLetrasPalabraMaj){
            cantLetrasPalabraMaj=cantLetrasAux;
        }
    } else {
            cantLetrasAux=0; 
    }
    cout <<"ingrese otro caracter"<<endl;
    cin>> caracterX;
 }

 cout << "A aparecio " << contadorA << " veces" <<endl;
 cout << "E aparecio " << contadorE << " veces" <<endl;
 cout << "I aparecio " << contadorI << " veces" <<endl;
 cout << "O aparecio " << contadorO << " veces" <<endl;
 cout << "U aparecio " << contadorU << " veces" <<endl;
 cout << "La cantidad de palabras que contiene esta oracion es " <<cantPalabras <<endl;
 cout << "La cantidad de letras de la palabra mas larga es " << cantLetrasPalabraMaj <<endl;
 
system("pause");
 return 0;
}