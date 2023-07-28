#ifndef TABLATRANSICIONES_H_INCLUDED
#define TABLATRANSICIONES_H_INCLUDED

template <class T, int ESTADOS = 11, int SIMBOLOS = 4>
class TablaTransiciones{
         private:
            T tabla_f[ESTADOS][SIMBOLOS];

         public:
            void agregarTransicion(const int &, const int &, const T &);
            T obtenerSiguienteEstado(const int &, const int &);

};

template <class T, int ESTADOS, int SIMBOLOS>
T TablaTransiciones <T, ESTADOS, SIMBOLOS>::obtenerSiguienteEstado(const int &estado, const int &entrada){
        return tabla_f[estado][entrada];
}

template <class T, int ESTADOS, int SIMBOLOS>
void TablaTransiciones <T, ESTADOS, SIMBOLOS>::agregarTransicion(const int &estado, const int &entrada, const T &estadoSiguiente){
        tabla_f[estado][entrada] = estadoSiguiente;
}

#endif // TABLATRANSICIONES_H_INCLUDED
