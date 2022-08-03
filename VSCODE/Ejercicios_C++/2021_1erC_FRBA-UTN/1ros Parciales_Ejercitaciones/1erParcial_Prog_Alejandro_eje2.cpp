#include <iostream>
using namespace std;

void cargarDatoInt (string mensaje, int &dato) {

    cout<<mensaje<<endl;
    cin>>dato;

    return;
}

void cargarDatoString (string mensaje, string &dato) {

    cout<<mensaje<<endl;
    cin>>dato;

    return;
}

void imprimirFloat (float dato, string mensaje) {

    cout<<mensaje<<dato<<endl;

    return;
}

void imprimirInt (int dato, string mensaje) {

    cout<<mensaje<<dato<<endl;

    return;
}

float calcularPromedio (int suma, int cant){
    float prom=0;

    prom=suma/cant;

    return prom;
}

float calcularProcentaje(int total, int cantX){
    float porcentaje=0;

    porcentaje=(cantX*100)/total;

    return porcentaje;
}

int main () {
    string nombre;
    string apellido;
    int masViejo=0;
    int contMasViejo=0;
    int masJoven=300;
    int contMasJoven=0;
    int edad;
    int sistOp;
    int contLinux=0;
    int contLinuxEdades=0;
    int contWind=0;
    int contMac=0;
    int cantAlumnos=0;
    int contEdades=0;
    float porcentLinux;
    float porcentWind;
    float porcentMac;
    float promEdadesTotal;
    float promEdadesLinux;


    cargarDatoInt ("Ingrese la edad del alumno", edad);

    while (edad>0) {

        cargarDatoString ("Ingrese el nombre de el alumno", nombre);
        cargarDatoString ("Ingrese el apellido de el alumno", apellido);

        cargarDatoInt ("Ingrese el sistema operativo 1-Linux 2-Windows 3-Mac", sistOp);

        switch (sistOp){
            case 1:
                contLinux++;
                contLinuxEdades+=edad;
                break;
            case 2:
                contWind++;
                break;
            case 3:
                contMac++;
                break;
            default:
                break;
        }

        cantAlumnos++;
        contEdades+=edad;

        if (edad==masViejo){
            contMasViejo++;
        }

        if (edad==masJoven){
            contMasJoven++;
        }

        if (edad>masViejo){
            masViejo=edad;
            contMasViejo=1;
        }

        if (edad<masJoven){
            masJoven=edad;
            contMasJoven=1;
        }


        cargarDatoInt ("Ingrese la edad del alumno", edad);
    }

    imprimirInt(cantAlumnos,"Total de estudiantes: ");

    promEdadesTotal=calcularPromedio(contEdades, cantAlumnos);
    imprimirFloat(promEdadesTotal,"El promedio de edades total de los alumnos es: ");

    porcentWind=calcularProcentaje(cantAlumnos,contWind);
    imprimirFloat(porcentWind,"El porcentaje de alumnos que usa Windows es: %");
    imprimirInt(contWind,"Total de estudiantes que usan Windows: ");

    porcentMac=calcularProcentaje(cantAlumnos,contMac);
    imprimirFloat(porcentMac,"El porcentaje de alumnos que usa Mac es: %");
    imprimirInt(contMac,"Total de estudiantes que usan Mac: ");

    porcentLinux=calcularProcentaje(cantAlumnos,contLinux);
    imprimirFloat(porcentLinux,"El porcentaje de alumnos que usa Linux es: %");
    imprimirInt(contLinux,"Total de estudiantes que usan Linux: ");
    promEdadesLinux=calcularPromedio(contLinuxEdades, contLinux);
    imprimirFloat(promEdadesLinux,"El promedio de edades de los que usan Linux es: ");

    imprimirInt(masJoven, "El más joven tiene: ");
    imprimirInt(contMasJoven, "La cantidad de alumnos que tienen la misma edad es: ");

    imprimirInt(masViejo, "El más viejo tiene: ");
    imprimirInt(contMasViejo, "La cantidad de alumnos que tienen la misma edad es: ");

    system("pause");
    return 0;
}