#include "tporo.h"
#include <string.h>
#include <new>

/// WARIIGN
/// TODAS LA VARIABLES DEBEN DE SER INICIALIZADAS CON LOS CONTRUCTORES
/// MUCHO CUIDADO

//CONSTRUCTORES
TPoro::TPoro():x(0), y(0), volumen(0), color(NULL){    
}

TPoro::TPoro(int x1, int y1, double volumen1):x(x1), y(y1), volumen(volumen1), color(NULL){    
}

//FUNCIONA SI EL PUNTERO QUE PASAMOS APUNTA A LA PRIMERA POSICION DE UNA CADENA
TPoro::TPoro(int x1, int y1, double volumen1, const char *color1):x(x1), y(y1), volumen(volumen1), color(NULL){
    //NO REPÎTAS CODIGO

    this->Color(color1);
}

TPoro::TPoro(TPoro const &p):x(p.x), y(p.y), volumen(p.volumen), color(NULL){

    //if(color != NULL){
    //     strcpy(this->color, p.color);
    //}
    this->Color(p.color);
}

TPoro::~TPoro(){
    if(color != NULL){
        delete[] this->color; 
    }
    this->color = NULL; 
    this->volumen = 0;
    this->x = 0;
    this->y = 0;

}

///////////
//METODOS//
///////////

TPoro& TPoro::operator=(const TPoro &p){
    this->~TPoro();
    if(this != &p){
        x = p.x;
        y = p.y;
        volumen = p.volumen;
        //strcpy(this->color, p.color); 
        this->Color(p.color);
    }

    return *this;
}

//SETTERS           
void TPoro::Posicion(int x1, int y1){
    x = x1;
    y = y1;
}

void TPoro::Volumen(double v){
    volumen = v;
}

//Modifica puntero, ¿tamaño?, Comprobar null excepciónes
void TPoro::Color(const char * c){

    if(this->color != NULL){
        delete[] this->color;
        this->color = NULL;
    }

    if(c != NULL){
        int clen = strlen(c);
        this->color = new char[clen+1];

        if(this->color == NULL){
            std::cout<<"Error al reservar memoria"<<std::endl;
        }else{

            //char aux[clen+1]="";

            for(int i=0;i<clen;i++){
                this->color[i] = (char)tolower(c[i]);
            }

            //strcpy(this->color, aux);
            this->color[clen] = '\0';
        }
    }
}

//GETTERS
int TPoro::PosicionX()const{
    return x;
}

int TPoro::PosicionY()const{
    return y;
}

double TPoro::Volumen()const{
    return volumen;
}



//Funciona pide un puntero si intentas imprimirlo es tu problema
char * TPoro::Color()const{
    //IDK 
    return color;
}

//SOBRECARGA DE OPERADORES
bool TPoro::operator==(const TPoro &p){

    /*  if((strcmp(color, p.color) == 0) && (volumen == p.volumen) && (y == p.y) && (x == p.x)){
        return true;
    }else{
        return false;
    }*/
    if((color == NULL && p.color != NULL) || (color != NULL && p.color == NULL)){
        return false;
    }/*else if(color == NULL && p.color == NULL){
        return ((volumen == p.volumen) && (y == p.y) && (x == p.x));
    }*/
    if(color != NULL && p.color != NULL){
        if(strcmp(color, p.color) != 0){
            return false;
        }
    }
    //RETURN BOOLEAN NO HACE FALTA IF.
    return ((volumen == p.volumen) && (y == p.y) && (x == p.x));

}
//This es un puntero

bool TPoro::operator!=(const TPoro &p){

    return !(*this == p);

}

bool TPoro::EsVacio()const
{
    return ((x == 0) && (y == 0) && (volumen == 0) && (color == NULL));
}

std::ostream & operator<<(std::ostream &os, const TPoro &poro){

    if(!poro.EsVacio()){
        os.setf(std::ios::fixed);
        os.precision ( 2 );
        os<<"("<<poro.x<<", "<<poro.y<<") "<<poro.volumen<<" ";

        if(poro.color != NULL){
            os<<poro.color;
        }else{
            os<<"-";

            return os;
        }
    }else{
        os<<"()";
        return os;
    }
    return os;
}
