#include <stdio.h>
#include <stdbool.h>

int ordenado(int arr[], size_t ini, size_t fin) {

    if (ini == fin || ini == fin-1) {
        if (arr[ini] > arr [fin]) {
            return arr[ini];
        }
        else {
            return NULL;
        }
    }

    size_t mitad = (ini+fin)/2;
    int izquierda = ordenado(arr, ini, mitad);
    int derecha = ordenado(arr, mitad, fin);

    return (!izquierda) ?  derecha : izquierda;
}

int elemento_desordenado(int arr[], size_t n) {
    ordenado(arr, 0, n-1);
}

int main() {
    int arr[] = {1,2,3,4,9,5,6,7}; // debe devolver 9
    size_t largo = sizeof(arr)/sizeof(int);
    printf("Elemento desordenado: %d\n", elemento_desordenado(arr, largo));

    return 0;
}

/*
 Implementar, por división y conquista, una función que dado un arreglo sin elementos repetidos y casi ordenado (todos los elementos se encuentran ordenados,salvo uno), obtenga el elemento fuera de lugar. Indicar y justificar  el orden.
*/