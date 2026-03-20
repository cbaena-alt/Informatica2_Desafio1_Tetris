#ifndef PIEZAS_H
#define PIEZAS_H

class Pieza {
public:
    unsigned short forma;
    int x, y;

public:
    Pieza();
    void caer();
    void rotar();
    void moverIzquierda();
    void moverDerecha();
    void obtenerPieza(int tipo);
    void dibujar();
};

#endif // PIEZAS_H