    int arrgelo[] = { 1,2,2,1,2,3 }; // debe devolver true
#include <stdio.h>
#include <stdbool.h>

/*

a = 2
b = 2
c = 1

Tenemos dos llamadas recursivas, cada una con la mitad de los elementos del arreglo, y debemos hacer algo lineal

El trabajo consistira en partir el arreglo en dos mitades (pues b)
Trabajar con ambas (pued a)
El costo de trabajar con ambas para obtener el resultado esperado debe costar O(n) (pues c)
*/

bool evaluar_repeticiones(int arreglo[], int inicio, int final);
void merge(int arreglo[], int inicio, int medio, int final);
void imprimir_arreglo(int arreglo[], int inicio, int final);

int main() {
    
    int inicio = 0;
    int final = sizeof(arrgelo) / sizeof(int); // clacula la cantidad de elementos

    imprimir_arreglo(arrgelo, inicio, final);
    printf("arreglo pasado como parámetro\n");
    printf( evaluar_repeticiones(arrgelo, inicio, final) ? "true\n" : "false\n" );

    return 0;
}

bool evaluar_repeticiones(int arreglo[], int inicio, int final) {
    
    if ( (final - inicio) < 2 ) return final; // caso base, si el arreglo es igual o menor a 1 entonces no debemos seguir iterando

    int puntoMedio = (final + inicio) / 2;

    evaluar_repeticiones(arreglo, inicio, puntoMedio);
    evaluar_repeticiones(arreglo, puntoMedio, final);
    merge(arreglo, inicio, puntoMedio, final); // intercala elementos
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

void imprimir_arreglo(int arreglo[], int inicio, int final) {
    printf("[");
    for (size_t i = 0; i < final; i++)
        printf("%d ", arreglo[i]);
    printf("] --> ");
}