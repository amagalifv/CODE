#ifndef CLSPILA_H_INCLUDED
#define CLSPILA_H_INCLUDED

class Pila {
    private:
        int *_pPila;
        int _tam, _tope;
    public:
        Pila(int tam){
            _tam=tam;
            _pPila= new int[tam];
            if (_pPila==NULL) {exit (1);}
            _tope=0;
        }
        bool Agregar (int valor){
            if(_tam==_tope){return false;}
            _pPila[_tope]=valor;
            _tope++;
            return true;
        }
        bool Sacar( int &valor){
            if(_tope==0){return false;}
            _tope--;
            valor=_pPila[_tope];
            return true;
        }
        ~Pila(){delete _pPila;}

};

#endif // CLSPILA_H_INCLUDED
