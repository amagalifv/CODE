#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class Articulo{
    private:
        char codigo[5];
        char descripcion[30];
        float precio;
        int stock;
        bool estado;
    public:
        Articulo(const char *c="AAAA", const char *d="Sin descripcion", float p=0, int s=0, bool e=false){
            strcpy(codigo, c);
            strcpy(descripcion, d);
            precio=p;
            stock=s;
            estado=e;
        }
        void Cargar();
        void Mostrar();

        void setCodigo(const char *c){strcpy(codigo, c);}
        void setDescripcion(const char *d){strcpy(descripcion, d);}
        void setPrecio(float p){precio=p;}
        void setStock(int s){if(s>=0)stock=s;}
        void setEstado(bool e){estado=e;}

        const char *getCodigo(){return codigo;}
        const char *getDescripcion(){return descripcion;}
        float getPrecio(){return precio;}
        int getStock(){return stock;}
        bool getEstado(){return estado;}
};

void Articulo::Cargar(){
    char c[5], d[30];
    float p;
    int s;
    cout<<"INGRESE EL CODIGO: ";
    cargarCadena(c, 4);
    setCodigo(c);
    cout<<"INGRESE LA DESCRIPCION: ";
    cargarCadena(d, 29);
    setDescripcion(d);
    cout<<"INGRESE EL PRECIO: ";
    cin>>p;
    setPrecio(p);
    cout<<"INGRESE EL STOCK: ";
    cin>>s;
    setStock(s);
    estado=true;
}
void Articulo::Mostrar(){
    cout<<"CODIGO: ";
    cout<<codigo<<endl;
    cout<<"DESCRIPCION: ";
    cout<<descripcion<<endl;
    cout<<"PRECIO: ";
    cout<<precio<<endl;
    cout<<"STOCK: ";
    cout<<stock<<endl;
}
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
void listarArticulos (Articulo v[], int tam){

        for (Articulo e : v){
            e.Cargar();
        }

}

int main () {




    system("pause");
    return 0;
}