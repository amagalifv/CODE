#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;
#include <windows.h>


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

void clrscr(void){
    system("cls");
}

void pause(void){
    system("pause >nul");
}

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

void recuadro(short iniX, short iniY, short ancho, short alto, short colorLinea=cBLANCO, short colorFondo=cNEGRO){
    int i, j;
    for(i=iniX; i<=iniX+ancho; i++){
        for(j=iniY; j<=iniY+alto; j++){
            gotoxy(i, j);
            textcolor(colorLinea, colorFondo);
            //Arriba izquierda
            if(i==iniX && j==iniY){
                cout << (char) 218;
            }
            //Arriba derecha
            else if(i==iniX+ancho && j==iniY){
                cout << (char) 191;
            }
            //Abajo izquierda
            else if(i==iniX && j==iniY+alto){
                cout << (char) 192;
            }
            //Abajo derecha
            else if(i==iniX+ancho && j==iniY+alto){
                cout << (char) 217;
            }
            //Lineas arriba y abajo
            else if(j==iniY || j==iniY+alto){
                cout << (char) 45;
            }
            //Lineas izquierda y derecha
            else if(i==iniX || i==iniX+ancho){
                cout << (char) 221;
            }

            //Dentro del recuadro
            else{
                cout << " ";
            }
        }
    }
}

void dado(short iniX, short iniY, short ancho, short alto, short colorLinea=cBLANCO, short colorFondo=cNEGRO){
    int i, j;
    for(i=iniX; i<=iniX+ancho; i++){
        for(j=iniY; j<=iniY+alto; j++){
            gotoxy(i, j);
            textcolor(colorLinea, colorFondo);
            //Arriba izquierda
            if(i==iniX && j==iniY){
                cout << (char) 218;
            }
            //Arriba derecha
            else if(i==iniX+ancho && j==iniY){
                cout << (char) 191;
            }
            //Abajo izquierda
            else if(i==iniX && j==iniY+alto){
                cout << (char) 192;
            }
            //Abajo derecha
            else if(i==iniX+ancho && j==iniY+alto){
                cout << (char) 217;
            }
            //Lineas arriba y abajo
            else if(j==iniY || j==iniY+alto){
                cout << (char) 196;
            }
            //Lineas izquierda y derecha
            else if(i==iniX || i==iniX+ancho){
                cout << (char) 179;
            }
            //Dentro del recuadro
            else{
                cout << " ";
            }
        }
    }
}

int main () {

    system ("color 57");

    /*
    recuadro(24, 6, 50, 14, cBLANCO, cMAGENTA);
    gotoxy(43,8);cout<<"RONDA Nro ";
    gotoxy(38,10);cout<<"PROXIMO TURNO: PEPE"<<endl;
    gotoxy(26,13);cout<<"------------------------------------------------";
    gotoxy(40,15);cout<<"PUNTAJE 20 PUNTOS";
    gotoxy(37,17);cout<<"CANTIDAD DE TIRADAS: 000";

    dado(6,1,8,4,cBLANCO, cMAGENTA);
    gotoxy(8,2);printf("●\n");
    gotoxy(10,3);printf("●\n");
    gotoxy(12,4);printf("●\n");
    */

    UINT WINAPI GetConsoleOutputCP(void);
    cout<<GetConsoleOutputCP();

    //gotoxy(8,2);cout<<(char)111;gotoxy(12,2);cout<<(char)111;
    //gotoxy(8,3);cout<<(char)111;gotoxy(10,3);cout<<(char)111;gotoxy(12,3);cout<<(char)111;
    //gotoxy(8,4);cout<<(char)111;gotoxy(12,4);cout<<(char)111;



    pause();
    return 0;
}
/*
// C++ program for the coloring the
// background and text with
// different color
//#include <iostream>

// Header file to change color of
// text and background
//#include <windows.h>
//using namespace std;

// Driver Code
int main()
{
    // Color of the console
    HANDLE console_color;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_color, P);

    // Print different colors from 1
    // to 50 on the output screen
    for (int P = 1; P < 50; P++) {

        // P is color code of the
        // corresponding color
        SetConsoleTextAttribute(
            console_color, P);

        // Print Statement
        cout << P << " Hello Geeks, "
             << "good night!!!";
    }

    return 0;
}
*/