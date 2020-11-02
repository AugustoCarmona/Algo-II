#include <stddef.h> 
#include "invertir_arreglo.h"

void invertir_arreglo(void** arreglo, size_t n) {
    pila_t* pila = pila_crear();

    for (size_t i = 0; i < n; i++)
        pila_apilar(pila, arreglo[i]);

    size_t i = 0;
    while (!pila_esta_vacia(pila)) {
        arreglo[i] = pila_desapilar(pila);
        i++;
    }
}

// Implementar una función que reciba un arreglo de void* e invierta su orden, utilizando los TDAs vistos.
// Indicar y justificar el orden de ejecución.

// Básicamente tengo que apilar los elementos de la función.

/*
 La función consta de un ciclo for y un ciclo while, pero al estos no estar anidados se trata de una complejidad lineal O(n)
*/