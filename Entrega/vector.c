#include "vector.h"

// Funciones a implementar.

void vector_destruir(vector_t *vector) {
    free(vector->datos);
    free(vector);
}

bool vector_obtener(vector_t *vector, size_t pos, int *valor) {
    if (pos < vector->tam) {
        *valor = vector->datos[pos];
        return true;
    } return false;
}

bool vector_guardar(vector_t *vector, size_t pos, int valor) {
    if (pos < vector->tam) {
        vector->datos[pos] = valor;
        return true;
    } return false;
}

size_t vector_largo(vector_t *vector) {
    return vector->tam;
}

// Funciones ya implementadas.

vector_t *vector_crear(size_t tam) {
    vector_t *vector = malloc(sizeof(vector_t)); //pide memoria para el puntero *vector

    if (vector == NULL) { //verifica que malloc haya funcionado correctamente
        return NULL;
    }
    vector->datos = malloc(tam * sizeof(int)); //pide memooria para *datos, multiplicando el valor pasado como tam por la cantidad de memoria que ocupe un int n el sistema

    if (tam > 0 && vector->datos == NULL) {
        free(vector); //en el caso de que este malloc haya fallado siendo un tam > 0 hay que liberar el malloc anterior para no perder memoria
        return NULL;
    }
    vector->tam = tam; //si todo funciona asignamos finalmente tam
    return vector;
}

bool vector_redimensionar(vector_t *vector, size_t tam_nuevo) {
    int *datos_nuevo = realloc(vector->datos, tam_nuevo * sizeof(int)); //reasigna a la memoria que ocupa el vector que ya tenemos el espacio de memoria que hayamos pasado como parametro

    // Cuando tam_nuevo es 0, es correcto si se devuelve NULL.
    // En toda otra situación significa que falló el realloc.
    if (tam_nuevo > 0 && datos_nuevo == NULL) {
        return false;
    }

    vector->datos = datos_nuevo; //se pisan los datos con el nuevo puntero
    vector->tam = tam_nuevo; //se modifica el tamaño
    return true;
}

// run command: gcc -g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -o pruebas *.c
