class Pieza {
private:

    unsigned short forma;
    int x, y;

public:

    Pieza();
    void rotar();
    void moverIzquierda();
    void moverDerecha();
    void obtenerPieza(int tipo);
    void dibujar();
};

