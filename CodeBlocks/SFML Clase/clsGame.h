#ifndef CLSGAME_H_INCLUDED
#define CLSGAME_H_INCLUDED

class Game{
    private:
        RenderWindow *ventana;
        Texture *fondo;
        Sprite *sFondo;
        Player *jugador;
        int puntaje;
    public:
        Game();
        ~Game();
        void controller();
        void gameloop();

};

Game::Game(){
    ventana = new RenderWindow(VideoMode(1200, 600), "SFML laboratorio 2");
    jugador = new Player;
    fondo = new Texture;
    fondo->loadFromFile("Imagenes/fondo.jpg");
    sFondo = new Sprite(*fondo);
    puntaje=0;
}

Game::~Game(){
    delete ventana;
    delete jugador;
    delete fondo;
    delete sFondo;
}

void Game::gameloop(){
    while(ventana->isOpen()){
        controller();
        jugador->update();
        ventana->clear();
        ventana->draw(*sFondo);
        ventana->draw(jugador->getSprite());
        ventana->display();

    }
}

void Game::controller(){
    Event event;
    while (ventana->pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed){
            if(event.key.code == sf::Keyboard::Escape){
                ventana->close();
            }
        }
    }
}

#endif // CLSGAME_H_INCLUDED
