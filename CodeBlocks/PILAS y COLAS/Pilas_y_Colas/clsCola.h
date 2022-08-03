#ifndef CLSCOLA_H_INCLUDED
#define CLSCOLA_H_INCLUDED

/*
la puedo llenar 1 vez y  solo acepta la
cantidad declarada en el main
Si se vacia uno no acepta otro!!!
*/

class Cola {
    private:
        int *_pCola;
        int _tam, _ppio, _fin;
    public:
        Cola(int tam){
            _tam=tam;
            _pCola= new int[tam];
            if (_pCola==NULL) {exit (1);}
            _ppio=_fin=0;
        }
        bool Agregar (int valor){
            if(_tam== _fin){return false;}
            _pCola[_fin]=valor;
            _fin++;
            return true;
        }
        bool Sacar( int &valor){
            if(_ppio==_fin){return false;}
            valor=_pCola[_ppio];
            _ppio++;
            return true;
        }
        ~Cola(){delete _pCola;}

};

#endif // CLSCOLA_H_INCLUDED
