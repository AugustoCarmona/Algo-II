#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct nodo_lista {
    struct nodo_lista* prox; 
    void* dato;
} nodo_lista_t;

typedef struct lista {
    nodo_lista_t* prim;
} lista_t;

void eliminar_pares(lista_t* lista) {

    nodo_lista_t* act = lista->prim;
    nodo_lista_t* ant = NULL;
    size_t pos = 0;

    while (act) {
        nodo_lista_t* aux = act->prox; // auxiliar es el proximo dato en la lista

        if (!pos) { // cero (se elimina)
            aux = lista->prim;
            free(act);
        }

        if (!(pos % 2) && pos) { // par (se elimina)
            ant->prox = aux;
            free(act);
        }

        if (pos % 2)  // impar (solo se pasa al siguiente nodo) 
            ant = act;

        act = aux;
        pos++;
    }
}

/*
    El orden de esta funcion es O(n) - Lineal
    Tiene una unica iteracion a lo largo de todos los elementos (n es la cantidad de elementos) y todas
    las operaciones que realiza dentro de la iteracion son constantes.
*/