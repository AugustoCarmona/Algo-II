#include "cola.h"
#include <stdlib.h>

void cola_filtrar(cola_t* cola, bool (*filtro)(void*)) { // O(n) "pero en realidad depende de filtro"
    cola_t* aux = cola_crear();
    while (!cola_esta_vacia(cola)) {
        void* dato = cola_desencolar(cola);
        if (filtro(dato)) cola_encolar(aux, dato);
    }
    while (!cola_esta_vacia(aux)) cola_encolar(cola, cola_desencolar(aux));
    free(aux);
}

/*
Implementar una función void void cola_filtrar(cola:t* cola, bool (*filtro) (void*)), que elimine los elementos encolados para los cuales
la función filtro devuelve false.
Aquellos elemetnos que no son eliminaos deben permannecer e el mismo orden en el que estaban antes de invocar a la función.
No es necesario destruir los elementos que si fueron eliminados.
Se pueden utilizar las estructuras auxiliares que se consideren necesarias y no está permitido acceder a la estructura interna de la cola (es una función).
¿Cuál es el orden del algoritmo implementado?
*/