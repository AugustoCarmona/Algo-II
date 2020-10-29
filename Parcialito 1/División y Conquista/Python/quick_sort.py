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