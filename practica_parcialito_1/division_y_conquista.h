/* 0:40:13
    Ejercicio 3 (17 de la guía): Implementar una función que utilice división y conquista de orden O(n log n) que dado un arreglo de n números devuelva true or false según existe algún elemento que aparezca más de la mitad de las veces. Justificar el orden de la solución.

    Ejemplos:
    [1,2,2,1,2,3] --> false
    [1,1,2,3] --> false
    [1,2,3,1,1,1] --> true
    [1] --> true

    Aclaración: Este ejercicio puede resolverse casi trivialmente, ordenando el arreglo con un algoritmo eficiente, o incluso se puede realizar más rápido utilizando una tabla de hash. Para hacer interesante este ejercicio, resolver sin ordenar el arreglo, sino pueramente división y conquista.


    Notas: si estamos muy perdidos puede ser una buena idea comenzar por un análisis del orden. No olvidar el teorema maestro. Merge Sort.
*/