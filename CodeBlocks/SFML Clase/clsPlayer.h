#ifndef CLSPLAYER_H_INCLUDED
#define CLSPLAYER_H_INCLUDED

class Player{
    private:
        Texture *textura;
        Sprite *sprite;
        int orientacion;
        float velocidad;
        bool isGrounded;
    public:
        Player();
        ~Player();
        void update();
        void mover();
        Sprite getSprite(){return *sprite;}
};

Player::Player(){
    textura=new Texture;
    orientacion=0;
    velocidad = 0.1;
    textura->loadFromFile("Imagenes/tipito.png");
    IntRect rect(0, 0, 50, 50);
    sprite=new Sprite(*textura, rect);
    sprite->setPosition(300, 300);
    //sprite->setOrigin(25,25);
}

Player::~Player(){
    delete textura;
    delete sprite;
}

void Player::update(){
    mover();
}
void Player::mover(){
    float x=0, y=0;
    int aux=-1;
    if(Keyboard::isKeyPressed(sf::Keyboard::S)){
        y=1;
        aux=4;
    }
    if(Keyboard::isKeyPressed(sf::Keyboard::W)){
        y=-1;
        aux=0;
    }
    if(Keyboard::isKeyPressed(sf::Keyboard::A)){
        x=-1;
        if(aux==0){
            aux=7;
        }else if(aux==4){
            aux=5;
        }else{
            aux=6;
        }
    }
    if(Keyboard::isKeyPressed(sf::Keyboard::D)){
        x=1;
        if(aux==0){
            aux=1;
        }else if(aux==4){
            aux=3;
        }else{
            aux=2;
        }
    }
    if(sprite->getPosition().x+x*velocidad<0 || sprite->getPosition().x+x*velocidad+50 > 1200) x=0;
    if(sprite->getPosition().y+y*velocidad<0 || sprite->getPosition().y+y*velocidad+50 > 600) y=0;
    if(x != 0 && y != 0){
        x=x/sqrt(2);
        y=y/sqrt(2);
    }
    sprite->move(x*velocidad,y*velocidad);
    if(aux!=-1){
        orientacion=aux;
    }
    //sprite->setRotation(45*orientacion);
    IntRect rect(50*orientacion,0,50,50);
    sprite->setTextureRect(rect);

}

#endif // CLSPLAYER_H_INCLUDED
