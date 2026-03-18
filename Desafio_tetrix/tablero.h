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
    bool validarEspacio (int f, int c);
    void colocarPieza (int f, int c, int valor);
    bool filaLlena (int f);

};
#endif // TABLERO_H
