// #include "main.h" // No borrar

#include "pila.h"

bool pila_es_piramidal(pila_t* pila) {
    pila_t* pila_aux = pila_crear();
    bool es_piramidal = true;
    
    while (!pila_esta_vacia(pila) && es_piramidal ) {
        int* tope = (int*) pila_desapilar(pila);
        int* siguiente = (int*) pila_ver_tope(pila);

        es_piramidal = siguiente ? *tope < *siguiente : true; // si no hay inferior es por que llegamos al final de la pila, es decir es piramidal
        pila_apilar(pila_aux, (void *) tope);
    } while (!pila_esta_vacia(pila_aux)) pila_apilar(pila, pila_desapilar(pila_aux)); // recompone la pila
    
    pila_destruir(pila_aux);
    return es_piramidal;
}