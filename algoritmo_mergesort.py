def merge(lista, inicio, medio, fin):
    I = lista[inicio:medio]
    D = lista[medio:fin+1]
    I.append(999999999)
    D.append(999999999)
    i = j = 0

    for k in range(inicio, fin+1):
        if I[i] <= D[j]:
            lista[k] = I[i]
            i += 1
        else:
            lista[k] = D[j]
            j += 1

def ordenar(lista, inicio, fin):
    if inicio < fin:
        medio = inicio + fin // 2
        ordenar(lista, inicio, medio)
        ordenar(lista, medio+1, fin)
        merge(lista, inicio, medio, fin)

def merge_sort(lista):
    largo = len(lista)
    ordenar(lista, 0, largo - 1)

lista = [10,5,2,7,4,9,12,1,8,6,11,3]
print(merge_sort(lista))

"""
Este algoritmo consiste en el ordenamiento de las mitades, y la mejor forma de encararlo es recursivamente.
Lo mejor que podemos hacer es  partir nuestro arreglo a la mitad, y luego acoplar esas mitades de manera recursiva
"""