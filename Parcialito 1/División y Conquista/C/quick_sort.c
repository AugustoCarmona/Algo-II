#include <stdio.h>
#include "vector.h"

int quickSort(int arreglo[])
{
    int largo = sizeof(arreglo) / sizeof(arreglo[0]);
    
    if (largo <= 1) //caso base
        return arreglo;

    int pivot = arreglo[0];
    int mayores[] = {};
    int menores[] = {};

    for (size_t i = 0; i < largo; i++)
    {
        if (arreglo[i] > pivot)
            mayores[i] = arreglo[i];
        else
            menores [i] = arreglo[i];
    }

    return quickSort(mayores) + pivot + quickSort(menores);
}

int main()
{
    vector_t *vector = vector_crear(15);
    int arreglo[] = {4,10,8,7,6,5,3,12,14,2};

    for (size_t i = 0; i < 10; i++)
        vector_guardar(arreglo[i]);
    

    printf("%d", quickSort(arreglo));
    
    return 0;
}
