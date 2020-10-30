#include <stdio.h>

void imprimirArreglo(int arreglo[], int inicio, int final);
void swap(int arreglo[], int inicio, int final);
void quickSort(int arreglo[], int inicio, int final);

int main() {
	int arreglo[] = {4,10,8,7,6,5,3,12,14,2};
	int fin = sizeof(arreglo)/sizeof(int);

	printf("### QUICK SORT ###\n\n");
	imprimirArreglo(arreglo, 0, fin);
	printf("arreglo desordenado\n");
	quickSort(arreglo, 0, fin);
	imprimirArreglo(arreglo, 0, fin);
	printf("arreglo ordenado\n");

	return 0;
}

void quickSort(int arreglo[], int inicio, int final) {
	if ( (final - inicio) < 2 ) return;

	int pivot = inicio, ult_menor = inicio;
	int punto_medio = (inicio + final) / 2;
	swap(arreglo, punto_medio, pivot); // aqui se cambia el ELEMENTO

	for (size_t i = pivot + 1; i < final; i++) { // por que pivot +1?
		if (arreglo[i] < arreglo[pivot] ) {
			ult_menor++;
			swap(arreglo, ult_menor, i);
		}
	}

	swap(arreglo, pivot, ult_menor);
	quickSort(arreglo, inicio, ult_menor);
	quickSort(arreglo, ult_menor + 1, final);
}

void swap(int arreglo[], int pos_1, int pos_2) {
	int temp = arreglo[pos_1];
	arreglo[pos_1] = arreglo[pos_2],
	arreglo[pos_2] = temp;
}

void imprimirArreglo(int arreglo[], int inicio, int final) {
	printf("[");
	for (size_t i = 0; i < final; i++)
		printf("%d ", arreglo[i]);
	printf("] --> ");
}
