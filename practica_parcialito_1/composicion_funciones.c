#include "composicion_funciones.h"
#include "pila.h"

struct composicion {
    pila_t* funciones;
};

/* Primitivas del TDA */

composicion_t *composicion_crear(void) {
    
    composicion_t* composicion = malloc(sizeof(composicion_t)); // puntero
    if (!composicion) return NULL;

    composicion->funciones = pila_crear();

    if (!composicion->funciones) {
        free(composicion);
        return NULL;
    }
     return composicion;
}

void composicion_destruir(composicion_t* composicion) {
    pila_destruir(composicion->funciones); //no te olvides que no tenes acceso a los datos internos de la pila
    free(composicion);
}

bool composicion_agregar_funcion(composicion_t* composicion, funcion_t* funcion) {
    return (pila_apilar(composicion->funciones, (void*) funcion));
}

/* Resolucion iterativa */

void composicion_aplicar(composicion_t* composicion, double x) {

    double res = x;

    while (!pila_esta_vacia(composicion->funciones)) {
        res = ((funcion_t) pila_desapilar(composicion->funciones)) (res); //hay que castear para poder pasar parametros
    }
    return res;
}

/* Alternativa a la solucion iterativa

void composicion_aplicar(composicion_t* composicion, double x) {

    double res = x;

    while (!pila_esta_vacia(composicion->funciones)) {
        funcion = (funcion_t) pila_desapilar(composicion->funciones);
        res = funcion(res);
    }
    return res;
}

    Resolucion recursiva

void composicion_aplicar(composicion_t* composicion, double x) {
    if (pila_esta_vacia(composicion->funciones)) return x; //caso base

    funcion_t funcion = pila_desapilar(composicion->funciones); //aqui el casteo es automatico
    return composicion_aplicar(composicion, funcion(x));
}

//pila desapilar devuelve una funcion del tipo (void*)

*/