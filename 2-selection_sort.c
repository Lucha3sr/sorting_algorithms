#include "sort.h"
/**
 * selection_sort - Function that sorts an array of integers in ascending order
 *
 * @array: pointer to array.
 * @size: size of array.
 *
 * Return: Nothing.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, temp;

	if (array == NULL || size < 2)
	{
		return;
	}

	/* Toma el primer valor y lo almacena en i */
	for (i = 0; i < size; i++)
	{
		/* toma el primer valor */
		for (j = i + 1; j < size; j++)
		{
			/* comparamos si posicion i es mayor a posicion i+1 */
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}