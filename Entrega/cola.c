#include "cola.h"
#include <stdlib.h>

typedef struct nodo {
	void* dato;
	struct nodo* prox;
} nodo_t;

/*******************************************************************
 *			PRIMITIVAS DEL NODO
 *******************************************************************/

nodo_t* nodo_crear(void* valor) {
	nodo_t* nodo = malloc(sizeof(nodo_t));
	if (!nodo) return NULL;

	nodo->dato = valor;
	nodo->prox = NULL;

	return nodo;
}

//definicion del struct cola

struct cola {
	nodo_t* prim;
	nodo_t* ult;
};

/*******************************************************************
 *			PRIMITIVAS DE LA COLA
 *******************************************************************/

cola_t *cola_crear(void) {
	cola_t *cola = malloc(sizeof(cola_t));
	if (!cola) return NULL;

	cola->prim = cola->ult = NULL;
	return cola;
}

void cola_destruir(cola_t *cola, void (*destruir_dato)(void *)) {
	while (!cola_esta_vacia(cola)) {
		void* dato = cola_desencolar(cola); //la funcion desencolar SIEMPRE destruye el nodo y devuelve el dato
		if (destruir_dato) destruir_dato(dato); //destruir dato le explica a la primitiva que debe hacer con dicho dato, pero el nodo ya ESTA DESTRUIDO
	} free(cola);
}

bool cola_esta_vacia(const cola_t *cola) {
	return !cola->prim; //si cola->prim == NULL es cero (false), yo lo que busco es que sea falso cuando la cola NO ESTA vacia, es por eso que debo negarlo
}

bool cola_encolar(cola_t *cola, void *valor) {
	nodo_t *nodo = nodo_crear(valor);
	if (!nodo) return false;
	
	if (cola_esta_vacia(cola)) cola->prim = nodo;
	else cola->ult->prox = nodo;

	cola->ult = nodo;
	return true;
}

void *cola_ver_primero(const cola_t *cola) {
	return (!cola_esta_vacia(cola)) ? cola->prim->dato : NULL;
}

void *cola_desencolar(cola_t *cola) {
	if (cola_esta_vacia(cola)) return NULL;
	
	nodo_t* nodo_a_destruir = cola->prim;
	void* dato_a_devolver = cola->prim->dato;

	cola->prim = cola->prim->prox; //asigno como primero al nodo proximo al que voy a desencolar para que la cola no quede acefala
	if (cola->ult == nodo_a_destruir) cola->ult = cola->prim; //si el ultimo nodo de la cola es igual al nuevo "primer dato" entonces solo queda un nodo

	free(nodo_a_destruir);
	return dato_a_devolver;
}
