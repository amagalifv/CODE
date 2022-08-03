#include <iostream>
using namespace std;

int main () {
 int num=0;
 int sumNum=0;

 for (num=0; num <= 99; num++) {
     cout << num <<endl;
     sumNum=num+sumNum;
 }
 cout << "La suma de todos los numeros ingresados es: " << sumNum <<endl;

system ("pause");

 return 0;

}
