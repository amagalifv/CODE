#include <iostream>
using namespace std;

int pedirNum (string mensaje);
void nacimientosOctubre(int mes, int &contOct);
int fusionarFecha (int dia, int mes, int anio);
void antes9julio1990 (int fechaFus, int &contAntes90);
void nacimientosPrimavera82 (char sex, int fechaFus, int &contPrim82);
void masViejoSexo (char sex, int fechaFus, char &sexoMasGrande, int &edadMasGrande);

int main () {
    int diaNac;
    int mesNac=0;
    int anioNac=0;
    int fechaConsol=0;
    char sexo;
    int contOctubre=0;
    int contadorAntes9julio1990=0;
    int contadorPrimavera82=0;
    int edadMasViejo=0;
    char sexoMasViejo;

    diaNac= pedirNum ("Ingrese el dia de nacimiento");

    while ( diaNac != 0 ){
        mesNac= pedirNum ("Ingrese el mes de nacimiento");
        anioNac= pedirNum ("Ingrese el año de nacimiento");
        cout << "Ingrese el sexo"<< endl;
        cin>>sexo;

        nacimientosOctubre(mesNac, contOctubre);
        fechaConsol=fusionarFecha (diaNac, mesNac, anioNac);
        antes9julio1990(fechaConsol, contadorAntes9julio1990);
        nacimientosPrimavera82(sexo, fechaConsol, contadorPrimavera82);
        masViejoSexo(sexo, fechaConsol, sexoMasViejo ,edadMasViejo);

        diaNac= pedirNum ("Ingrese el dia de nacimiento");
    }

    cout<< "La cantidad de nacidos en Octubre es" << contOctubre <<endl;
    cout<< "La cantidad de nacidos antes del 9 de Julio de 1990 es "<< contadorAntes9julio1990<<endl;
    cout<< "La cantidad de nacidos en la primavera del 82 es " << contadorPrimavera82 <<endl;
    cout<< "El sexo de la persona mas grande es "<< sexoMasViejo <<endl;

    system("pause");
    return 0;
}

int pedirNum (string mensaje){
    int num;
    cout << mensaje << endl;
    cin >> num;

    return num;
}

void nacimientosOctubre(int mes, int &contOct){
    if (mes==10){
        contOct++;
    }
}

int fusionarFecha (int dia, int mes, int anio){
 return anio*10000+mes*100+dia;
}

void antes9julio1990 (int fechaFus, int &contAntes90){
    if (fechaFus<19900709){
        contAntes90++;
    }
}

void nacimientosPrimavera82 (char sex, int fechaFus, int &contPrim82){
    if (sex == 'F' && fechaFus>19820922 && fechaFus<19821221){
        contPrim82++;
    }
}

void masViejoSexo (char sex, int fechaFus, char &sexoMasGrande, int &nacMasGrande){
    if (fechaFus<nacMasGrande || nacMasGrande==0){
        nacMasGrande=fechaFus;
        sexoMasGrande=sex;
    }
}
