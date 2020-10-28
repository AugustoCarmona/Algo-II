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