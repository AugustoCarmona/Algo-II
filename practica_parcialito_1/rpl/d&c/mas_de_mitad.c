#include <stdio.h>
#include <stdbool.h>

int candidateador(int* arr, size_t ini, size_t fin) {
    if (ini > fin) return false;
    if (ini == fin) return true;

    size_t medio = (ini+fin)/2;
    int cand_izquierda = candidateador(arr, ini, medio);
    int cand_derecha = candidateador(arr, medio+1, fin);

    int cont_1 = 0, cont_2 = 0; // cuenta que candidato apareció más veces
    for (size_t i = 0; i < fin; i++) {
        if (arr[cont_1] == cand_izquierda) i++;
        if (arr[cont_2] == cand_derecha) cont_2++;
    } return cont_1>cont_2 ? cand_izquierda : cand_derecha;
}

bool mas_de_mitad(int* arr, size_t n) {
    int cand = candidateador(arr, 0, n);
    int cont = 0;
    
    for (size_t i = 0; i < n; i++) {
        if (arr[i] == cand) cont++;
    } return cont > n/2;
}

int main() {
    int arr[] = {1,2,3,1,1,1}; // debe devolver 9
    size_t largo = sizeof(arr)/sizeof(int);
    printf( mas_de_mitad(arr, largo) ? "true PAPÁ" : "false PAPÁ");

    return 0;
}

// Implementar una función (de orden O(n log n) que dado un arreglo de n número enteros decuelva true o false según si existe algún elemento que aprezca más de la mitad de las veces.) --> combiene usar o un algoritmo de Mergesort, o un algoritmo de Quicksort

// [1,2,1,2,3] --> false
// [1,1,2,3] --> false
// [1,2,3,1,1,1] --> true
// [1] --> true

/*
Teorema Maestro:

O(n) + 2O(n/2) -> a=2, b=2, c=1 -> logb(a) = 1 = c -> O(n log(n))
*/

/*
o...

Teorema Maestro:

T(n) = 2*T(n/2) + O(n) -> A = 2, B = 2, C = 1
-> log_B(A) = log_2(2) = 1 = C -> O(n^C*log(n)) = O(n^1*log(n)) = O(n*log(n))
*/