#include <stdio.h>
#include <stdbool.h>

/*  Ejercicio 1: composición de funciones 0:0:18

    Implementar en C el TDA composición de funciones, que emula la composición de funciones, según las primitivas dadas

    Consideraciones:
        - El orden en el cual se agregan las funciones es el orden en el cual se leen, es decir de afuera hacia adentro.
        - El orden en el cual se aplican las funciones es de adentro hacia afuera.

    Ejemplo:
                        f(g(x))
        - Para este caso debería haber:
            1) Agregado la función f()
            2) Agregado la función g()
*/

struct composicion;

typedef struct composicion composicion_t;

typedef double (*funcion_t) (double);

composicion_t composicion_crear();

void composicion_destruir(composicion_t);

bool composicion_agregar_funcion(composicion_t, funcion_t);

double composicion_aplicar(composicion_t, double)

/*
    Nota: La idea es la siguiente. Primero vamos a necesitar un struct composicion, el cual cuando llamamos a la primitiva agregar_funcion lo que debemos hacer es guardar dicha funcion que recibimos en el struct. Puede ser una funcion del tipo funcion_t que multiplique por dos, divida por un numero, etc.

    Necesitamos algún tda que sirva para guardar las funciones y luego cuando apliquemos lo que debemos hacer es tomar el numero que nos den y comenzar a aplicar las fuciones que tenemos guardadas en el orden que correspondan.
*/