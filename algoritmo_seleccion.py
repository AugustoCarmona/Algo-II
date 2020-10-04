def algoritmo_de_seleccion(lista):
    largo_de_indexacion = range(0, len(lista) - 1) #utilizamos un menos 1 por que cuando nos encontremos en el ultimo elemento de la lista ya no necesitaremos comparar

    for i in largo_de_indexacion:
        minimo = i #minimo por default

        for j in range(i+1, len(lista)): #i+1, es decir, los elementos a la derecha del minimo
            if lista[j] < lista[minimo]:
                minimo = j #se establece un nuevo minimo cada vez que este numero a la derecha es menor ue el minimo previamente establecido

        if minimo != i:
            lista[minimo], lista[i] = lista[i], lista[minimo] #cuando se termina el for interno se realiza un swap

    return lista

print(algoritmo_de_seleccion( [4,5,8,6,4,2,1,0,7,5,3,4,6,77,8,3,22,11] ))

"""
consola: [0, 1, 2, 3, 3, 4, 4, 4, 5, 5, 6, 6, 7, 8, 8, 11, 22, 77]

El algoritmo de ordenamieto por seleccion consiste en iterar un arreglo y establecer el primer elemento "minimo".
A medida que procedemos en la iteracion, entonces, debemos comparar ese "minimo" con el número a su derecha. Si el número a su derecha es más pequeño,
este pasará a ser el "minimo".
Al finalizar el recorrido enntonces se dividirá el arreglo con, los numeros ordenados a la izquierda del "minimo" y los desordenado, los cuales volveremos
a iterar a su derecha.
"""