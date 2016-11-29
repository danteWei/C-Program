#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamicArray.h"


/* Initiate a dynamic array */
int d_init(d_array_t *a)
{
	a->arr = (DT *) malloc(sizeof(DT));
	if (a->arr == NULL)
		return NOT_OK;
	a->capacity = 1;
	a->size = 0;
	return ALL_OK;
}

/* get data from the array at index */
int get(d_array_t *a, int index, DT *data)
{
	if (a == NULL || a->arr == NULL)
		return NOT_OK;
	if (index < 0 || index > a->size)
		return INDEX_OUT_OF_BOUND;
	*data = a->arr[index];
	return	ALL_OK;
}

/* remove and return an element from the array, element order may change */
int removeAt(d_array_t *a, int index, DT *ptr)
{
	if (a == NULL || a->arr == NULL)
		return NOT_OK;
	if (index < 0 || index > a->size)
		return INDEX_OUT_OF_BOUND;

	*ptr = a->arr[index];
	a->size--;
	if (index != a->size)
		a->arr[index] = a->arr[a->size];
	if (a->size <= (a->capacity / 4))
		resize(a, a->capacity / 2);
	return ALL_OK;
}

/* push an element to the end of the array */
int push(d_array_t *a, DT data)
{
	if (a == NULL || a->arr == NULL)
		return NOT_OK;
	if (a->capacity == 0)
		resize(a, 1);
	if (a->size == a->capacity)
		resize(a, a->capacity * 2);
	a->arr[a->size++] = data;
	return ALL_OK;
}

/* resize the array to newSize */
int resize(d_array_t *a, int newSize)
{
	if (a == NULL || a->arr == NULL)
		return NOT_OK;
	a->arr = realloc(a->arr, sizeof(DT) * newSize);
	if (a->arr == NULL)
		return NOT_OK;
	a->capacity = newSize;
	return ALL_OK;
}

/* clear all elements in the array */
int d_clear(d_array_t *a)
{
	if (a != NULL) {
		if (a->arr != NULL) {
			free(a->arr);
			a->arr = NULL;
		}
		a->capacity = 0;
		a->size = 0;
		return ALL_OK;
	}
	return NOT_OK;
}

int d_set(d_array_t *a, int index, DT data) {
	if (!(a && a->arr))
		return NOT_OK;
	if (index < 0 || index > a->size)
		return INDEX_OUT_OF_BOUND;
	(a->arr)[index] = data;
	return ALL_OK;
}
