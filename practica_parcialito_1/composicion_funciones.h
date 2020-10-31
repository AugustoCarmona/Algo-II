#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* Definicion de los tipos de datos */

struct composicion;
typedef struct composicion composicion_t;
typedef double (*funcion_t) (double); // funcion_t es un tipo de dato que recibe un double y devuelve un double

/*
 * Primitivas
 */

//crea el tda
composicion_t composicion_crear();

//destruye el tda
void composicion_destruir(composicion_t);

//apila
//agrega una nueva funcion a la composicion
bool composicion_agregar_funcion(composicion_t, funcion_t);

//desapila todo el contenido
//basicamente necesito ir desapilando de la composicion, y a medida que lo hago debo aplicar la funcion desapilada 
//aplica todas la funciones que posee en el orden adecuado
double composicion_aplicar(composicion_t, double)

/* Aca deberian ir las pruebas unitarias */