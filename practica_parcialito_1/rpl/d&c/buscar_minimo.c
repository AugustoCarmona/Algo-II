#include <stdio.h>

int buscar_minimo(int arr[], size_t n);
int mergeSort(int arr[], size_t inicio, size_t final);
void merge(int arreglo[], int inicio, int medio, int final);

int main()
{
    int arr[] = {4,66,5,-9,2,7,6,8,3};
    size_t elementos = sizeof(arr)/sizeof(int);
    printf("\nEl mínimo del arreglo es: %d\n", buscar_minimo(arr, elementos));

    return 0;
}

int buscar_minimo(int arr[], size_t n) {
    size_t inicio = 0;
    size_t medio = (inicio + n) / 2;
    mergeSort(arr, inicio, n);
    return(arr[0]);
}

int mergeSort(int arr[], size_t inicio, size_t final) {
    if ((final - inicio) < 2) return arr[0];

    size_t medio = (inicio+final)/2;

    mergeSort(arr, inicio, medio);
    mergeSort(arr, medio, final);
    merge(arr, inicio, medio, final); // itercala los elmentos
}

void merge(int arreglo[], int inicio, int medio, int final) {
    int pos_1 = inicio, pos_2 = medio, temp[final - inicio], pos_a = 0;

    while ((pos_1 < medio) && (pos_2 < final)) {
        if (arreglo[pos_1] <= arreglo[pos_2]) {
            temp[pos_a] = arreglo[pos_1];
            pos_a++;
            pos_1++;
        } else {
            temp[pos_a] = arreglo[pos_2];
            pos_a++;
            pos_2++;
        }
    }

    while (pos_1 < medio) {
        temp[pos_a] = arreglo[pos_1];
        pos_a++;
        pos_1++;
    }

    while (pos_2 < final) {
        temp[pos_a] = arreglo[pos_2];
        pos_a++;
        pos_2++;
    }

    int a = 0;
    int i = inicio;
    while (i < final) {
        arreglo[i] = temp[a];
        i++;
        a++;
    }
}

// Implementar por división y conquista una función que determine el mínimo de un arreglo. Indicar y justificar el orden.
// No puedo recurrir a la búsqueda binaria, debido a que el arreglo puede no estar ordenado (requisito fundamental)
// Pruebo con recurrir al algoritmo Merge Sort

// Para poder encontrar el mínimo elemento de un arreglo es indispensable recorrer TODO el arreglo.
// Con Merge puedo ordenar el arreglo y luego devolver el primer elemento. A otra cosa. XD


/*
 * No puedo recurrir a la búsqueda binaria debido a que el arreglo que me llegue puede no estar ordenado (requisito
 * fundamental).
 *
 * Así mismo, para poder encontrar el mínimo valor de un arreglo, hay que iterar a lo largo de todos sus elementos,
 * por lo que tampoco me es conveniente usar Quick Sort, ya que en caso de llegarme un arreglo ordenado estaría obteniendo
 * el peor tiempo de este algorítmo O(n²).
 *
 * Es así que lo que me conviene es usar Merge Sort para, iterar una sola vez a lo largo de todo el vector, el cual ya quedará
 * ordenado por lo que puedo devolver su primer valor sabiendo que será el más pequeño, siempre con una misma complejidad
 * de O(n log n).
 
 
 
 
 
 void min(int vector[],size_t i,size_t j, size_t *minPos)
{
    size_t middle, minPos1=0;

    *minPos=i;
    if(i==j) return;
    else if(i==j-1)
    {
        *minPos = (vector[i]<vector[j])?i:j;
        return;
    }
    else
    {
        // partimos a la mitad el vector
        middle= i + (j-i)/2;
        min(vector,0,middle,minPos);
        min(vector,middle+1,j,&minPos1);
        *minPos = ((vector[*minPos]<=vector[minPos1])?*minPos:minPos1);
    }

}

int buscar_minimo(int arr[], size_t n) {
    size_t minPos=0;

    // casos base
    if(n==0) return -1;
    if(n==1) return 1;

    min(arr,0,n-1,&minPos);
    return arr[minPos];
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 */