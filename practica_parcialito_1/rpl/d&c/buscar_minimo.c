#include <stdio.h>

int buscar(int arr[], size_t inicio, size_t fin) {
    if(inicio == fin) return arr[inicio]; 
    size_t medio = (inicio + fin) / 2;
    
    int minimo_izquierda = buscar(arr, inicio, medio); // llama a ordenar a las dos mitades y devuelve solo una
    int minimo_derecha = buscar(arr, medio + 1, fin);
    
    return minimo_derecha > minimo_izquierda ? minimo_izquierda : minimo_derecha; // compara y devuelve
}

int buscar_minimo(int arr[], size_t n) {
    return buscar(arr, 0, n - 1);
}

int main() {
    int arr[] = {1,2,3,4,5,-3,6,7};
    size_t largo = sizeof(arr)/sizeof(int);
    printf("El elemento más pequeño es: %d", buscar_minimo(arr, largo));

    return 0;
}

// Implementar por división y conquista una función que determine el mínimo de un arreglo. Indicar y justificar el orden.
// No puedo recurrir a la búsqueda binaria, debido a que el arreglo puede no estar ordenado (requisito fundamental)
// Pruebo con recurrir al algoritmo Merge Sort

// Para poder encontrar el mínimo elemento de un arreglo es indispensable recorrer TODO el arreglo.
// Con Merge puedo ordenar el arreglo y luego devolver el primer elemento.

/*
 Ecuación de recurrencia: T(n) = AT(n/B) + O(n^c)
 
 A = 2 Llama a las dos mitades / esto está mal
 B = 2 Divido el vector en 2
 C = 0 Solo todas las operaciones internas lineales O(1)

 logb(A) = log2(1) = C = 0
 Seria O(log2(n) * n ^ C) = O(log(n)) --> esto está mal
*/