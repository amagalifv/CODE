#include <iostream>
#include "SFML/Graphics.hpp"
#include "Packman.h"

//https://www.sfml-dev.org/tutorials/2.5/window-events.php
//https://www.youtube.com/watch?v=k1jIxFWT6yI

int main(){

    //INICIALIZACION
    sf::RenderWindow window(sf::VideoMode(640, 400), "SFML works!");
    window.setFramerateLimit(60);//60 fotogramas por seg

    //sf::CircleShape shape(50.f);
    //shape.setFillColor(sf::Color::Yellow);
    Packman pac;

    // GAME LOOP
    while (window.isOpen()){

        // CMD, event listing o reading input (de la ventana)
        sf::Event event;

        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }

        }
         pac.cmd();

        // UPDATE
        //shape.move(0.1f, 0.f); //SE MUEVE  HACIA LA DERECHA
       pac.update();


        //DRAW o render
        window.clear(sf::Color::Magenta);//pinta de magenta el fondo

        //window.draw(shape);
        window.draw(pac.getDraw());

        window.display();// para que se muestre en la pantalla
    }

    // LIBERACION
    //en SFML está todo encapsulado y no necesito ocuparme yo de los destructores ya que está programado

    return 0;
}
