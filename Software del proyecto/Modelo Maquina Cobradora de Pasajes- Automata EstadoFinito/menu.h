#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "tablaTransiciones.h"
#define  T int
class Menu{
       private:
           void interfazUsuario(TablaTransiciones <T> &);
           int procesoAutomata(TablaTransiciones <T> &, std::string &);

        public:
           void definirTablaTransiciones();
};


#endif // MENU_H_INCLUDED
