# include<iostream>
# include<cstdlib>
# include<cstring>
using namespace std;

#include "Funcs_y_Cls.h"

const char *AR_ULTIMOSCONCURSOS = "ultimosconcursos.dat";

void cargarCadena(char *pal, int tam){
  int i;
  fflush(stdin);
  for(i=0;i<tam;i++){
      pal[i]=cin.get();
	  if(pal[i]=='\n') break;
	  }
  pal[i]='\0';
  fflush(stdin);
}

class UltimoConcurso {
    private:
        int DNI;
        char nombre[50], apellido[50];
        int numeroConcurso;

    public:
        int getDNI(){return DNI;}
        const char *getNombre(){return nombre;}
        const char *getApellido(){return apellido;}
        int getNumeroConcurso(){return numeroConcurso;}

        void setDNI(int d){DNI=d;}
        void setNombre(const char *nom){strcpy(nombre,nom);}
        void setApellido(const char *ape){strcpy(apellido, ape);}
        void setNumeroConcurso(int c){numeroConcurso=c;}

        void Mostrar();
        void Cargar();
        bool leerDeDisco(int i);
        bool grabarEnDisco();

        void operator= (Docente d){
            setDNI(d.getDNI());
            setNombre(d.getNombre());
            setApellido(d.getApellido());
        }
};

void UltimoConcurso::Cargar(){
    int aux;
    char texto[50];

    cout<<"--------------------------------------"<<endl;
    cout<<"INGRESE EL DNI                 :";
    cin>>aux;
    setDNI(aux);

    cout<<"INGRESE EL APELLIDO            :";
    cargarCadena(texto, 20);
    setApellido(texto);

    cout<<"INGRESE EL NOMBRE              :";
    cargarCadena(texto, 20);
    setNombre(texto);

    cout<<"INGRESE EL NUMERO CONCURSO     :";
    cin>>aux;
    setNumeroConcurso(aux);
    cout<<"--------------------------------------"<<endl;
}

void UltimoConcurso::Mostrar(){
    cout<<"--------------------------------------"<<endl;
    cout<<"DNI                 :";
    cout<<getDNI()<<endl;
    cout<<"APELLIDO            :";
    cout<<getApellido()<<endl;
    cout<<"NOMBRE              :";
    cout<<getNombre()<<endl;
    cout<<"NUMERO CONCURSO     :";
    getNumeroConcurso();
    cout<<"--------------------------------------"<<endl;
}


bool UltimoConcurso::leerDeDisco(int pos){
    FILE *pCon;
    int leyo;

    pCon=fopen(AR_ULTIMOSCONCURSOS,"rb");
    if (pCon==NULL){return -1;}

    fseek(pCon, sizeof(UltimoConcurso)*pos,SEEK_SET);
    leyo=fread(this ,sizeof(UltimoConcurso),1,pCon);
    fclose(pCon);

    return leyo;
}

bool UltimoConcurso::grabarEnDisco(){
    FILE *pCon;
    bool escribio;

    pCon=fopen(AR_ULTIMOSCONCURSOS,"ab");
    if (pCon==NULL){return false;}

    escribio=fwrite(this ,sizeof(UltimoConcurso),1,pCon);
    fclose(pCon);
    return escribio;
}

/*
a) Generar un archivo nuevo con los concursos realizados en los últimos 5 años
Cada registro del archivo debe tener el siguiente formato:
- Número de concurso, DNI, el nombre y apellido del docente (3 puntos)
*/


/*
2) Agregar una sobrecarga de un operador para alguna de las clases del ejercicio 1 que sea útil para el desarrollo de alguno de los puntos que se piden (2 puntos)

sale: 10, 11, 12, 13, 14, 14, 13, 12, 11, 10 !!!
*/

int buscarConcurso(int dni){
    Concurso con;
    int i=0;

    while (con.leerDeDisco(i)) {
        if(con.getDNI()==dni) {return con.getNumeroConcurso();}
        i++;
    }

    return 0;
}

bool generarArchivo(){
    Docente doc;
    UltimoConcurso ConcU;
    int i=0;
    int aux;
    bool band;

    while (doc.leerDeDisco(i)) {
        if (2017<doc.getAnioIngreso() && doc.getAnioIngreso()<=2022) {
            aux=buscarConcurso(doc.getDNI());
            if (aux>0) {
                ConcU=doc;
                ConcU.setNumeroConcurso(aux);

                band=ConcU.grabarEnDisco();
                if (band==false) return false;
            }
        }

        i++;
    }
    return true;
}


/*
b)  Informar cuál es la categoría en la que ingresaron mayor cantidad de docentes en el año 2015. (3 puntos).

Desarrollar todas las clases que se consideren necesarias para la resolución del ejercicio. No es obligatorio codificar de manera completa los métodos; se considera suficiente que se coloquen los prototipos dentro de las clases.
*/
void PuntoB(){
    Docente doc;
    int i=0;
    int v[7]={0};
    int max;
    int iMax;


    while (doc.leerDeDisco(i)) {
        if (doc.getAnioIngreso()==2015) {
            v[doc.getCategoria()-1]++;
        }
        i++;
    }

    max=v[0];
    iMax=0;
    for (int j=1; j<7; j++) {
        if (v[j]>max) {
            max=v[j];
            iMax=j;
        }
    }
    cout<<"En la categoria que ingresaron más docentes en el 2015 es: "<<iMax+1<<endl;
}

int main(){
    bool bandera;
    //PUNTO 1 A
    bandera=generarArchivo();
    if (bandera) {cout<<"Archivo creado con exito\n";}
    else {cout<<"Error en creación de Archivo\n";}

    //PUNTO 1 B
    PuntoB();

    system("pause");
    return 0;
}
