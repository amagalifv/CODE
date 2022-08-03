#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

class Fecha{
    private:
        int _dia, _mes, _anio;
    public:
        void Cargar();
        void Mostrar();

        // GETTERS
        int getDia();
        int getMes();
        int getAnio();

        // SETTERS
        void setDia();
        void setMes();
        void setAnio();
};

class Restaurante{
    private:
        int _codigoRestaurante;
        char _nombre[30];
        int _provincia;
        char _nombreGerente[30];//categoria
        int _tipoRestaurante;
        bool _estado;
    public:
        bool leerDeDisco(int pos);
        bool grabarEnDisco();
        void Cargar();
        void Mostrar();

        // GETTERS
        int getCodigoRestaurante();
        const char *getNombre();
        int getProvincia();
        const char *getNombreGerente();
        int getTipoRestaurante();
        bool getEstado();

        // SETTERS
        void setCodigoRestaurante();
        void setNombre();
        void setProvincia();
        void setNombreGerente();
        void setTipoRestaurante();
        void setEstado();
};

class Cliente{
   private:
        int _DNI;
        char _nombre [30];
        int _medioPago, _tipoCliente, _edad;
        bool _estado;
    public:
        bool leerDeDisco(int pos);
        bool grabarEnDisco();
        void Cargar();
        void Mostrar();

        // GETTERS
        int getDni();
        const char *getNombre();
        int getMedioPago();
        int getTipoCliente();
        int getEdad();
        bool getEstado();

        // SETTERS
        void setDni();
        const char *setNombre();
        void setMedioPago();
        void setTipoCliente();
        void setEdad();
        void setEstado();
};

class Reserva{
    private:
        int _codigoRestaurante;
        int _DNI;
        Fecha _fechaReserva;
        int _hora;
        bool _estado;

    public:
        bool leerDeDisco(int pos);
        bool grabarEnDisco();
        void Cargar();
        void Mostrar();

        // GETTERS
        int getCodigoRestaurante();
        int getDNI();
        Fecha getFechaReserva();
        int getHora();
        bool getEstado();

        // SETTERS
        void setCodigoRestaurante();
        void setDNI();
        void setFechaReserva();
        void setHora();
        void setEstado();
};




#endif // FUNCIONES_H_INCLUDED
