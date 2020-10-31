# Enunciados

## Ejercicio 1:

Implementar en C el TDA composición de funciones, que emula la composición de funciones, según las primitivas dadas

Consideraciones:
    - El orden en el cual se agregan las funciones es el orden en el cual se leen, es decir de afuera hacia adentro.
    - El orden en el cual se aplican las funciones es de adentro hacia afuera.
Ejemplo:
                    f(g(x))
    - Para este caso debería haber:
        1) Agregado la función f()
        2) Agregado la función g()

Nota: La idea es la siguiente. Primero vamos a necesitar un struct composicion, el cual cuando llamamos a laprimitiva agregar_funcion lo que debemos hacer es guardar dicha funcion que recibimos en el struct. Puede ser una funcion del tipo funcion_t que multiplique por dos, divida por un numero, etc.

Necesitamos algún tda que sirva para guardar las funciones y luego cuando apliquemos lo que debemos hacer estomar el numero que nos den y comenzar a aplicar las fuciones que tenemos guardadas en el orden que correspondan.

Vamos a usar una pila para el proceso.

## Ejercicio 2:

Lista eliminar pares.
Dada una lista enlazada implementada con las siguientes estructuras:

typedef struct nodo_lista {
    struct nodo_lista* prox;
    void* dato
} nodo_lista_t;

typedef struct lista {
    nodo_lista_t* prim;
} lista_t;

Escribir una primitiva que reciba una lista y elimine todos los elementos que se encuentren en posiciones pares, recorriendo la lista una sola vez y sin usar estructuras auxiliares.
Por ejemplo, si se recibe la lista [1,5,10,3,8] debe quedar [5,3,8].
Indicar el orden de complejidad de la primitiva.

Voy a recorrer la lista enlazada, y mi única forma d entrar es a traves del primero. ¿Qué variales necesito para recorrerla?
    -una referencia al nodo actual
    -una referencia al anterior
    -un contador que represente la posicion

## Ejericicio 3:

(17 de la guía)
Implementar una función que utilice división y conquista de orden O(n log n) que dado un arreglo de n números devuelva true o false según existe algún elemento que aparezca más de la mitad de las veces. Justificar el orden de la solución.

Ejemplos:
[1,2,2,1,2,3] --> false
[1,1,2,3] --> false
[1,2,3,1,1,1] --> true
[1] --> true

Aclaración: Este ejercicio puede resolverse casi trivialmente, ordenando el arreglo con un algoritmo eficiente, o incluso se puede realizar más rápido utilizando una tabla de hash. Para hacer interesante este ejercicio, resolver sin ordenar el arreglo, sino pueramente división y conquista.

Notas: si estamos muy perdidos puede ser una buena idea comenzar por un análisis del orden. No olvidar el teorema maestro. Merge Sort.

## Ejercicio 5:

Cola multiplos primeros

A. Implementar la primitiva void** cola mulplosprimeros(const cola t* cola, size_t k) que dada una cola y un numero k, devuelva los primeros k elementos de la cola en el mismo orden en el que habrian salido de la cola.
Encaso que la cola tenga menos de j elementos, rellenar con NULL. La cola debe queadar en el mismo estado que al invocarse la primitiva.
Indicar el orden de ejecución del algoritmo. Justificar.

B. Implementar la función 'void ** cola mulpliprimeros (cola t* cola, size t k)' con el mismo comportamiento dela primitiva anterior

## Ejercicio 6:

Pila Piramidal

Dada una pila de enteros, escribir una función que determine si es piramidal. Una pila de enteros es piramidal si cada elemento es menor a su elemento inferior (en el sentido que va desde el tope de la pila hacia el otro extremo).
La pila no debe ser modificada.