#include "tablero.h"
//pedimos la memoria

 Tablero::Tablero(int f, int c) {
    filas = f;
    columnas = c;
    malla = new unsigned char*[filas];
    for (int i = 0; i < filas; i++) {
        malla[i] = new unsigned char[columnas];
        for (int j = 0; j < columnas; j++) {
            malla[i][j] = 0;
        }
     }
 }

 //Devolvemos la memoria
 Tablero ::~Tablero (){
     for (int i = 0; i< filas; i++){
         delete[] malla [i];
     }
     delete [] malla;
 }

 //muestra el tablero en consola
 void Tablero:: mostrar() {
     for (int i = 0; i< filas; i++){
         for(int j=0; j< columnas; j++ ){
             std::cout<<(int)malla[i][j]<<" ";
         }
         std::cout <<std::endl;
     }
 }

 // revisa si la posición es valida y esta vacia
 bool Tablero :: validarEspacio (int f, int c){
     //si se sale de los bordes
     if (f >= filas or c < 0 or c >= columnas){
         return false;
     }
     // Si la celda ya está ocupada
     if (malla[f][c] != 0) {
         return false;
     }
     return true;
 }

 //pinta el valor en el tablero
 void Tablero :: colocarPieza(int f, int c, int valor){
     if (f >= 0 and f < filas and c < columnas){
         malla [f][c] = (unsigned char)valor;
     }
 }

 //comprueba si hay una fila llena
 bool Tablero :: filaLlena(int f){
     for (int j = 0; j<= columnas; j++){
         if (malla [f][j] == 0){
             return false;
         }
     }
     return true;
 }
