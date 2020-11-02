#ifndef LISTA_STR
#define LISTA_STR
#include "lista.h"

/*
 * Definición de los tipos de datos. 
 * Esto se define en un archivo aparte unicamente para que se pueda tener 
 * acceso sin estar escribiendo en el .c. No es la forma correcta de implementar esto. 
 */

typedef struct nodo {
    void *dato;
    struct nodo *prox;
} nodo_t;

struct lista {
    nodo_t *primero;
    nodo_t *ultimo;
    size_t largo;
};

#endif