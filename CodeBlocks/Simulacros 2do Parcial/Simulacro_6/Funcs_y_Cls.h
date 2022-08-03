#ifndef FUNCS_Y_CLS_H_INCLUDED
#define FUNCS_Y_CLS_H_INCLUDED
# include<iostream>
# include<cstdlib>
# include<cstring>
# include<ctime>
using namespace std;

bool validarFecha(int d, int m, int a, bool siAnioFutu);

class Fecha {
    private:
        int _dia, _mes, _anio;
    public:
        Fecha(int dia=0, int mes=0, int anio=0){
            _dia=dia;
            _mes=mes;
            _anio=anio;
        }
        void Mostrar();
        void Cargar(bool siAnioFuturo);
        ///gets()
        int getDia(){return _dia;}
        int getMes(){return _mes;}
        int getAnio(){return _anio;}
        ///sets()
        void setDia(int d){if(d>=1 && d<=31){ _dia=d;}else{_dia=0;_mes=0;_anio=0;}}
        void setMes(int m){if(m>=1 && m<=12){ _mes=m;}else{_dia=0;_mes=0;_anio=0;}}
        void setAnio(int a){if(a>=1920){_anio=a;}else{_dia=0;_mes=0;_anio=0;}}
        bool operator== (Fecha f){
            if (f.getDia()==_dia && f.getMes()==_mes && f.getAnio()==_anio){return true;}
            return false;
        }
};

void Fecha::Mostrar(){
    if (getDia()<10){
        cout<<"0"<<getDia();
    }else{
        cout<<getDia();
    }
    cout<<"/";
    if (getMes()<10){
        cout<<"0"<<getMes();
    }else{
        cout<<getMes();
    }
    cout<<"/"<<getAnio()<<endl;
}

void Fecha::Cargar(bool siAnioFuturo=false){
    int dia, mes, anio;

    cout<<"INGRESE EL DIA:             ";
    cin>>dia;

    cout<<"INGRESE EL MES:             ";
    cin>>mes;

    cout<<"INGRESE EL AÑO (4 digitos): ";
    cin>>anio;


    while(!validarFecha(dia, mes, anio, siAnioFuturo)){
        cout<<"\nFECHA INCORRECTA, intentelo nuevamente\n";

        cout<<"INGRESE EL DIA:             ";
        cin>>dia;

        cout<<"INGRESE EL MES:             ";
        cin>>mes;

        cout<<"INGRESE EL AÑO (4 digitos): ";
        cin>>anio;
    }
    setDia(dia);setMes(mes);setAnio(anio);

}

