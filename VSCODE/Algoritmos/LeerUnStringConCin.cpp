#include <iostream>
using namespace std;
// Fuente https://www.cplusplus.com/reference/string/string/getline/
//Este archivo es un ejemplo básico que lee sólo un string en una función y los retorna.

string devuelveFrase(){
    string frase;
    cout << "Ingrese frase: ";
    getline(cin, frase);
    cout << endl;
   
    return frase;
}

int main(){
    
    string frase;
    frase = devuelveFrase();
    cout << "-------------" << endl;
    cout << "Frase ingresada: " << frase << endl;
     
    return 0;
}