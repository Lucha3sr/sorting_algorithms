#include "sort.h"
/*
*						  p3
*		array = [4,1,6,   7,    5,2,3]
*
*		izq = indice 0
*		der = indice n-1
*		pivote = (len(array) - 1) / 2 > pivote = 3
*		temporal;
*
*		mientras izq sea menor que der:
*			izq > a pivote ? mover a la derecha : sino, no hacer nada
*			der < a pivote ? mover a la izquierda: sino, no hacer nada
*
*		+4 > 7 ? > entonces no hacer nada
*		-3 < 7 ? entonces mover a la izquierda
*		array = [4,1,6, 3, 7,5,2]
*		+1 > 3 ? > entonces no hacer nada
*		-2 < 3 ? entonces mover a la izquierda
*		array = [4,1,6, 2, 3,7,5]
*		+6 > 2 ? entonces mover derecha
*		array = [4,1,2, 6, 3,7,5]
*		-5 < 6 ? entonces mover a la izquierda
*		array = [4,1,2, 5, 6,3,7]
*		+4 > 5 ? entonces no hacer nada
*		-7 < 5 ? entonces no hacer nada
*		+1 > 5 ? entonces no hacer nada
*		-3 < 5 ? entonces mover a la derecha
*		array = [4,1,2, 3, 5,6,7]
*		+4 > 3 ? si, entonces mover derecha
*		array = [1,2,3,4,5,6,7]
**/



/**
 * _proyecto_lu_niko - ordena perfectamente una array, de forma increible.
 * @array: list to sort
 * @limite_izq: left limit of list
 * @limite_der: right limit of list
 **/
void _proyecto_lu_niko(int *array, int limite_izq, int limite_der)
{
	int izq     = limite_izq;
	int der     = limite_der;
	int pivot   = array[(izq + der) / 2];
	int temp;

	do {
		while (array[izq] < pivot && izq < limite_der)
			izq++;
		while (pivot < array[der] && der > limite_izq)
			der--;

		if (izq <= der)
		{
			temp = array[izq];
			array[izq] = array[der];
			array[der] = temp;
			izq++;
			der--;
		}

	} while (izq <= der);

	if (limite_izq < der)
		_proyecto_lu_niko(array, limite_izq, der);
	if (limite_der > izq)
		_proyecto_lu_niko(array, izq, limite_der);
}

/**
 * quick_sort - sort array using quick sort algorithm
 * @array: array
 * @size: array size
 **/
void quick_sort(int *array, size_t size)
{

	if (array == NULL || size < 2)
		return;

	int limite_izq = 0;
	int limite_der = size - 1;

	_proyecto_lu_niko(array, limite_izq, limite_der);

}