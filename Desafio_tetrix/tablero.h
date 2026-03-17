#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
class Tablero {
private:
    int filas;
    int columnas;
    unsigned char** malla;

public:
    Tablero(int f = 20, int c = 10);
    ~Tablero();

    void mostrar();

};
#endif // TABLERO_H
