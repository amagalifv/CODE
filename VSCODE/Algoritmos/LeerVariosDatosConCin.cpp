#include <iostream>
using namespace std;
// Fuente https://www.cplusplus.com/reference/string/string/getline/
//Este archivo lee varios datos en un procedimiento. Hace uso de la función cin.ignore() 
//para eliminar caracteres como "retorno de línea" que pueden hacer fallar la lectura de datos siguientes.

string devuelveFrase(){
    string frase;
    cout << "Ingrese frase: ";
    getline(cin, frase);
    cout << endl;
   
    return frase;
}

void devuelveDatos(int &edad, string &nombre){
    
    cout << "Ingrese edad: ";
    cin >> edad;
    cout << endl;
    
    // Hace que se elimine el retorno de línea del buffer
    cin.ignore();
    
    cout << "Ingrese nombre: ";
    getline(cin, nombre);
    cout << endl;
    return;
    
}

int main(){

    string nombre;
    int edad = 0;
    devuelveDatos(edad, nombre);
    cout << "-------------" << endl;
    cout << "Nombre ingresada: " << nombre << " tiene: " << edad << endl;
    return 0;
}