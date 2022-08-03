#include <iostream>
using namespace std;

int main () {
 int num=0;
 int unidad=0;
 int decena=0;
 int centena=0;
 int millar=0;
 string romUnidad;
 string romDecena;
 string romCentena;
 string romMillar;

 cout<< "Ingrese un numero de  4 cifras del 1 al 3999"<< endl;
 cin>> num;

 unidad= num % 10;
 decena= (num % 100)/10;
 centena= (num%1000)/100;
 millar=num/1000;

 if (num>=1 && num <=3999) {
    switch (unidad){
        case 1:
            romUnidad="I";
        break;
        case 2:
            romUnidad="II";
            break;
        case 3:
            romUnidad="III";
            break;
        case 4:
            romUnidad="IV";
            break;
        case 5:
            romUnidad="V";
            break;
        case 6:
            romUnidad="VI";
            break;
        case 7:
            romUnidad="VII";
            break;
        case 8:
            romUnidad="VIII";
            break;
        case 9:
            romUnidad="IX";
            break;
    }

    switch (decena){
        case 1:
            romDecena="X";
            break;
        case 2:
            romDecena="XX";
            break;
        case 3:
            romDecena="XXX";
            break;
        case 4:
            romDecena="XL";
            break;
        case 5:
            romDecena="L";
            break;
        case 6:
            romDecena="LX";
            break;
        case 7:
            romDecena="LXX";
            break;
         case 8:
            romDecena="LXXX";
            break;
        case 9:
            romDecena="LC";
            break;
    }
    switch (centena){
        case 1:
            romCentena="C";
            break;
        case 2:
            romCentena="CC";
            break;
        case 3:
            romCentena="CCC";
            break;
        case 4:
            romCentena="CD";
            break;
        case 5:
            romCentena="D";
            break;
        case 6:
            romCentena="DC";
            break;
        case 7:
            romCentena="DCC";
            break;
        case 8:
            romCentena="DCCC";
            break;
        case 9:
            romCentena="CM";
            break;
    }

    switch (millar){
        case 1:
            romMillar="M";
            break;
        case 2:
            romMillar="MM";
            break;
        case 3:
            romMillar="MMM";
            break;
    }

 }
 
 cout << "Su equivalente en numeros romanos es: "<<romMillar<<romCentena<<romDecena<<romUnidad<<endl;

 system("pause");
 return 0;
}