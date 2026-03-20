#include <iostream>
#include "tablero.h"
#include "piezas.h"
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    Tablero miTablero(15, 15);
    Pieza miPieza;

    // Inicializamos la primera pieza
    miPieza.obtenerPieza(3);
    miPieza.x = 5;
    miPieza.y = 0;
    char accion = ' ';

    while (accion != 'q' && accion != 'Q') {
        // 1. LIMPIAR PANTALLA
        system("cls");

        // 2. "PINTAR" LA PIEZA EN LA MATRIZ ANTES DE MOSTRARLA

        for (int f = 0; f < 4; f++) {
            for (int c = 0; c < 4; c++) {

                if (miPieza.forma & (1 << (f * 4 + c))) {

                    miTablero.colocarPieza(miPieza.y + f, miPieza.x + c, 1);
                }
            }
        }

        // 3. MOSTRAR EL TABLERO (Ahora sí tiene el '1' adentro)
        cout << "--- TETRIS INTERACTIVO ---" << endl;
        miTablero.mostrar(); //

        // 4. LIMPIAR EL RASTRO (Para que la pieza no se quede pegada al moverla)
        for (int f = 0; f < 4; f++) {
            for (int c = 0; c < 4; c++) {
                if (miPieza.forma & (1 << (f * 4 + c))) {
                    miTablero.colocarPieza(miPieza.y + f, miPieza.x + c, 0);
                }
            }
        }

        // 5. PEDIR ACCIÓN
        cout << "\nAccion: [A]Izq [D]Der [S]Bajar [W]Rotar [Q]Salir: ";
        cin >> accion;

        // 6. LÓGICA DE MOVIMIENTO Y COLISIÓN
        switch(accion) {
        case 'a': case 'A':
            if (miTablero.validarEspacio(miPieza.y, miPieza.x - 1)) miPieza.moverIzquierda();
            break;
        case 'd': case 'D':
            if (miTablero.validarEspacio(miPieza.y, miPieza.x + 1)) miPieza.moverDerecha();
            break;
        case 'w': case 'W':
            miPieza.rotar();
            break;
        case 's': case 'S': {
            // Revisar colisión abajo
            bool puedeBajar = true;
            for (int f = 0; f < 4; f++) {
                for (int c = 0; c < 4; c++) {
                    if (miPieza.forma & (1 << (f * 4 + c))) {
                        if (!miTablero.validarEspacio(miPieza.y + f + 1, miPieza.x + c)) {
                            puedeBajar = false;
                        }
                    }
                }
            }

            if (puedeBajar) {
                miPieza.caer(); //
            } else {
                // FIJAR PIEZA: Si no puede bajar, se queda en el tablero
                for (int f = 0; f < 4; f++) {
                    for (int c = 0; c < 4; c++) {
                        if (miPieza.forma & (1 << (f * 4 + c))) {
                            miTablero.colocarPieza(miPieza.y + f, miPieza.x + c, 1);
                        }
                    }
                }
                miTablero.LimpiarLineas(); //

                // NUEVA PIEZA
                miPieza.y = 0;
                miPieza.x = 5;
                miPieza.obtenerPieza(rand() % 7 + 1);
            }
            break;
        }
        }
    }
    return 0;
}