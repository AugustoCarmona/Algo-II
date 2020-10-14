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
consola: 4

esto fue casi un copy paste y la verdad que no entiendo bien como funciona, asi que me voy a comer, quiza despues me vea un cap
de friends y mas tarde actualizo bien la descripcion de este algoritmo por que ahora tengo paja
"""