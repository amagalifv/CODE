#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
# include<iostream>
# include<cstdlib>
# include<cstring>
using namespace std;

class Cliente{
private:
    int DNI;
    Fecha fechaNacimiento;
    char nombre[25], apellido[25];
    char email[30];
    char telefono[15];
    bool estado;///true el registro est� activo; si est� el false el registro est� borrado y debe ser ignorado por el sistema
public:
    ///Un constructor con valores por omisi�n para los par�metros.
    Cliente(int d=0, const char *n="vacio", const char *a="vacio",
            const char *e="vacio", const char *t="vacio"  ){
        DNI=d;
        strcpy(nombre, n);
        strcpy(apellido, a);
        strcpy(email, e);
        strcpy(telefono, t);
    }
    void Cargar(int );
    void Mostrar();
    ///gets() para todas las propiedades
    int getDNI(){return DNI;}
    const char *getNombre(){return nombre;}
    const char *getApellido(){return apellido;}
    const char *getEmail(){return email;}
    const char *getTelefono(){return telefono;}
    bool getEstado(){return estado;}

    Fecha getFechanacimiento(){return fechaNacimiento;}
    ///sets() para todas las propiedades
    void setDNI(int d){DNI=d;}
    void setNombre(const char *par){strcpy(nombre, par);}
    void setApellido(const char *par){strcpy(apellido, par);}
    void setEmail(const char *par){strcpy(email, par);}
    void setTelefono(const char *par){strcpy(telefono,par);}
    void setEstado(bool e){estado=e;}

    int grabarEnDisco();
    int leerDeDisco(int pos);

};

int Cliente::grabarEnDisco(){
    FILE *p;
    int escribio;
    p=fopen("clientes.dat", "ab");
    if(p==NULL)return -1;
    escribio=fwrite(this, sizeof(Cliente) ,1, p);
    fclose(p);
    return escribio;
}

int Cliente::leerDeDisco(int pos){
    FILE *p;
    int leyo=0;
    p=fopen("clientes.dat", "rb");
    if(p==NULL)return -1;
    fseek(p, sizeof(Cliente)*pos, 0);
    leyo=fread(this, sizeof(Cliente) ,1, p);
    fclose(p);
    return leyo;


}

void Cliente::Mostrar(){
    //if(estado==true){
        cout<<"DNI: ";
        cout<<DNI<<endl;
        cout<<"NOMBRE: ";
        cout<<nombre<<endl;
        cout<<"APELLIDO: ";
        cout<<apellido<<endl;
        cout<<"EMAIL: ";
        cout<<email<<endl;
        cout<<"TELEFONO: ";
        cout<<telefono<<endl;
        cout<<"FECHA DE NACIMIENTO: ";
        fechaNacimiento.Mostrar();
    //}
}


void Cliente::Cargar(int d=0){
    estado=true;
    if(d!=0){
        DNI=d;
    }
    else{
        cout<<"DNI: ";
        cin>>DNI;
    }
    cout<<"NOMBRE: ";
    cin>>nombre;
    cout<<"APELLIDO: ";
    cin>>apellido;
    cout<<"EMAIL: ";
    cin>>email;
    cout<<"TELEFONO: ";
    cin>>telefono;
    cout<<"FECHA DE NACIMIENTO: ";
    fechaNacimiento.Cargar();
}

#endif // CLIENTE_H_INCLUDED
