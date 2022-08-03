# include<iostream>
# include<cstdlib>
# include<cstring>
using namespace std;

const char *AR_PRODMAQ = "produ_maq.dat";
const char *AR_ENVASES = "envases.dat";
const char *AR_PRODUCCION = "produccion.dat";

int  contarRegistros();
bool copiarArchivo(Envase*, int cantregistros);

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
        void Cargar();
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

class Envase{

    private:
        int IDenvase;
        char nombre[50];
        int color; //(1 a 7)
        int stock;
        int tamanio;// (1 a 5)

    public:
        int getId() {return IDenvase;}
        const char *getNombre() {return nombre;}
        int getColor() {return color;}
        int getStock() {return stock;}
        int getTamanio() {return tamanio;}

        void setId (int id) {IDenvase=id;}
        void setNombre (const char *n){strcpy(nombre, n);}
        void getColor(int c) {color=c;}
        void getStock(int s) {stock=s;}
        void getTamanio(int t) {tamanio=t;}

        void Mostrar();
        void Cargar();
        bool leerDeDisco(int);
        bool grabarEnDisco();
};

class Produccion{

    private:
        int IDenvase;
        Fecha fecha;
        int nroMaq; //(1 a 50)
        int cantidadProd;

    public:
        int getId () {return IDenvase;}
        Fecha getFecha() {return fecha;}
        int setNroMaq () {return nroMaq;}
        int getCantidadProd() {return cantidadProd;}

        void setId (int id) {IDenvase=id;}
        void setFecha (Fecha f) {fecha=f;}
        void setNroMaq (int nro) {nroMaq=nro;}
        void setCantidadProd (int c) {cantidadProd=c;}

        void Mostrar();
        void Cargar();
        bool leerDeDisco(int);
        bool grabarEnDisco();
};

class ProduMaq {

    private:
        int id;
        char nombre[50];
        int cantidadProd;

    public:

        int getId() {return id;}
        const char *getNombre() {return nombre;}
        int getCantidadProd() {return cantidadProd;}


        void setId (int ide) {id=ide;}
        void setNombre (const char *n){strcpy(nombre, n);}
        void setCantidadProd (int c) {cantidadProd=c;}

        void Mostrar();
        void Cargar();
        bool leerDeDisco(int);
        bool grabarEnDisco();

        void operator= (Envase env){
            setId(env.getId());
            setNombre(env.getNombre());
        }

        bool operator<(int d){
            if (getId()<d) {
                return true;
            }
            return false;
        }

};

bool ProduMaq::leerDeDisco(int pos){
    FILE *pCls;
    int leyo;

    pCls=fopen(AR_PRODMAQ,"rb");
    if (pCls==NULL){return -1;}

    fseek(pCls, sizeof(ProduMaq)*pos,SEEK_SET);
    leyo=fread(this ,sizeof(ProduMaq),1,pCls);
    fclose(pCls);

    return leyo;
}

bool ProduMaq::grabarEnDisco(){
    FILE *pCls;
    bool escribio;

    pCls=fopen(AR_PRODMAQ,"ab");
    if (pCls==NULL){return false;}

    escribio=fwrite(this ,sizeof(ProduMaq),1,pCls);
    fclose(pCls);
    return escribio;
}

/*
a) Generar un archivo nuevo (produ_maq.dat) con la producción de las envases de tamaño 3. Cada registro del archivo debe tener el siguiente formato:
- ID, nombre del envase y cantidad producia. (3 puntos)
*/
void generarArchivo (){
    Envase env;
    Produccion produ;
    ProduMaq proM;
    int i=0;
    int j=0;
    int aux=0;

    while (env.leerDeDisco(i)) {

        if (env.getTamanio()==3) {

            while (produ.leerDeDisco(j)) {
                if (env.getId()==produ.getId()) {
                    aux+=produ.getCantidadProd();
                }
                j++;
            }

            proM=env; // sobrecarga de operador =
            proM.setCantidadProd(aux);

            proM.grabarEnDisco(); //aca grabo en archivo

            j=0;
            aux=0;
        }

        i++;
    }

}

/*
b) Informar los colores con más de 100 envases distintos (cantidad de envases distintos no cantidad de envases producidos)
*/
void contarColores(){
    Envase env;
    int i=0;
    int vColor[7]={0};

    while (env.leerDeDisco(i)) {

        vColor[env.getColor()-1]++;

        i++;
    }

    for (int j=0; j<7; j++) {

        if (vColor[j]>100) {
            cout<<"El color "<<j+1<<" tiene "<<vColor[j]<<" envases distintos"<<endl;
        }
    }
}
/*
3) Hacer un programa que genere de manera dinámica un vector para copiar entero el archivo envases del ejercicio 1. Suponer que existe una función de nombre int  contarRegistros(), que devuelve la cantidad de registros del archivo, y otra que copia el archivo en el vector ( bool copiarArchivo(envase*, int cantregistros)).
Hacer una función que muestre el vector.
*/
bool imprimirVectorDinamico(){
    Envase *env;
    int tam;
    bool bandera;

    tam=contarRegistros();
    env=new Envase[tam];
    bandera=copiarArchivo(env, tam);

    if (bandera==false) {
        return false;
    }

    for (int i=0; i<tam; i++) {
        env[i].Mostrar();
    }

    return true;
}


int main(){
     bool bandera;

    // PUNTO 1 A:
    generarArchivo ();

    // PUNTO 1 B:
    contarColores();

    // PUNTO 3:
    bandera=imprimirVectorDinamico();
    if (bandera==true) {
        cout<<"Operacion Exitosa"<<endl;
    } else {
        cout<<"Error!"<<endl;
    }

    system("pause");
    return 0;
}
