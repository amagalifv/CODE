#ifndef TEMPORIZADOR_H
#define TEMPORIZADOR_H


class Temporizador
{
    public:
        Temporizador();// constructor
        Temporizador(int hs, int minu, int segu);
        void mostrar();
        void setTipo(int tipo);
        void tic();
        int comparar(Temporizador uno, Temporizador otro);
    private:
        int consolidarHora(Temporizador a);
        int _horas;
        int _min;
        int _seg;
        bool _tipo;
};

#endif // TEMPORIZADOR_H
