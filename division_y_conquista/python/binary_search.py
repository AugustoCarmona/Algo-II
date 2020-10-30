#implementacion iterativa

def busqueda_binaria(arreglo, elemento):
	encontrado = False
	inicio = 0
	fin = len(arreglo)

	while inicio <= fin and not encontrado:
		mitad = (inicio + fin) // 2

		if arreglo[mitad] == elemento:
			encontrado = True

		if arreglo[mitad] > elemento:
			fin = mitad

		if arreglo[mitad] < elemento:
			inicio = mitad

	if encontrado:
		print(f"el elemento solicitado se encontró en la posición {mitad} del arreglo")
	else:
		print("el elemento solicitado no se encuentra en el arreglo")

def main():
	arreglo = [1,2,3,4,5,6,7,8,9] 
	elemento = 7

	busqueda_binaria(arreglo, elemento)

if __name__ == "__main__":
    main()