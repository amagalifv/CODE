#include <iostream>
using namespace std;

typedef struct{
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

void cargarCurso (ST_CURSO cursos[], int M);
void cargarAlumno(ST_ALUMNE alumnos[], int N);
void ordenarArray (int alumnos[], int N);
int busquedaBinaria (ST_ALUMNE alumnos[],int N, int DNI);
void imprimir (ST_ALUMNE alumnos[], int N);

int main () {
 int M=0;
 int N=0;
 float contProm=0;
 int contAluTotal=0;
 
 cout<<"Ingrese la cantidad de cursos";
 cin>>M;

 ST_CURSO cursos[M];

 cout<<"Ingrese la cantidad de alumnos";
 cin>>N;
 
 ST_ALUMNE alumnos[N];

 cargarCurso(cursos, M);
 cargarAlumno(alumnos, N);
 ordenarArray(alumnos, N);
 //busquedaBinaria(alumnos, N, alumnos[N].dni);

 system("pause");
 return 0;
}

void cargarCurso(ST_CURSO cursos[], int M){
 int codigoCur=0;

    for (int i =0 ; i < M -1 ; i++){
        cout<<"Ingrese la cantidad de horas del curso";
        cin>>cursos[i].cantidadDeHoras;

        cout<<"Ingrese el nombre del inscripto";
        cin>>cursos[i].nombre;
    }
    
}

void cargarAlumno(ST_ALUMNE alumnos[], int N){
    for (int i = 0; i < N ; i++){
     cout<<"Ingrese el DNI del alumno";
     cin>> alumnos[i].dni;

     cout<<"Ingrese el nombre del alumno";
     cin>> alumnos[i].nombre;

     cout<<"Ingrese la edad del alumno";
     cin>> alumnos[i].edad;

     cout<<"Ingrese el email del alumno";
     cin>> alumnos[i].email;

     cout<<"Ingrese el telefono del alumno";
     cin>> alumnos[i].telefono;

     cout<<"Ingrese el curso al que se inscribe";
     cin>> alumnos[i].curso;
 }

}

void ordenarArray (ST_ALUMNE alumnos[], int N){
 int aux = 0;

 for (int i=0 ; i<(N-1) ; i++) {

    for (int j=0 ; j<(N-1-i) ; j++) {

        if (alumnos[j+1].dni < alumnos[j].dni) {
            
            aux = alumnos[j].dni;
            alumnos[j].dni = alumnos[j+1].dni;
            alumnos[j+1].dni = aux;
        }
    }
 }
 return;
}

int busquedaBinaria (ST_ALUMNE alumnos[],int cant, int dni){
    int inicio=0;
    int fin = cant-1;

    while (fin>=inicio){
        int mitad = inicio + (fin-inicio) / 2;
        if (alumnos[mitad].dni==dni){
            return mitad;
        }
        if (alumnos[mitad].dni>dni){
            fin = mitad - 1;
        }else{
            inicio = mitad + 1;
        }
    }
    return -1;
}

void imprimir (ST_ALUMNE alumnos[], int N){
 int i = 0;
 int contadorAlu = 0;
 int contadorEdades= 0;
 int key;
 float promedio;
 float sumProm;
 int contPosProm;
 float promTotal;
 int cantTotalAlu;

 while(i < N) {

    key = alumnos[i].curso;

    contadorAlu = 0;
    contadorEdades=0;

    while(i < N && key == alumnos[i].curso) {

        contadorAlu++;
        contadorEdades+=alumnos[i].edad;

        cout << "Curso: " << key << endl;
        cout<< "Alumno    | Edad    | Email    | Telefono    "<<endl;
        cout<<alumnos[i].nombre<<" "<<alumnos[i].edad<<" "<<alumnos[i].email<<" "<<alumnos[i].telefono <<endl;

        i++; 
    }
    promedio=contadorEdades/contadorAlu;
    cout<<"El total de alumnos es: "<<contadorAlu<<endl;
    cout<<"El promedio de edades del curso es: "<<promedio<<endl;

    sumProm+=promedio;
    contPosProm++;
    cantTotalAlu+=contadorAlu;

 }
 promTotal=sumProm/contPosProm;
 cout<< "El promedio de edades general es: " << promTotal <<endl;
 cout<< "La cantidad de alumnos es: " << cantTotalAlu <<endl;

 return;
}
