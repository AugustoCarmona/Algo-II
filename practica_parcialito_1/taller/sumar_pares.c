#include <stdio.h>
#include <stdbool.h>

typedef struct nodo {
    struct nodo* prox;
    int* dato;
} nodo_t;

typedef struct lista {
    nodo_t* prim;
} lista_t;

void lista_iterar(lista_t lista, bool (*visitar) (void* dato, void* extra)) {
}









/* esta implementacion es incorrecta 

int visitar(lista_t* lista)
{
    int contador = 0;
    nodo_t* act = lista->prim;
    nodo_t* prox = lista->prim->prox;

    while (prox) {

        int dato = act->dato;

        if ((dato % 2) == 0)
            contador += dato;

        act = prox;
    }
    int ult = lista->prim->dato;
    contador += ult;
    return contador;
}

// primero necesito corroborar que la lista no está vacía
// luego necesito iterarla hasta que se vacíe controlando nada numero en sus nodos y sumándolos a un contador en caso de que sean pares

*/