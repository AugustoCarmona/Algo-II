#include <stdio.h>
#include <stdbool.h>

int raiz(int dato, int sup);

int main() {
    int dato = 10;
    int cant_elementos = dato;

    printf("\nLa raíz cuadrada del número ingresado es: %i\n\n", raiz(dato, cant_elementos));

    return 0;
}

int raiz(int dato, int sup) {

    int inf = 0;
    bool bandera = false;
    int mitad;

    while ((inf <= sup) && (!bandera)) {
        mitad = (inf + sup) / 2;

        if ((mitad * mitad) <= dato && ((mitad + 1) * (mitad + 1)) > dato) bandera = true;
        
        if ((mitad * mitad) > dato) sup = mitad;
        
        if ((mitad * mitad) < dato) inf = mitad;
    }
    return mitad;
}

// La complegidad del algoritmo es O(log n). Según el teorema maestro la busqueda binaria (algoritmo en el cual basamos esta resolución) tiene una complegidad de este tipo por que realiza una iteracion sobre una de las mitades del arreglo.