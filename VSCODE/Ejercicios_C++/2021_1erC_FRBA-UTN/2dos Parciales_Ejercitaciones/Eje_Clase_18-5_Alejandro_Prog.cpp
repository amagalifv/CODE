#include <iostream>
using namespace std;

#define M 10
#define N 50

typedef struct {
    string nombre;
    int cantidadDeHoras;
} ST_CURSO;

typedef struct {
    int dni;
    string nombre;
    int edad;
    string email;
    string telefono;
    int curso;
} ST_ALUMNE;

void cargarCursos (ST_CURSO cursos[], int dimensionM){
    
    for (int i = 0; i < dimensionM-1; i++) {
        cout<<"Ingrese el nombre del curso"<<endl;
        cin>>cursos[i].nombre;
    
        cout<<"Ingrese la cantidad de horas del curso"<<endl;
        cin>>cursos[i].cantidadDeHoras;
    }
    return;
}

void cargarAlumnos (ST_ALUMNE alumnos[], int dimensionN){
    
    for (int i = 0; i <dimensionN; i++) {
        cout<<"Ingrese el nombre del alumno"<<endl;
        cin>>alumnos[i].nombre;

        cout<<"Ingrese el dni del alumno"<<endl;
        cin>>alumnos[i].dni;
    
        cout<<"Ingrese la edad del alumno"<<endl;
        cin>>alumnos[i].edad;

        cout<<"Ingrese el email del alumno"<<endl;
        cin>>alumnos[i].email;

        cout<<"Ingrese el telefono del alumno"<<endl;
        cin>>alumnos[i].telefono;

        cout<<"Ingrese el codigo de curso al que se inscribe el alumno"<<endl;
        cin>>alumnos[i].curso;
    }
    return;
}

void ordenarDni (ST_ALUMNE alumnos[], int dimensionN){
    int j;
    int aux;
    int i=0;
    bool ordenado = false;

    while (i < dimensionN && !ordenado){
        ordenado= true;

        for (int j = 0; j < dimensionN-i-1 ; j++){
            
            if (alumnos[j].dni > alumnos[j+1].dni){
                
                aux = alumnos[j].dni;
                alumnos[j]=alumnos[j+1];
                alumnos[j+1].dni=aux;
                ordenado = false;
            }
        }
        i++;
    }
    return;
}

int busquedaBinaria (ST_ALUMNE alumnos[], int dimensionN, int x) {
    int inicio=0;
    int fin = dimensionN-1;

    while(fin >= inicio){
        int mitad =inicio + (fin - inicio)/2;

        if (alumnos[mitad].dni==x){
            return mitad;
        }

        if (alumnos[mitad].dni>x){
            fin=mitad - 1;
         }else{
            inicio=mitad+1;
         } 
    }
    return -1;
}

void imprimirX (ST_ALUMNE alumnos[], ST_CURSO cursos[], int x) {
    int cursoDeX;

    if (x > -1){
        cout<<"-------------------INFORMACION DE DNI "<<x<<"-------------------"<<endl;
        cout<<"Nombre: "<<alumnos[x].nombre<<endl;
        cout<<"Edad: "<<alumnos[x].edad<<endl;
        cout<<"Email: "<<alumnos[x].email<<endl;
        cout<<"Telefono: "<<alumnos[x].telefono<<endl;
        cout<<"Curso: "<<alumnos[x].curso<<endl;
        cursoDeX=alumnos[x].curso;
        cout<<"Nombre del Curso: "<<cursos[cursoDeX].nombre<<endl;
        cout<<"Cantidad de horas del Curso: "<<cursos[cursoDeX].cantidadDeHoras<<endl;
    }

    return;
}

void apareoVectores (ST_ALUMNE alumnos[], ST_ALUMNE alumnosBis[N], int dimensionN, ST_ALUMNE aluAmbosTurnos[], int &dimensionT) {
    int i = 0;
    int j = 0;

    while (i < dimensionN && j < dimensionN) {

        if (alumnos[i].curso < alumnosBis[j].curso) {

            aluAmbosTurnos[dimensionT] = alumnos[i];
            i++;
            
        } else {
            aluAmbosTurnos[dimensionT] = alumnosBis[j];
            j++;
        }

        dimensionT++;
    }

    while(i < dimensionN) {
        aluAmbosTurnos[dimensionT] = alumnos[i];
        i++;
        dimensionT++;
    }

    while(j < dimensionN) {
        aluAmbosTurnos[dimensionT] = alumnosBis[j];
        j++;
        dimensionT++;
    }

    return;
}

void corteControl (ST_ALUMNE aluAmbosTurnos[], int dimensionT, ST_CURSO cursos[]) {
    //SUPONIENDO QUE EL VECTOR ESTA ORDENADO

    int i = 0;
    int contadorAlu = 0;
    int contadorEdad = 0;
    int key;
    int contadorTotalAlu=0;

    while(i < dimensionT) {

        key = aluAmbosTurnos[i].curso;
        cout<<"CURSO: "<<cursos[key].nombre<<endl;
        contadorAlu=0;

        while(i < dimensionT && key == aluAmbosTurnos[i].curso) {

            cout<<aluAmbosTurnos[i].nombre<<"\t\t"<<aluAmbosTurnos[i].edad<<"\t\t"<<aluAmbosTurnos[i].email<<"\t\t"<<aluAmbosTurnos[i].telefono<<endl;
            i++;
            contadorAlu++;
            contadorEdad++;
        }

        cout <<"Total de alumnos del curso: "<<contadorAlu<< endl;
        contadorTotalAlu+=contadorAlu;
        float promedioEdades=0;
        promedioEdades=contadorEdad/contadorAlu;
        cout<<"Promedio de edad del curso: "<<promedioEdades<<endl;
    }
    return;
}

int main () {
    ST_CURSO cursos[M];
    ST_ALUMNE alumnos[N];
    ST_ALUMNE alumnosBis[N];
    ST_ALUMNE aluAmbosTurnos[N+N];
    int dimensionM;
    int dimensionN;
    int dimensionT;
    int x;


    //---A---
    cargarCursos(cursos, dimensionM);
    //---B---
    cargarAlumnos(alumnos, dimensionN);
    //---C---
    //ordeno x dni el vector de alumnos
    ordenarDni(alumnos, dimensionN);
    // pido el dni a buscar y lo busco con BINARIA 
    cout<<"Ingrese el DNI a buscar"<<endl;
    cin>>x;
    busquedaBinaria(alumnos, dimensionN, x);

    //---D---
    // hago el  apareo de los dos turnos ordenados x curso
    apareoVectores(alumnos, alumnosBis, dimensionN, aluAmbosTurnos, dimensionT);
    // hago un corte de control para las impresiones
    corteControl(aluAmbosTurnos, dimensionT, cursos);
 
    system("pause");
    return 0;
}