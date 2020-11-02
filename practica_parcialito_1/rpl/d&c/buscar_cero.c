#include <stdio.h>
#include <stdbool.h>

int buscar(int arr[], size_t i, size_t f) {
    if (i > f) return -1;
    size_t mitad = (i+f)/2;
    if (!arr[mitad] && (!mitad || arr[mitad-1])) return mitad;
    return (!arr[mitad]) ? buscar(arr, i, mitad-1) : buscar(arr, mitad+1, f);
}

int primer_cero(int arr[], size_t n) {
    buscar(arr, 0, n-1);
}

// me hago el canchero, pero en realidad d&c me esta haciendo parir


/*
Siendo n la cantidad de elementos, utilizando el teorema maestro:
A = 1
B = 2 
C = 0
log b (a) = 0 = C => O(log(n))
*/

// Teo Maestro:
// O(n/2)+O(1) -> a=1, b=2, c=0 -> logb(a) = 0 = c -> O(log(n))

/*
Se tiene un arreglo tal que [1, 1, 1, …, 0, 0, …] (es decir, unos seguidos de ceros). Se pide una función de orden O(log(n)) que encuentre el índice del primer 0. Si no hay ningún 0 (solo hay unos), debe devolver -1.
*/