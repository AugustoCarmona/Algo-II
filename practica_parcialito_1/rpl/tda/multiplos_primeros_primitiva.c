#include "cola.h"
#include "multiplos_primeros_primitiva.h"

void** cola_multiprimeros(const cola_t* cola, size_t k) {
    
    void** elementos = calloc(k, sizeof(void)); // pide espacio para un arreglo de voids
    if (!elementos) return NULL;
    
    nodo_t* actual = cola->prim;

    for (size_t i = 0; i < k && actual; i++) {
        elementos[i] = actual->dato;
        actual = actual->sig;
    } return elementos; // no necesita llenar los elementos restantes con NULL por que ya lo hizo calloc
}

/*
Implementar la primitiva void** cola_multiprimeros(const cola_t* cola, size_t k) que dada una cola y un número k, devuelva los primeros k
elementos de la cola, en el mismo orden en el que habrían salido de la cola. En caso que la cola tenga menos de kk elementos, rellenar con NULL.
Indicar y justificar el orden de ejecución del algoritmo

La función consta de un orden lineal O(n)
*/