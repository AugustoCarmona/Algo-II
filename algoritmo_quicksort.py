def quick_sort(lista):

    largo = len(lista)

    if largo <= 1:
        return lista
    else:
        pivot = lista.pop()
    
    mayores = []
    menores = []

    for numero in lista:
        if numero > pivot:
            mayores.append(numero)
        else:
            menores.append(numero)
    
    return quick_sort(menores) + [pivot] + quick_sort(mayores)

lista = [273,9,4,83,7,29,2,0,2,46,8,4,47,3,91,1,1,0,2,93,3,8,7,3,87,4,663,2]
print(quick_sort(lista))

"""
consola: [0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 7, 7, 8, 8, 9, 29, 46, 47, 83, 87, 91, 93, 273, 663]

El algoritmo de ordenamiento Quick Sort consiste en el caso base de que el arreglo a ordenar tenga un largo mayor a uno
(por definicion un arreglo de un unico elemento ya esta ordenado); y un caso recursivo en el que extraemos un elemento
cualquiera el cual funcionara como pivot, para luego iterar en dicho arreglo y ubicar cada elemento en una lista distinta:
sea mayor o menor. Por ultimo retornamos cada una de estas listas en un llamado a la misma funcion de ordenar, pero, concatenadas
con el pivot entre ellas dos para no perder ningun elemento.
"""