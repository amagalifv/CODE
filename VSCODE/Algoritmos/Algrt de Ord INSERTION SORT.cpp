#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){
    int i;
    int j;
    int key;

    for (int i = 1; i < n; i++){
        key=arr[i];
        j=i-1;

        //Movemos los elementos de arr[0..i-1], que son
        //mas grandes que key, a la posicion siguiente
        //a su posicion actual

        while (j>=0 && arr[j] > key ){
            arr[j+1]=arr[j];
            j = j -1;
        }
        arr[j+1]= key;
    }
}

int main () {

system("pause");
 return 0;
}