/**
 * Dynamic vector data structure header.
 * Author: Jonathan Santos Castro.
 * GitHub: https://github.com/MaeseJohn
*/

#ifndef _TPORO_H_
#define _TPORO_H_
#include <iostream>




class TPoro{


    private:
        //Coordenada x de la posición
        int x;
        //Coordenada y de la posición
        int y;
        //Volumen
        double volumen;
        //Color
        char* color;

    public:
        //CONSTRUCTORES
        //Constructor por defecto
        TPoro();
        //Contructor a partir de una posición y un volumen
        TPoro(int, int, double);
        //Contructor a partir de una posició, un volumen y un color
        TPoro(int, int, double, const char *);
        //Constructor copia
        TPoro(TPoro const &);
        //Destructor
        ~TPoro();
        //Sobrecarga del operador asignacion
        TPoro & operator=(const TPoro &);

        //METODOS
        //Sobrecarga del operador igualdad
        bool operator==(const TPoro &);
        //Sobrecarga del operador desigualdad
        bool operator!=(const TPoro&);
        //Modifica la posicion
        void Posicion(int, int);
        //Modifica el volumnen
        void Volumen(double);
        //Modifica el color
        void Color(const char *);
        //Devuelve la coordenada x de la posición
        int PosicionX()const;
        //Devuelve la coordenada y de la posicion
        int PosicionY()const;
        //Devuelve el volumen
        double Volumen()const;
        //Devuelve el color
        char * Color()const;
        //Devuelve cierto si el poro está vacio
        bool EsVacio()const;

        //FUNCIONES AMIGAS
        //Sobrecarga del operador SALIDA
        friend std::ostream & operator<<(std::ostream &, const TPoro &);

};
#endif


    


