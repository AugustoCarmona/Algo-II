# Algoritmos de División y Conquista
----
## Quick Sort (caso de estudio en lenguaje C)

### Concepto:

El algoritmo de ordenamiento Quick Sort recurre a la implementación de un pivote para realizar contra este la comparación del resto de los elementos.

Teniendo como caso base un arreglo de un único elemento, se toma un componente al azar (aunque lo recomendado es tomar el elemento del medio para evitar el peor caso del algotimo, que es cuando el arreglo ya se encuentra ordenado) y se itera a lo largo de los demás valores, colocando a cada paso el valor **en uno** de dos nuevos arreglos (los valores que irán a la **izquierda del pivote, es decir los menores** a este; y los que irán a su **derecha, es decir los mayores**.
Los elementos que sean iguales será indistinto a donde se posicionen).

De este forma se llegara al caso base para cada elemento, siendo que este ya estará en la posición del vector que le corresponda, por lo que solo quedará concatenar.

### Implementación

La implementación del algoritmo de quicksort consiste en los siguientes pasos.

Necesitamos un vector a ordenar, así como la cantidad de elementos que este tendrá ya que las llamadas al algoritmo recibirán tres parámetros: el vector en sí, una posición de inicio de iteración y una posición de final de esta.

El caso de estudio en el lenguaje C requiere que obtengamos la cantidad de elementos de este vector dividiendo: la cantidad de bytes que ocupa el arreglo por la cantidad de bytes que ocupa el tipo de dato que este arreglo contiene.

````C
size_t cant_elementos = sizeof(arreglo)/sizeof(tipo_dato);
````

Llamados a la función recursiva:

Caso base:
Todo algoritmo recursivo necesita un caso base que será el que indique cuando debe frenarse el algoritmo. En el caso de los algoritmos de ordenamiento este caso base será cuando el la cantidad de elementos en el arreglo sea igual a 1. Por definición un arreglo con un solo elemento o ninguno ya se encuentra ordenado.

Si la posición de final menos la de incio del arreglo da como reltado cualquier cosa menor a dos, el arreglo solo puede tener uno o ningun elementos.

Procedimiento:
Lo primero que necesitamos es tomar un elemento como **pivote** y otro que se llamara **ultimo elemento menor**. Ambos iniciarán en la posicion de inicio:

````C
int pivote = inicio;
int ult_menor = inicio;
````    

y un **punto medio**:

````C
int punto_medio = (posicion_inicio + posicion_final) / 2;
````

y luego intercambiaremos con ayuda de alguna función auxiliar los valores de dicho **punto medio** y el **pivote**. Este es un proceso de optimización para el caso en que nuestro areglo original ya se encuentre ordenado.

Es entonces cuando comienza la iteración.
Iteraremos con un incremento de una unidad, desde el valor del pivote más 1, hasta el final del arreglo, y cada vez que el vector evaluado en la **posición en la que nos encontramos** sea **menor** al valor del vector evaluado en el pivote, intercamiaremos la **posición** en la que nos encontramos con el **último elemento menor** que tengamos, luego de incrementar en una unidad el valor de este último.

Cuando se termine esta itración intercambiaremos el pivote con el último elemento menor. Esto colocará el pivote al final de los menores y con el ultimo menor en el primer lugar. Es decir que ese pivote ya estará ordenado.

Por útimo haremos dos llamadas recursivas, una de las llamadas tomará el incio del arreglo original y el ultimo elemento menor como final, y la otra tomará el último elemento menor más 1 como incio, y el final del arreglo original como final en sí.

> Nota: es importante tener en cuenta que la función de intercambio original no debe intercambiar las posiciones, si no los valores del vector en dichas posiciones.Nota: es importante tener en cuenta que la función de intercambio original no debe intercambiar las posiciones, si no los valores del vector en dichas posiciones.

<center>
    <img src="https://upload.wikimedia.org/wikipedia/commons/6/6a/Sorting_quicksort_anim.gif" />
    </a>
</center>

> Nota 2: el caso de estudio se tomó de los ejemplos de código de la profesora Margarita Manterola y el profesor Maximiliano Curia en el drive de la materia Algoritmos II "Cátedra Buchwald".

----
## Merge Sort (caso de estudio en lenguaje C)


### Concepto:

El algoritmo de Merge Sort consiste en la implementación de un ordenamiento por mitades.

La premisa es simple, partimos el arreglo a ordenar por la mitad, ordenamos sus mitades, y una vez ordenadas sus mitades las intercalamos también de forma ordenada.

Para esto va a ser necesario llegar al caso base, recordemos cualquier arreglo de largo menor o igual a uno por definición va a estar ordenado, para luego comenzar a intercalar con los elementos previamente particionados.

### Implementación
---

## Binary Search (caso de estudio en lenguaje C)

### Concepto:



---