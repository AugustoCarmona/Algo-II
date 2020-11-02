#include <stdio.h>
#include <stdbool.h>


bool _arreglo_es_magico(int arr[], size_t ini, size_t fin) {
    if (ini > fin) return false;

    size_t mitad = (ini + fin)/2;

    if (arr[mitad] == mitad) return true;
    
    if (_arreglo_es_magico(arr, ini, fin - 1) || _arreglo_es_magico(arr, mitad + 1, fin))
        return true;
    
    return false;
}

bool arreglo_es_magico(int arr[], size_t n) {
    _arreglo_es_magico(arr, 0, n);
}

int main() {
    int arreglo[] = {7,3,8,4,2,5,9};
    size_t largo = sizeof(arreglo)/sizeof(int);
    
    printf( (arreglo_es_magico(arreglo, largo)) ? "\nEl arreglo es mágico\n\n" : "\nEl arreglo no es mágico\n\n");
    
    return 0;
}