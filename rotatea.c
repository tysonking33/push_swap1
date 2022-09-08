/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotatea.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:24:39 by tytang            #+#    #+#             */
/*   Updated: 2022/08/30 18:56:37 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char *rotateA(char *unsorted_array, int array_size)
{
	if (array_size > 1)
	{
		char *output_array = (char *)malloc(array_size*(sizeof(char)));
		int unsorted_array_ctr = 0;
		while (unsorted_array_ctr < array_size)
		{
			output_array[unsorted_array_ctr] = unsorted_array[unsorted_array_ctr + 1];
			unsorted_array_ctr++;
		}
		output_array[array_size - 1] = unsorted_array[0];
			
		return (output_array);
	}
	return (unsorted_array);
}
/*
int main(){
	char arrayA[5] = {1,2,3,4,5};
	char *newarray = (char *)malloc(5 *sizeof(char));

	rotateA(arrayA, 5);

	for (int i=0; i < 5; i++){
		printf("%d ", arrayA[i]);
	}
	return (0);
	
}*/
