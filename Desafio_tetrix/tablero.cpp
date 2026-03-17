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

 void Tablero:: mostrar() {
     for (int i = 0; i< filas; i++){
         for(int j=0; j< columnas; j++ ){
             std::cout<<(int)malla[i][j]<<" ";
         }
         std::cout <<std::endl;
     }
 }