bool validarFecha(int d, int m, int a, bool siAnioFutu){
    bool bandera=true;
    int v[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int anioActual;

    //chequear dia segun mes
    if(d>=v[m-1]){
        if (d==29 && m==2 && a%4==0) {
            //chequear febrero y año bisiesto
            if (a%100==0 && a%400!=0){bandera=false;}
            else{ bandera=true;}
        }else{bandera=false;}
    }

    //chequear mes
    if (m<1 || m>12){bandera=false;}

    if (siAnioFutu==true) {
        //chequear año
        time_t fechaActual;
        time(&fechaActual);
        struct tm *pST_tiempo = localtime(&fechaActual);
        anioActual=pST_tiempo->tm_year+1900;
        if (a<1920 || a>anioActual) {bandera=false;}
    }else{if (a<1920){bandera=false;}}

    return bandera;
}

void devuelveFechaActualSistema(Fecha *f){
    time_t fechaActual;
    time(&fechaActual);
    struct tm *pST_tiempo = localtime(&fechaActual);
    f->setAnio(pST_tiempo->tm_year+1900);
    f->setMes(pST_tiempo->tm_mon+1);
    f->setDia(pST_tiempo->tm_mday);
}


class Docente{
    private:
        int DNI;
        char nombre[50], apellido[50];
        int provincia; //(entero entre 1 y 24),
        int categoria; //(1 a 7)
        int especialidad; //(1 a 50)
        int anioIngreso;
    public:
        int getDNI(){return DNI;}
        const char *getNombre(){return nombre;}
        const char *getApellido(){return apellido;}
        int getProvincia(){return provincia;}
        int getCategoria(){return categoria;}
        int getEspecialidad(){return especialidad;}
        int getAnioIngreso(){return anioIngreso;}

        void setDNI(int d){DNI=d;}
        void setNombre(const char *nom){strcpy(nombre,nom);}
        void setApellido(const char *ape){strcpy(apellido, ape);}
        void setProvincia(int p){provincia=p;}
        void setCategoria(int c){categoria=c;}
        void setEspecialidad(int e){especialidad=e;}
        void setAnioIngreso(int a){anioIngreso=a;}

        void Mostrar();
        void Cargar();
        bool leerDeDisco(int i);
        bool grabarEnDisco();
};

class Concurso {
    private:
        int dniDocente;
        Fecha fecha;
        int numeroUniversidad; // (1 a 80),
        int numeroConcurso;
        int tipoCargoAconcursar; //(1: titular; 2: adjunto; 3: jefe de trabajos prácticos; 4: ayudante).

    public:

        int getDNI(){return dniDocente;}
        int getNumeroUniversidad(){return numeroUniversidad;}
        int getNumeroConcurso(){return numeroConcurso;}
        int getTipoCargoAconcursar(){return tipoCargoAconcursar;}
        Fecha getFecha(){return fecha;}

        void setDNI(int d){dniDocente=d;}
        void setNumeroUniversidad(int u){numeroUniversidad=u;}
        void setNumeroConcurso(int c){numeroConcurso=c;}
        void setTipoCargoAconcursar(int ac){tipoCargoAconcursar=ac;}
        void setFecha(Fecha f){fecha=f;}

        void Mostrar();
        void Cargar();
        bool leerDeDisco(int i);
        bool grabarEnDisco();
};
/*
1) El área de estadística de la Secretaría de Políticas Universitarias tiene, entre otros, los siguientes archivos en su sistema:

docentes.dat:
DNI (int),
nombre y apellido (char[50]),
provincia (entero entre 1 y 24),
categoría (1 a 7)
especialidad(1 a 50),
año de ingreso.

concursos.dat:
DNI del docente (int),
fecha (día, mes y año),
número de universidad (1 a 80),
número de concurso,
tipo de cargo a concursar (1: titular; 2: adjunto; 3: jefe de trabajos prácticos; 4: ayudante).

El archivo tiene los concursos de los docentes desde el año 2000 a la fecha.
Se pide:
a) Generar un archivo nuevo con los concursos realizados en los últimos 5 años . Cada registro del archivo debe tener el siguiente formato:
- Número de concurso, DNI, el nombre y apellido del docente (3 puntos)
b)  Informar cuál es la categoría en la que ingresaron mayor cantidad de docentes en el año 2015. (3 puntos).

Desarrollar todas las clases que se consideren necesarias para la resolución del ejercicio. No es obligatorio codificar de manera completa los métodos; se considera suficiente que se coloquen los prototipos dentro de las clases.

2) Agregar una sobrecarga de un operador para alguna de las clases del ejercicio 1 que sea útil para el desarrollo de alguno de los puntos que se piden (2 puntos)

3) Suponiendo que a es una Cola de números enteros, y que b es una Pila de enteros,
informar que se obtiene en la salida de pantalla del siguiente programa

int main(){
	Cola a(5);
	Pila b(5);
	int i, x;
	for(i=10;i<15;i++) b.Agregar(i);
for(i=10;i<15;i++) a.Agregar(i);
	for(i=10;i<15;i++) {
		a.Sacar(x);
		cout<<"SALE: "<<x<<endl;
	}
	for(i=10;i<15;i++) {
		b.Sacar(x);
		cout<<"SALE: "<<x<<endl;
	}
	return 0;
}

Nota:
El prototipo del método Sacar() en ambas clases es

bool Sacar(int &aux);
*/

#endif // FUNCS_Y_CLS_H_INCLUDED
