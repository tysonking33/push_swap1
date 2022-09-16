#include "../includes/pushswap.h"

int *bubble_sort(t_arrays *array)
{
	int *temp_arr = (int *)malloc(((array->a_size) + 1)*sizeof(int *));
	int temp = 0;

	int temp_ctr_extern = 0;
	int temp_ctr_intern = 0;
	for (int i = 0; i <= array->a_size; i++)
	{
		temp_arr[i] = array->a[i];
	}

	while (temp_ctr_extern < array->a_size)
	{
		temp_ctr_intern = 0;
		while (temp_ctr_intern < array->a_size)
		{
			if (temp_arr[temp_ctr_intern] < temp_arr[temp_ctr_intern + 1])
			{
				temp = temp_arr[temp_ctr_intern + 1];
				temp_arr[temp_ctr_intern + 1] = temp_arr[temp_ctr_intern];
				temp_arr[temp_ctr_intern] = temp;
			}
			temp_ctr_intern++;
		}
		temp_ctr_extern++;
	}
	return temp_arr;
}

/*void	large_sort(t_arrays *array)
{
	int array_a_size = array->a_size;
	int bb_sort_ctr;
	for (int i = 0; i <= array->a_size - 1; i++){
		//printf("bubble sort array[%d] = %d\n", i, array->bubble_sort_arr[i]);
		bb_sort_ctr = 0;
		while (array->bubble_sort_arr[i] != array->a[bb_sort_ctr])
		{
			bb_sort_ctr++;
		}
		//printf("bb_sort_ctr: %d\n", bb_sort_ctr);
		if (bb_sort_ctr > (array->a_size)/2)
		{
			while(array->a[array->a_size] != array->bubble_sort_arr[i])
				rotatea(array);
		}
		else if (bb_sort_ctr <= (array->a_size)/2)
		{
			while(array->a[array->a_size] != array->bubble_sort_arr[i])
				revrotatea(array);
		}
		pb(array);
	}
	small_med_large(array);
	for (int j = 0; j <= array_a_size - (array->a_size - 1); j++)
		pa(array);
}*/

void btop_more_than_abot(t_arrays *array)
{
	printf("more_than\n");
	pa(array);
	rotatea(array);
}

void btop_less_than_abot(t_arrays *array)
{
	printf("less_than\n");
	while (array->a[0] > array->b[array->b_size])
		revrotatea(array);
	pa(array);
	while (array->a[array->a_size] > array->a[0])
		rotatea(array);
}

void	large_sort(t_arrays *array)
{
	//finding location of smallest number
	int small_loc;
	small_loc = 0;

	while (array->a[small_loc] != array->bubble_sort_arr[array->a_size])
		small_loc++;
	printf("small_loc: %d\n", small_loc);

	//pushing the smallest number to the bottom
	int counter = 0;
	if ((small_loc > array->a_size / 2) && (array->a[0] != array->bubble_sort_arr[array->a_size]))
	{
		while (counter <= array->a_size - small_loc)
		{
			rotatea(array);
			counter++;
		}
	}
	else if ((small_loc <= array->a_size / 2) && (array->a[0] != array->bubble_sort_arr[array->a_size]))
	{
		while (counter < small_loc)
		{
			revrotatea(array);
			counter++;
		}
	}
	printf("--------------------------------------------------------------------------------------------\n");
	int array_a_size = array->a_size;
	for (int i = 0; i < array_a_size; i++){
		//find postion of the element in array bubble sort
		int bb_loc = 0;
		while (array->a[array->a_size] != array->bubble_sort_arr[bb_loc])
			bb_loc++;
		//find position of the element, in array a
		int ele_loc = 0;
		while (array->a[ele_loc] != array->bubble_sort_arr[bb_loc])
			ele_loc++;
		printf("bb_loc: %d, ele_loc: %d\n", bb_loc, ele_loc);
		if ((array->a[array->a_size] > array->a[0]) && (bb_loc > (3*array->a_size / 4)))
			rotatea(array);
		else 
			pb(array);
		//else
		//	rotatea(array);
	}
	printf("*********************************************************************************************\n");
	//int array_b_size = array->b_size;
	while (check_sorted(array) != 1 && array->b_size >= 0)
	{
		if (array->b[array->b_size] > array->a[0] && array->b_size >= 0)
			btop_more_than_abot(array);
		else if(array->b[array->b_size] < array->a[0] && array->b_size >= 0)
			btop_less_than_abot(array);
	}
		

}
