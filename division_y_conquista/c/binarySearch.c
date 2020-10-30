//implementacion iterativa

#include <stdio.h>
#include <stdbool.h>

void binaySearch(int arreglo[], int dato, int sup);

int main() {
    int arreglo[] = {1,2,3,4,5,6,7,8,9};
    int dato = 7;
    int cant_elementos = sizeof(arreglo) / sizeof(int); //define el numero superior de iteraciones

    binaySearch(arreglo, dato, cant_elementos);

    return 0;
}

void binaySearch(int arreglo[], int dato, int sup) {

    int inf = 0;
    bool bandera = false;
    int mitad;

    while ((inf <= sup) && (!bandera)) {
        mitad = (inf + sup) / 2;

        if (arreglo[mitad] == dato) bandera = true;
        
        if (arreglo[mitad] > dato) sup = mitad;
        
        if (arreglo[mitad] < dato) inf = mitad;
    }

    if (bandera)
        printf("el número solicitado se encuentra en la posicion %d del arreglo\n", mitad);
    else
        printf("el número solicitado no se encuentra en el arreglo");
}