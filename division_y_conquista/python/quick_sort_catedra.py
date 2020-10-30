# Resolucion para el lenguaje de programacion Python

def quick_sort(arreglo):

    largo = len(arreglo) # caso base
    if largo <= 1:
        return arreglo
    
    pivot = arreglo.pop(len(arreglo) // 2) # por optimización conviene tomar un valor del medio en caso de que el arreglo ya se encuentre ordenado
    mayores = []
    menores = []

    for i in range(0, largo - 1):
        if arreglo[i] > pivot:
            mayores.append(arreglo[i])
        else:
            menores.append(arreglo[i])

    return quick_sort(menores) + [pivot] + quick_sort(mayores) # dos llamadas recursivas

def main():
    arreglo = [4,10,8,7,6,5,3,12,14,2]
    
    print("### QUICK SORT ###")
    print(f"{arreglo} --> arreglo desorenado")
    print(f"{quick_sort(arreglo)} --> arreglo ordenado")

if __name__ == "__main__":
    main()