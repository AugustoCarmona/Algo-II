#include <stdio.h>
#include <stdbool.h>

size_t posicion_pico(int v[], size_t ini, size_t fin) {
    size_t mitad = (ini + fin) / 2;

    if ((v[mitad] > v[mitad-1]) && (v[mitad] > v[mitad+1])) //caso base (pico)
        return mitad;

    if ((v[mitad] > v[mitad-1]) && (v[mitad] < v[mitad+1])) // (in crescendo)
        posicion_pico(v, mitad+1, fin);
    posicion_pico(v, ini, mitad-1);
}

int main(int argc, char const *argv[]) {
    int arr[] = {-5,-1,1,2,3,1,0,-2};
    size_t fin = sizeof(arr)/sizeof(int);
    printf("la posicion del pico es: %ld\n", posicion_pico(arr, 0, fin));
    
    return 0;
}

// Caso base: si el arreglo evaluado[posición de la mitad] es mayor al arreglo[una posición antes] y también es mayor al
// arreglo[una posicion depués], entonces esa es la posición del pico.
// Si el arreglo evaluado[posición de la mitad] es mayor al arreglo[una posición antes] pero es menor al arreglo[una posicion depués],
// entonces el pico se encuentra en la mitad derecha.
// En cualquier otro caso el pico se va a encontrar en la mitad izquierda. Siempre debe haber un pico.


// Se tiene un arreglo de N >= 3 elementos en foma de pico, esto es: estrictamente creciente hasta una determinada posición p, y estrictamente decreciente
// a partir de ella (con 0 < p < N - 1).
 
// Por ejemplo, en el arreglo [1,2,3,1,0,-2] la posición del pico es p = 2.
 
// Se pide: implementar un algoritmo de división y conquista de orden O(log(n)) que encuentre la posición
// del pico: size_t posicion size_t posicion_pico(int v[], size_t ini, size_t fin);.
 
// La función será invocada inicialmente como posicion_pico(v, 0, n-1), y tiene como pre-condición que el arreglo tenga forma de pico.

/*
Teorema Maestro

T(n) = 1*T(n/2) + O(1) -> A = 1, B = 2, C = 0

-> log_B(A) = log_2(1) = 0 = C -> T(n) = O(n^0*log(n) = O(log(n))
*/