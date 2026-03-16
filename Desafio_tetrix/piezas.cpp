#include "piezas.h"

Pieza::Pieza() {
    x = 0; y = 0;
    forma = 0;
}



void Pieza::moverIzquierda() {

    x--;

}

void Pieza::moverDerecha() {
    x++;
}


void Pieza::rotar() {
    unsigned short nuevaForma = 0;

    for (int fila = 0; fila < 4; fila++) {
        for (int col = 0; col < 4; col++) {

            if (forma & (1 << (fila * 4 + col))) {
                nuevaForma |= (1 << (col * 4 + (3 - fila)));
            }
        }
    }
    forma = nuevaForma;
}



void Pieza::obtenerPieza(int tipo) {
    switch(tipo) {
    case 1: forma = 0x0F00; break; // I
    case 2: forma = 0x6600; break; // O
    case 3: forma = 0x0E40; break; // T
    case 4: forma = 0x06C0; break; // S
    case 5: forma = 0x0C60; break; // Z
    case 6: forma = 0x0E20; break; // J
    case 7: forma = 0x0E80; break; // L
    default: forma = 0; break;
    }
}