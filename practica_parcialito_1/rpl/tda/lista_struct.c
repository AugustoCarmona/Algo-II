#include "lista.h"
#include "lista_struct.h"

void lista_invertir(lista_t* lista) {
    nodo_t* act = lista->primero;
    nodo_t* ant = NULL;
    nodo_t* prox = act ? act->prox: NULL; // en caso de que la lista tenga solo un elemento

    while (act) {
        act->prox = ant;
        ant = act;
        act = prox;
        prox = act ? act->prox : NULL;
    } lista->primero = ant;
}

/*
Implementar en C una primitiva void lista_invertir(lista_t* lista) que invierta la lista recibida por parámetro, sin utilizar estructuras auxiliares.
Indicar y justificar el orden de la primitiva.
*/