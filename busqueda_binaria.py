#metodo recursivo
def busqueda_binaria(arreglo, elemento, inicio):
    final = len(arreglo)
    punto_medio = inicio - final % 2

    if arreglo[punto_medio] == elemento:
        return punto_medio
    elif arreglo[punto_medio] > elemento:
        final = punto_medio - 1
        return busqueda_binaria(arreglo[:final], elemento, inicio)
    else:
        inicio = punto_medio + 1
        return busqueda_binaria(arreglo[inicio:], elemento, inicio)

def main():
    arreglo = [1,2,3,4,5,6,7,8,9] #debe devolver 6
    elemento = 7
    inicio = 0
    print(busqueda_binaria(arreglo, elemento, inicio))

main()

"""
LA REPUTA QUE LOS RE PARIO NO ME SALE RECURSIVO
"""

"""
consola: 4

El objetivo de la busqueda binaria es (dado un arreglo ordenado), identificar si un elemento dado pertenece a este arreglo,
devolviendo la posicion del mismo en caso de pertenecer, o devolviendo None en caso de no pertenecer.
Procedimiento:
Una vez se tiene el largo del arreglo, se divide a este a la mitad y se toma dicha mitad como punto de comparacion.
Si esta mitad es el elemento que estamos buscando, entonces este ya fue encontrado; si no, si esta mitad es mas grande,
significa que el elemento que buscamos es mas chico y necesitamos seguir iterando la mitad de la izquiera de nuestro elemento
"pivot".
Si es mas chico, entonces el elemento que buscamos esta a su derecha.
La idea es seguir iterando hasta que el valor de nuestro punto medio sea el del elemento que buscamos o hayamos recorrido toda
la lista.


#metodo iterativo
def busqueda_binaria(lista, elemento):
    index_inicio = 0
    index_final = len(lista) - 1

    while index_inicio <= index_final:
        punto_medio = index_inicio + (index_final - index_inicio) // 2
        valor_puto_medio = lista[punto_medio]

        if valor_puto_medio == elemento:
            return punto_medio
        
        elif elemento < valor_puto_medio:
            index_final = punto_medio - 1
        
        else:
            index_inicio = punto_medio + 1

    return None

lista = [1,3,4,6,7,8,9]
elemento = 7
print(busqueda_binaria(lista, elemento))
"""