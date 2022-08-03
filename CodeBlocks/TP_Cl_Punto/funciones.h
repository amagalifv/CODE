#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <windows.h>
#include <cstring>

enum Color{
cNEGRO=0,
cAZUL=1,
cVERDE=2,
cCIAN=3,
cROJO=4,
cMAGENTA=5,
cMARRON=6,
cGRIS_CLARO=7,
cGRIS=8,
cAZUL_CLARO=9,
cVERDE_CLARO=10,
cCIAN_CLARO=11,
cROJO_CLARO=12,
cMAGENTA_CLARO=13,
cAMARILLO=14,
cBLANCO=15
};

void gotoxy(short x, short y){
    COORD a;
    a.X = x;
    a.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);
}

void textcolor(short colorTexto=15, short colorFondo=0){
    short color = colorTexto + colorFondo * 16;
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), color);
}

class Punto{
private:
    char _cPunto;
public:
    Punto(char caracter);
    void dibPunto(short x, short y);
    void dibLineaHoriz(short x, short y, int longitud);
    void dibLineaVertical(short x);
    void dibLineaHorizColor(short y);
    void dibLineaVerticalColor(short x);
    void dibDosLineaCentroH(short y);
    void dibDosLineaCentroV(short x);
    void dibPuntoParpadeante(short x, short y);
    void dibRectangulo(short x, short y, short ancho, short alto);
    void dibPuntoCaminanteH(short x, short y);
    void dibPuntoCaminanteV(short x, short y);
    void dibLluviaAleatoria(short x, short y);
    void dibLluviaAleatoriaEscape(short x, short y);
};

//CONTRUCTOR
Punto::Punto(char caracter){
    _cPunto=caracter;
}

// dibuja punto en coordenadas (x,y)
void Punto::dibPunto (short x, short y){
    gotoxy(x,y);
    cout<<_cPunto<<endl;
}

// dibuja linea
// parametros: coordenadas (x,y) + cantidad de caracteres de la línea.
void Punto::dibLineaHoriz(short x, short y, int longitud){
    gotoxy(x,y);

    for (int i=0; i<longitud; i++) {
        cout<<_cPunto;
    }
    cout<<endl;
}

void Punto::dibRectangulo (short x, short y, short ancho, short alto){
    int i, j;
    for(i=x; i<=x+ancho; i++){
        for(j=y; j<=y+alto; j++){
            gotoxy(i, j);

            //Arriba izquierda
            if(i==x && j==y){
                cout <<_cPunto;
            }
            //Arriba derecha
            else if(i==x+ancho && j==y){
                cout <<_cPunto;
            }
            //Abajo izquierda
            else if(i==x && j==y+alto){
                cout <<_cPunto;
            }
            //Abajo derecha
            else if(i==x+ancho && j==y+alto){
                cout <<_cPunto;
            }
            //Lineas arriba y abajo
            else if(j==y || j==y+alto){
                cout <<_cPunto;
            }
            //Lineas izquierda y derecha
            else if(i==x || i==x+ancho){
                cout <<_cPunto;
            }
            //Dentro del recuadro
            else{
                cout << " ";
            }
        }
    }
    cout<<endl;
}


#endif // FUNCIONES_H_INCLUDED
