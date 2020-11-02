#include <stdlib.h>
#include <stdio.h> // sprintf
#include "fraccion.h"

struct fraccion {
    int* num;
    int* den;
};


fraccion_t* fraccion_crear(int numerador, int denominador) {
    if (denominador == 0) return NULL; // si se pasó como denominador cero, devuelve null
    
    fraccion_t* fraccion = malloc(sizeof(fraccion_t));
    if (!fraccion) return NULL; // verifica que se haya podido crear

    fraccion->num = numerador;
    fraccion->den = denominador;
    
    return fraccion;
}

void fraccion_destruir(fraccion_t* fraccion) {
    free(fraccion->num);
    free(fraccion->den);
    free(fraccion);
}

fraccion_t* fraccion_sumar(fraccion_t* f1, fraccion_t* f2) {
    int den_1 = f1->den;
    int den_2 = f2->den;
    int num_1 = f1->num;
    int num_2 = f2->num;

    int nuevo_denominador = den_1*den_2;
    int nuevo_numerador = (num_1 * den_2) + (num_2 * den_2);

    fraccion_t* nueva_fraccion = fraccion_crear(nuevo_numerador, nuevo_denominador);
    if (!nueva_fraccion) return NULL;

    fraccion_destruir(f1);
    fraccion_destruir(f2);

    return nueva_fraccion;
}

fraccion_t* fraccion_mul(fraccion_t* f1, fraccion_t* f2) {
    int den_1 = f1->den;
    int den_2 = f2->den;
    int num_1 = f1->num;
    int num_2 = f2->num;

    int nuevo_denominador = den_1*den_2;
    int nuevo_numerador = num_1*num_2;

    fraccion_t* nueva_fraccion = fraccion_crear(nuevo_numerador, nuevo_denominador);
    if (!nueva_fraccion) return NULL;

    fraccion_destruir(f1);
    fraccion_destruir(f2);

    return nueva_fraccion;
}

int fraccion_parte_entera(fraccion_t* fraccion) {
    int num = fraccion->num;
    int den = fraccion->den;
    int parte_entera = num / den;
}

char* fraccion_representacion(fraccion_t* fraccion) {
    int num = fraccion->num;
    int den = fraccion->den;
    int mcd;

    if (den == 1)
        return sprintf("%d", num);;

    mcd = maximo_comun_divisor(num, den);
    int num = num / mcd;
    int den = den / mcd;

    return sprintf("%d/%d", num, den);
}

int maximo_comun_divisor(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    } return a;
}


/*
Implementar el TDA Fracción. Dicho TDA debe tener las siguientes primitivas, cuya documentación puede encontrarse en fraccion.h:

fraccion_t* fraccion_crear(int numerador, int denominador);
fraccion_t* fraccion_sumar(fraccion_t* f1, fraccion_t* f2);
fraccion_t* fraccion_mul(fraccion_t* f1, fraccion_t* f2);
char* fraccion_representacion(fraccion_t* fraccion);
int fraccion_parte_entera(fraccion_t* fraccion);
void fraccion_destruir(fraccion_t* fraccion);

Nota: considerar que se puede utilizar la función sprintf para generar la representación de la fracción. Por ejemplo: sprintf(buffer, "%d/%d", num1, num2).
*/