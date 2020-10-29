def quick_sort(arreglo):
    
    if len(arreglo) <= 1: #caso base
        return arreglo

    pivot = [arreglo.pop(0)]
    mayores = []
    menores = []

    for i in range(0, len(arreglo)):
        if arreglo[i] > pivot[0]:
            mayores.append(arreglo[i])
        else:
            menores.append(arreglo[i])

    return quick_sort(menores) + pivot + quick_sort(mayores)

def main():
    arreglo = [4,10,8,7,6,5,3,12,14,2]
    arreglo = quick_sort(arreglo)
    print(arreglo)

if __name__ == "__main__":
    main()

"""
Quick sort es un método de ordenamiento que consiste en tomar un elemento como pivot de una lista desordenada
y ubicar todos los elementos mayores que el de la lista a su derecha y los menores a la izquierda.
Así quick sort ubica cada elemento en su lugar, llamando a la misma funció tanto en la lista de la izquierda
y de la derecha recursivamente hasta que cada elemento este ordenado.

Todas las funciones recursivas necesitan un caso base que se resolverá sin llamar a la funcíon principal.
En este caso consideraremos como caso base ccuando la funcion reciba una lista de un elemento o vacía (ya que estará
ordenada por definicial inicio < fin)

Podemos necesitar un módulo para ubicar el pivote: 
"""