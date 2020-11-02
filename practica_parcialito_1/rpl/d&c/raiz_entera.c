#include <stdio.h>

size_t raiz_entera(size_t n) {
    
    size_t inicio = 0, fin = n;

    while (inicio < fin) {
        size_t mitad = (inicio + fin) / 2;

        if ( (mitad * mitad <= n) && ((mitad + 1)*(mitad + 1) > n) )
            return mitad;
        
        if (mitad * mitad > n)
            fin = mitad;
        
        else if (mitad * mitad < n)
            inicio = mitad;
    }
}

int main() {
    size_t n = 10;
    printf("\n\nLa raíz cuadrada del número ingresado es: %ld\n", raiz_entera(n));
    raiz_entera(n);
    
    return 0;
}


// Implementar un algoritmo que, por división y conquista, permita obtener la parte entera de la raíz cuadrada de un número, en tiempo O(log n)
// Por ejemplo, para  n = 10, debe devolver 3, y para n = 25 debe devolver 5
// Para poder lograr un tiempo O(log n) puedo basarme en el algoritmo de busqueda binaria.

/*
Siendo n la cantidad de numeros enteros tales que n <= valor_ingresado. Utilizando el Teorema Maestro:

A = 1 (ya que siempre se llama solo a una de las mitades de la funcion)
B = 2 (ya el se dividió el arreglo en 2)
C = 0 (ya que todas las operaciones internad son constantes)

log b (a) = c => O(n^c log (n))= O(log(n))
*/