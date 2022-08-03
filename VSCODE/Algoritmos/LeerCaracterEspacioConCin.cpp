#include <iostream>

using namespace std;

int main(){

    char letra;

    for(int i=0; i< 4; i++){

        cout << "Ingrese una letra: ";
        cin.get(letra);
        cin.ignore();
        if(letra == ' '){
            cout << "Espacio" << endl;
        }
        else{
            cout << "un caracter" << endl;
        }
    }

    return 0;
}