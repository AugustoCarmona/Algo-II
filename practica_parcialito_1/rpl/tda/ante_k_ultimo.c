#include "lista.h"
#include "lista_struct.h"

void* lista_ante_k_ultimo(lista_t* lista, size_t k) {
    nodo_t* p1 = lista->primero;
    nodo_t* p2 = lista->primero;

    for (size_t i = 0; i < k; i++)
        p1 = p1->prox;
    
    while (p1) {
        p1 = p1->prox;
        p2 = p2->prox;
    }
    // estos dos punteros van a estar a una distancia k
    // cuando p1 llegue al final, p2 va a estar a k elementos del final
    return p2->dato;
}


/*
Dada una lista enlazada implementada con las siguientes estructuras:

typedef struct nodo {
    void *dato;
    struct nodo *prox;
} nodo_t;

struct lista {
    nodo_t *primero;
};

Escribir una primitiva que reciba una lista y devuelva el elemento que esté a k posiciones del final (el ante-k-último),
recorriendo la lista una sola vez y sin usar estructuras auxiliares. Considerar que k es siempre menor al largo de la lista.

Por ejemplo, si se recibe la lista [ 1, 5, 10, 3, 6, 8 ], y k = 4, debe devolver 10. Indicar el orden de complejidad de la primitiva.

La táctica es la siguiente: ambos punteros inician en la misma posición sobre la lista, pero adelantamos el primero k posiciones, y luego
lo movemos hasta el final junto con el segundo, de manera que el segundo quede a k posiciones del final

El orden de la primitiva es O(n) por que se itera a lo largo de esta solo una vez.
*/