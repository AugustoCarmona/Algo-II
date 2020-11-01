#include <stdio.h>
#include <stdbool.h>

int raiz(int dato, int inicio, int fin);

int main(int argc, char const *argv[]) {
    int dato = 10;

    ("\n\nLa raíz cuadrada del número introducido es: %i\n", raiz(dato, 0, dato));
    return 0;
}

int raiz(int dato, int inicio, int fin) {

    int mitad = (inicio + fin) / 2;
    int cuadrado = mitad * mitad;

    if ( cuadrado <= dato && (mitad+1)*(mitad+1) > dato ) // O(1)
        return mitad;
    
    if (cuadrado < dato) { // T(n/2)
        raiz(dato, inicio, mitad);
    }
    raiz(dato, mitad, fin); // T(n/2)
}

// no corre perro