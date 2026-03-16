#ifndef PIEZAS_H
#define PIEZAS_H

class Pieza {
public:
    unsigned short forma; // Usamos 16 bits para una rejilla de 4x4
    int x, y;            // Posición en el tablero

    Pieza();
    void cargarCuadrado();   // Pieza O
    void cargarLinea();      // Pieza I
    void moverDerecha();     // Usará >>
    void moverIzquierda();   // Usará <<
    void rotar();            // El reto de bits
};

#endif