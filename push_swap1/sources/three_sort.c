#include "../includes/pushswap.h"


void	small_med_large(t_arrays *array)
{
	if ((array->a[2] > array->a[1]) && (array->a[2] > array->a[0]))
		rotatea(array);
	else if ((array->a[1] > array->a[2]) && (array->a[1] > array->a[0]))
		revrotatea(array);
	else if ((array->a[1] > array->a[2]) && (array->a[1] < array->a[0]))
		swapa(array);
	else if ((array->a[2] > array->a[1]) && (array->a[1] < array->a[0]) && (array->a[2] < array->a[0]))
		swapa(array);
	if (array->a[2] > array->a[1])
		swapa(array);
}
