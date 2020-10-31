#include "pila.h"

// Dada una pila, necesito iterarla hasta que este vacia, desapilar sus elementos y encolarlos en otra estructura (cola) ya que si no desapilo los elementos no podré ver más que el primero.

bool pila_es_piramidal(pila_t* pila) {
    pila_t* pila_aux = pila_crear();
    bool es_piramidal = true;
    
    while (!(pila_esta_vacia(pila)) && es_piramidal ) { // mientras haya elementos en la pila y se cumplan las condiciones para que esta sea piramidal.
        int* tope = (int*) pila_desapilar(pila); //casteo
        int* siguiente = (int*) pila_ver_tope(pila); //casteo

        es_piramidal = siguiente ? *tope < *siguiente : true; // sin no hay inferior es por que llegamos al final de la pila, es decir la pila es piramidal

        pila_apilar(pila_aux, (void *) tope);
    }

    while (!(pila_esta_vacia(pila_aux))) { // cuando se haya terminado no importa si la pila original esta vacía o no, se la va a recomponer por completo y por ultimo se destruirá la pila auxiliar.
        pila_apilar(pila, pila_desapilar(pila_aux));
    }
    
    pila_destruir(pila_aux);
    return es_piramidal;
}
