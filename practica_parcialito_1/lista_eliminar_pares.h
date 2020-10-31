/* 0:59:29
    Ejercicio 2: Lista eliminar pares.

    Dada una lista enlazada implementada con las siguientes estructuras:

    typedef struct nodo lista {
        struct nodo_lista* prox;
        void* dato
    } nodo_lista_t;

    typedef struct lista {
        nodo_lista_t* prim;
    } lista_t;

    Escribir una primitiva que reciba una lista y elimine todos los elementos que se encuentren en posiciones pares, recorriendo la lista una sola vez y sin usar estructuras auxiliares.

    Por ejemplo, si se recibe la lista [1,5,10,3,8] debe quedar [5,3,8].

    Indicar el orden de coplijidad de la primitiva.

    Voy a recorrer la lista enlazada, y mi única forma d entrar es a travpes del primero. ¿Qué variales necesito para recorrerla?

        -una referencia al nodo actual
        -una referencia al anterior
        -un contador que represente la posision
*/