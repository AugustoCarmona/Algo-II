#include <stdio.h>
#include <stdbool.h>

int buscar(int arr[], size_t inicio, size_t final) {
    if (inicio > final) return -1; // son todos unos
    
    size_t mitad = (inicio+final)/2;
    
    if (!arr[mitad] && (!mitad || arr[mitad-1])) // si estamos sobre el primer cero con un uno a la izquierda
        return mitad;

    if (!arr[mitad])
        buscar(arr, inicio, mitad-1);
    buscar(arr, mitad+1, final);
}

int primer_cero(int arr[], size_t n) {
    buscar(arr, 0, n-1);
}

// Se tiene un arreglo tal que [1, 1, 1, …, 0, 0, …] (es decir, unos seguidos de ceros).
// Se pide una función de orden O(log(n)) que encuentre el índice del primer 0. Si no hay ningún 0 (solo hay unos), debe devolver -1.


/*
Siendo n la cantidad de elementos, utilizando el teorema maestro:
A = 1 Solo hago la llamada recursiva en una de las mitades
B = 2 Divido en dos el arreglo
C = 0 Todas las operaciones internas son del orden O(1)
log b (a) = 0 = C => O(log(n))
*/

// Teorema Maestro:
// O(n/2)+O(1) -> a=1, b=2, c=0 -> logb(a) = 0 = c -> O(log(n))