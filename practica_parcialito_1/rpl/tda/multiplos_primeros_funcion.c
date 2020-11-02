#include "cola.h"
#include "multiplos_primeros_funcion.h"
#include <stdlib.h>

void** cola_multiprimeros(cola_t* cola, size_t k) {

    void** elementos = calloc(k, sizeof(void*)); // por que hay que rellenar con NULL (guarda los primeros elementos hasta k)
    if (!elementos) return NULL;

    for (size_t i = 0; i < k && !cola_esta_vacia(cola); i++) {
        elementos[i] = cola_desencolar(cola);
    } return elementos;
}

/*
Implementar la función void** cola_multiprimeros(cola_t* cola, size_t k) que dada una cola y un número k, devuelva los primeros k elementos de
la cola, en el mismo orden en el que habrían salido de la cola. En caso que la cola tenga menos de kk elementos, rellenar con NULL.
Indicar y justificar el orden de ejecución del algoritmo.
*/