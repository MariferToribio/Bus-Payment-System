#include <iostream>
#include <string>

#include "menu.h"
#include "tablaTransiciones.h"

#define T int

using namespace std;

void Menu::definirTablaTransiciones(){
    TablaTransiciones <int> tabla_f;

    tabla_f.agregarTransicion(0, 0, 1);
    tabla_f.agregarTransicion(0, 1, 2);
    tabla_f.agregarTransicion(0, 2, 5);
    tabla_f.agregarTransicion(0, 3, 10);

    tabla_f.agregarTransicion(1, 0, 2);
    tabla_f.agregarTransicion(1, 1, 3);
    tabla_f.agregarTransicion(1, 2, 6);
    tabla_f.agregarTransicion(1, 3, 11);

    tabla_f.agregarTransicion(2, 0, 3);
    tabla_f.agregarTransicion(2, 1, 4);
    tabla_f.agregarTransicion(2, 2, 7);
    tabla_f.agregarTransicion(2, 3, 11);

    tabla_f.agregarTransicion(3, 0, 4);
    tabla_f.agregarTransicion(3, 1, 5);
    tabla_f.agregarTransicion(3, 2, 8);
    tabla_f.agregarTransicion(3, 3, 11);

    tabla_f.agregarTransicion(4, 0, 5);
    tabla_f.agregarTransicion(4, 1, 6);
    tabla_f.agregarTransicion(4, 2, 9);
    tabla_f.agregarTransicion(4, 3, 11);

    tabla_f.agregarTransicion(5, 0, 6);
    tabla_f.agregarTransicion(5, 1, 7);
    tabla_f.agregarTransicion(5, 2, 10);
    tabla_f.agregarTransicion(5, 3, 11);

    tabla_f.agregarTransicion(6, 0, 7);
    tabla_f.agregarTransicion(6, 1, 8);
    tabla_f.agregarTransicion(6, 2, 11);
    tabla_f.agregarTransicion(6, 3, 11);

    tabla_f.agregarTransicion(7, 0, 8);
    tabla_f.agregarTransicion(7, 1, 9);
    tabla_f.agregarTransicion(7, 2, 11);
    tabla_f.agregarTransicion(7, 3, 11);

    tabla_f.agregarTransicion(8, 0, 9);
    tabla_f.agregarTransicion(8, 1, 10);
    tabla_f.agregarTransicion(8, 2, 11);
    tabla_f.agregarTransicion(8, 3, 11);

    tabla_f.agregarTransicion(9, 0, 10);
    tabla_f.agregarTransicion(9, 1, 11);
    tabla_f.agregarTransicion(9, 2, 11);
    tabla_f.agregarTransicion(9, 3, 11);

    tabla_f.agregarTransicion(10, 0, 11);
    tabla_f.agregarTransicion(10, 1, 11);
    tabla_f.agregarTransicion(10, 2, 11);
    tabla_f.agregarTransicion(10, 3, 11);

    tabla_f.agregarTransicion(11, 0, 11);
    tabla_f.agregarTransicion(11, 1, 11);
    tabla_f.agregarTransicion(11, 2, 11);
    tabla_f.agregarTransicion(11, 3, 11);

    interfazUsuario(tabla_f);
}

void Menu::interfazUsuario(TablaTransiciones <T> &tabla_f){
        int ingresarDinero;

        do{
           system("cls");
           string monedas;
           int estado(-1);
           cout << "\n\n                ******* C O B R O  D E  P A S A J E  D E  T R A N S P O R T E  P U B L I C O *******" << endl;
           for (int i = 0; i < 120; i++){
                cout << char(177);
           }

           cout << endl << endl;
           cout << "                                 ESTA MAQUINA SOLO RECIBE MONEDAS EN PESO MEXICANO " << endl;
           cout << "                                    DEPOSITE PASAJE EXACTO, NO DEVUELVE CAMBIO" << endl;
           cout << "\t\t      ***********************************************************************" << endl;
           cout << "\t\t      *           COSTO DE PASAJE: " << char(36) << " 11.00                                  *" << endl;
           cout << "\t\t      *           MONEDAS ACEPTADAS" << "                                         *" << endl;
           cout << "\t\t      *                " << char(36) << " 1.00                                               *" << endl;
           cout << "\t\t      *                " << char(36) << " 2.00                                               *" << endl;
           cout << "\t\t      *                " << char(36) << " 5.00                                               *" << endl;
           cout << "\t\t      *                " << char(36) << " 10.00                                              *" << endl;
           cout << "\t\t      ***********************************************************************"  << endl << endl;
           cout << "\t\t      Nota: Ingrese monedas con un espacio para separar cada una " << endl;
           cout << "\t\t      Deposite monedas: "; fflush(stdin); getline(cin, monedas);

           try {
                estado = procesoAutomata(tabla_f, monedas);
           } catch (const out_of_range& e) {
                cerr << "\t\t        -- DINERO NO ACEPTADO -- " << endl;
                cerr << "\t\t          < " << e.what() << " > " << endl;
           }

           if (estado == 11){
                cout << "\t\t        -- DINERO ACEPTADO -- " << endl;
                cout << "\t\t           ADELANTE, ERES BIENVENIDO!!" << endl;
           }

           else if (estado != 11 and estado != -1) {
                cout << "\t\t        -- DINERO INSUFICIENTE --" << endl;
                cout << "\t\t          < El costo del pasaje es " << char(36) << " 11.00 >" << endl;
           }

           cout << "\n\n\t\t      Presione '1' para ingresar dinero para pagar pasaje: "; cin >> ingresarDinero;
        }while (ingresarDinero == 1);
}

int Menu::procesoAutomata(TablaTransiciones <T>&tabla_f, string &monedas){
    int estado(0), entrada(0);
    char simbolo;

    do{
        for (int i = 0; i < monedas.size(); i++){
            if (monedas[i] != ' ' and monedas[i] != '0'){
                if (monedas[i] == '1'){
                        if (monedas[i+1] == '0'){ ///SE INGRESO MONEDA DE 10
                                simbolo = '7';
                        }

                        else { ///NO FUE MONEDA DE 10, FUE DE 1
                                simbolo = '1';
                        }
                }

                else if (monedas[i] != '1'){///SE INGRESO OTRA MONEDA QUE NO ES DE 1 NI DE 10
                        simbolo = monedas[i];
                }

                switch(simbolo){
                case '1': ///MONEDA DE 1
                    entrada = 0;
                    break;
                case '2':///MONEDA DE 2
                    entrada = 1;
                    break;
                case '5':///MONEDA DE 5
                    entrada = 2;
                    break;
                case '7':///MONEDA DE 10
                    entrada = 3;
                    break;
                default: throw out_of_range("Ingresaste tipo de dinero que no acepta esta maquina cobradora");
                }

                estado = tabla_f.obtenerSiguienteEstado(estado, entrada);

               if (monedas[i+1] != '0' and monedas[i+1] != ' ' and i != monedas.size()-1){
                     throw out_of_range("Ingresaste tipo de dinero que no acepta esta maquina cobradora");
               }
            }

            if (i == monedas.size()-1 and estado != 11){
                  return estado;
            }

            if (estado == 11){
                return estado;
            }
        }
    } while (estado != 11);

    return estado;
}
