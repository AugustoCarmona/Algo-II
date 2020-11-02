#include <stdio.h>
#include <stdbool.h>

bool arreglo_es_magico(int arr[], size_t n) {
        
    size_t mitad, inicio = 0;
    bool es_magico = false;

    while ( (inicio < n) && (!es_magico) ) {
        mitad = (inicio + n) / 2;
        size_t valor = arr[mitad];
    
        if (valor == mitad) return es_magico = true;
        if (valor > mitad) n = mitad;
        else if (valor < mitad) inicio = mitad;
    } return es_magico;
}

int main() {
    int arreglo[] = {1,2,4,6,7,9};
    size_t largo = sizeof(arreglo)/sizeof(int);
    
    printf( (arreglo_es_magico(arreglo, largo)) ? "\nEl arreglo es mágico\n\n" : "\nEl arreglo no es mágico\n\n");
    
    return 0;
}

// El algoritmo recibe un arreglo de enteros de tamaño n, ordenado ascendentemente y sin elementos repetidos.
// Debe determinar en O(log n) si el arreglo es mágico.
// Un arreglo es mágico cuando exíste algún valor i tal que 0 <= i y arreglo[i] = i
// Se puede decir que 0 es mayor que el número que estamo evaluando y el arreglo evaluado en dicho número es ese mismo valor.

// { -3, 0, 1, 3, 7, 9 } --> es mágico por que A[3] = 3
// { 1, 2, 4, 6, 7, 9 } --> no es mágico por que B[i] != i para todo i.

/*
 Se me pide una complejidadad de O(log n) por lo que debo recurrir a la búsqueda binaria
 
 Función de recurrencia => T(n) = T(n/2) + O(1) 
 
 Siendo:
 A = 1 Cantidad de veces que se llama la función recursiva.
 B = 2 Cantidad de partes en las que si divide el arreglo.
 C = 0 Todas las demas funciones son constantes complejidad O(1).
 
 Por teorema maestro
 logB (A) = log2 (1) = 0 = C => O(n^c log n) => O(n^0 log n) => O(log n)
*/
