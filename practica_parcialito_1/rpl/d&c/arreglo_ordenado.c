#include <stdio.h>
#include <stdbool.h>

bool ordenado(int arr[], size_t ini, size_t fin) {
    
    if (fin-ini < 2) return (arr[ini] < arr[fin]) ? true : false; // en caso de quedar dos elementos, si el de la izquierda es menor, devuelve true
    
    size_t mitad = (ini+fin)/2; // si el arreglo es de más de dos elementos, forzamos la partición
    bool izquierda = ordenado(arr, ini, mitad);
    bool derecha = ordenado(arr, mitad, fin); // 2 T(n/2)
    
    return izquierda && derecha;
}

bool arreglo_ordenado(int arr[], size_t n) {
    if (!n || n == 1) return true;
    ordenado(arr, 0, n);
}

int main() {
    int arr[] = {1,2,3,4,5,6,7};
    size_t largo = sizeof(arr)/sizeof(int);
    printf (arreglo_ordenado(arr, largo) ? "El arreglo está ordenado\n" : "El arreglo no está ordenado\n");

    return 0;
}

// Implementar por división y conquista una función que determine si un arrego está ordenado.
// El caso base no es que el arreglo sea de un elemento, si no de dos.

/*
T(n) = 2 T(n/2) +O(1)

A = 2
B = 2
C = 0
logB (A) > C => O(n ^ logB (A)) => O(n ^ 1) => O(n)

o... log_2(2) = 1 > C  -> T(n) = O(n^log_2(2)) = O(n)
*/