def busqueda_binaria(arreglo, inicio, final, elemento):

	if final >= inicio: 
		mitad = (final + inicio) // 2

		if arreglo[mitad] == elemento: 
			return mitad 

		elif arreglo[mitad] > elemento: 
			return busqueda_binaria(arreglo, inicio, mitad - 1, elemento) 

		else: 
			return busqueda_binaria(arreglo, mitad + 1, final, elemento) 

	else: 
		return -1


def main():
    arreglo = [ 2, 3, 4, 10, 40 ] 
    elemento = 10

    resultado = busqueda_binaria(arreglo, 0, len(arreglo)-1, elemento) 

    if resultado != -1: 
    	print(f"El elemento que se busca esta presente en el arreglo en la posición {resultado}") 
    else: 
    	print("El elemento que se busca no esta presente en el arreglo") 

if __name__ == "__main__":
    main()