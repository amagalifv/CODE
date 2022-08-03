#ifndef PACKMAN_H_INCLUDED
#define PACKMAN_H_INCLUDED

#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

/*
La forma de llamar a los métodos de esa clase seria con _shape.nombreMetodo()

Si si, pero vos la propiedad la usas adentro de la clase (por el encapsulamiento, no podes acceder a las
propiedades desde fuera)
Asi que cuando tengas que trabajar con la propiedad del tipo shape, vas a trabajar mediante los métodos
De la clase shape
Entonces adentro de un método de pacman que necesite modificar la propiedad shape vas a llamar a los
métodos de shape usando _shape.Metodo()

No es muy complicado, cuando arranquemos con los proyectos finales en lab2 les voy a mostrar un
 ejemplo sencillito que hice que trabaja con texturas y sprites

Fijate también que podes usar texture y Sprite en personajes que no son figuras geométricas

*/

enum ESTADOS{
SUBE
BAJA
DER
IZQ
QUIETO
};

class Packman {

    private:
        sf::CircleShape _shape;

    public:
        Packman();
        void cmd();
        void update();
        sf::CircleShape& getDraw();// circle sprite para imagenes
};

//CONTRUCTOR
Packman::Packman(){
    _shape.setFillColor(sf::Color::Yellow);
    _shape.setRadius(50.f);
    _shape.setPosition(10,10);
}

void Packman::cmd(){

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){

        }
/*
    if (sf::Event::KeyPressed::isKeyPressed){


                if(event.key.code==sf::Keyboard::Down){
                shape.move(0.f, 9.f);
                }
                if(event.key.code==sf::Keyboard::Up){
                 shape.move(0.f, -9.f);
                }
                if(event.key.code==sf::Keyboard::Left){
                 shape.move(-9.f, 0.f);
                }
                if(event.key.code==sf::Keyboard::Right){
                 shape.move(9.f, 0.f);
                }
    }
*/
}

void Packman::update(){
}

sf::CircleShape& Packman::getDraw(){
        return _shape;
}

#endif // PACKMAN_H_INCLUDED
