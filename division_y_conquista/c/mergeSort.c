#include <stdio.h>

void printArray(int arreglo[], int inicio, int final);
void mergeSort(int arreglo[], int inicio, int final);
void merge(int arreglo[], int inicio, int medio, int final);

int main() {
    int arreglo[] = {64, 7, -4, 2, 55, 0, 9, 1};
    int largo = sizeof(arreglo)/sizeof(int);

    printf("### MERGE SORT ###\n\n");
    printArray(arreglo, 0, largo);
    printf("arreglo desordenado\n");
    mergeSort(arreglo, 0, largo);
    printArray(arreglo, 0, largo);
    printf("arreglo ordenado\n");
    
    return 0;
}

void mergeSort(int arreglo[], int inicio, int final) {
    if ((final - inicio) < 2) return;

    int puntoMedio = (final + inicio) / 2;

    mergeSort(arreglo, inicio, puntoMedio);
    mergeSort(arreglo, puntoMedio, final);
    merge(arreglo, inicio, puntoMedio, final); // funcion que se ocupa de intercalar los elementos
}

void merge(int arreglo[], int inicio, int medio, int final) {
    int pos1 = inicio;
    int pos2 = medio;
    int temp[final - inicio];
    int posA = 0;

    while ((pos1 < medio) && (pos2 < final)) {
        if (arreglo[pos1] <= arreglo[pos2]) {
            temp[posA] = arreglo[pos1];
            posA++;
            pos1++;
        } else {
            temp[posA] = arreglo[pos2];
            posA++;
            pos2++;
        }
    }

    while (pos1 < medio) {
        temp[posA] = arreglo[pos1];
        posA++;
        pos1++;
    }

    while (pos2 < final) {
        temp[posA] = arreglo[pos2];
        posA++;
        pos2++;
    }

    int a = 0;
    int i = inicio;
    while (i < final) {
        arreglo[i] = temp[a];
        i++;
        a++;
    }
}

void printArray(int arreglo[], int inicio, int final) {
    printf("[");
    for (size_t i = 0; i < final; i++)
        printf("%d ", arreglo[i]);
    printf("] --> ");
}