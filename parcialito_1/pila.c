#include "pila.h"
#include <stdlib.h>

#define CANTIDAD_I 0 
#define CAPACIDAD_I 10
#define VALOR_MODIF 3

/*
 * Definición del struct pila proporcionado por la cátedra.
 */

struct pila {
    void **datos;
    size_t cantidad;   // Cantidad de elementos almacenados.
    size_t capacidad;  // Capacidad del arreglo 'datos'.
};

/*
 * Funciones auxiliares.
 */

bool pila_redimensionar(pila_t *pila, size_t operacion) {
    void *temp = realloc(pila->datos, operacion * sizeof(void*));
    if (temp == NULL) return false;
    
    pila->capacidad = operacion;
    pila->datos = temp;
    
    return true;
}

/* *****************************************************************
 *                    PRIMITIVAS DE LA PILA
 * *****************************************************************/

pila_t *pila_crear(void) {
    pila_t *pila = malloc(sizeof(pila_t));

    if (pila == NULL) return NULL;
    pila->datos = malloc(CAPACIDAD_I * sizeof(void*));

    if (pila->datos == NULL) {
        free(pila);
        return NULL;
    }

    pila->cantidad = CANTIDAD_I;
    pila->capacidad = CAPACIDAD_I;
    return pila;
}

void pila_destruir(pila_t *pila) {
    free(pila->datos);
    free(pila);
}

bool pila_esta_vacia(const pila_t *pila) {
    return (pila->cantidad == 0);
}

bool pila_apilar(pila_t *pila, void *valor) {
    if (pila->capacidad == pila->cantidad)
        if (!pila_redimensionar(pila, (size_t) (pila->capacidad *= VALOR_MODIF))) return false; //redimensiona y controla que la redimension haya funcionado correctamente
    
    pila->datos[pila->cantidad++] = valor;
    return true;
}

void *pila_ver_tope(const pila_t *pila) {
    return (!pila_esta_vacia(pila)) ? pila->datos[pila->cantidad - 1] : NULL;
}

void *pila_desapilar(pila_t *pila) {
    if (pila_esta_vacia(pila)) return NULL;

    void *extraido = pila_ver_tope(pila);

    if (pila->capacidad == pila->cantidad * 4) {
        pila_redimensionar(pila, (size_t) (pila->cantidad /= VALOR_MODIF)); //no se controla que devuelva true ya que siempre que se hace un realloc reduciendo va a devolver true
    } --pila->cantidad;

    return extraido;
}