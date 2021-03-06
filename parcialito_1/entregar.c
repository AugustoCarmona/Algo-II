/* EJERCICIO 1:
 Implementar una función que reciba un arreglo desordenado de valores enteros (y su largo), que, por division
 y conquista determine si se trata de un arreglo mágico.
 Un arreglo es mágico si existe un valor i tal que arr[i] = i

 Por ejemplo el arreglo [7,3,8,4,5,2,9] no es mágico pero el arreglo [7,3,8,4,2,5,9] sí lo es, puesto que arr[5] = 5.

 Indicar y justificar adecuadamente la complejidad de la función implementada.
*/

#include <stdio.h>
#include <stdbool.h>

bool _arreglo_es_magico(int arr[], size_t ini, size_t fin) {
    if (ini > fin) return false;

    size_t mitad = (ini + fin)/2;

    if (arr[mitad] == mitad) return true;
    
    if (_arreglo_es_magico(arr, ini, fin - 1) || _arreglo_es_magico(arr, mitad + 1, fin)) // 2T(n/2)
        return true;
}

bool arreglo_es_magico(int arr[], size_t n) {
    _arreglo_es_magico(arr, 0, n);
}

/*
 Recurrencia => T(n) = 2T(n/2) + O(1)
 
 Siendo:
 A = 2 Cantidad de veces que se llama la función recursiva.
 B = 2 Cantidad de partes en las que si divide el arreglo.
 C = 0 Todas las demas funciones son constantes complejidad O(1).
 
 Por Teorema Maestro:
 log b (a) = 1 > c => O(n) --> estamos ante un algoritmo de orden lineal.
*/



/* EJERCICIO: 5
 Escribir una función bool cola_magica(cola_t cola) que reciba una cola de punteros a enteros y devuelva true
 si la cola es mágica, false en caso contrario.

 Se considera que una cola es mágica si existe un i tal que el i-ésimo elemento encolado vale.

 Ejemplo cola [4,8,3,1,7,6] (primero en 4) es mágico pues el tercer elemento encolado vale 3.

 La cola puede ser modificada durante la ejecución de la función, pero al finalizar la mísma, debe quedar en el
 mismo estado que el original.

 Indicar y justificar adecuadamente la complejidad de la función implementada.
*/

#include "cola.h"
#include <stdlib.h>

bool cola_magica(cola_t* cola) {
    cola_t* aux = cola_crear();
    bool es_magico = false;
    size_t pos = 1;
    
    while (!cola_esta_vacia(cola) && !es_magico) {
        void* dato = cola_desencolar(cola);
        if (dato == pos) es_magico = true;

        cola_encolar(aux, dato);
        pos++;
    }

    while (!cola_esta_vacia(aux)) { // restaura la cola original
        cola_encolar(cola, cola_desencolar(aux));
    }
    
    cola_destruir(aux, NULL);
    return es_magico;
}

// La función implementada cuenta con una complejidad de O(n) donde n es la cantidad de elementos de la cola.
// Consta de dos ciclos while, pero estos no están anidados (y todas sos operaciones internas son constantes)
// por lo que solo se recorre una vez el total de elementos.



/* EJERCICIO: 9
 Dada una lista enlazada con las estructuras indicadaindicadas:

 Implementar en C la función prmitiva bool lista_any(const lsita_t* lista, bool (*f) (void*)) que devuleve
 true solo si la función f pasada por parámetro devuelve true para alguno de los elementos de la lista.

 Indicar y justificar adecuadamente la complejidad de la función implementada.
*/

#include <stdio.h>
#include <stdbool.h>

typedef struct nodo_lista {
    struct nodo_lista* prox;
    void* dato;
} nodo_lista_t;

typedef struct lista {
    nodo_lista_t *prim;
} lista_t;

bool lista_any(const lista_t* lista, bool (*f) (void*)) {
    nodo_lista_t* act = lista->prim;
    nodo_lista_t* prox = lista->prim->prox;
    bool es_valido = false;

    while (act && es_valido) { // si algún elemento es válido se corta la iteración y se devuelve true
        if (f(act->dato))
            es_valido = true;
        act = prox;
        prox = prox->prox;
    }
    return es_valido;
}

// El orden de esta función es O(n), siendo n la cantidad de elementos de la lista. En su peor caso (si la función
// valida false para todos los elementos) itera a lo largo de toda la lista.
// Cada una de las operaciones (a excepción del while, que es O(n)) es constante.