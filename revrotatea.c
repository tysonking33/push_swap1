/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotatea.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:13:06 by tytang            #+#    #+#             */
/*   Updated: 2022/08/30 18:56:47 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char *revrotateA(char *unsorted_array, int array_size)
{
	if (array_size > 1)
	{
		char *output_array = (char *)malloc(array_size*(sizeof(char)));
		int unsorted_array_ctr = 1;
		output_array[0] = unsorted_array[array_size - 1];
		while (unsorted_array_ctr < array_size)
		{
			output_array[unsorted_array_ctr] = unsorted_array[unsorted_array_ctr - 1];
			unsorted_array_ctr++;
		}
		/*for (int i=0; i < array_size; i++){
			printf("%d ", output_array[i]);
		}
		printf("\n\n\n\n");*/
		return (output_array);
	}
	return (unsorted_array);

}
/*
int main(){
	{
		char *arrayA;
		arrayA = (char *)malloc(5 *sizeof(char));
		arrayA[0] = 1;
		arrayA[1] = 2;
		arrayA[2] = 3;
		arrayA[3] = 4;
		arrayA[4] = 5;
		
		for (int i=0; i < 5; i++){
			printf("%d ", arrayA[i]);
		}
		printf("\n");
		arrayA = revrotateA(arrayA, 5);

		for (int i=0; i < 5; i++){
			printf("%d ", arrayA[i]);
		}
	}
	printf("\n\n");
	{
		char *arrayA = (char *)malloc(5 *sizeof(char));
		arrayA[0] = 4;
		arrayA[1] = 20;
		arrayA[2] = 8;
		arrayA[3] = 4;
		arrayA[4] = 5;
		for (int i=0; i < 5; i++){
			printf("%d ", arrayA[i]);
		}
		printf("\n");
		arrayA = revrotateA(arrayA, 5);

		for (int i=0; i < 5; i++){
			printf("%d ", arrayA[i]);
		}
	}
	printf("\n\n");
	{
		char *arrayA = (char *)malloc(5 *sizeof(char));
		arrayA[0] = 5;
		arrayA[1] = 8;
		arrayA[2] = 20;
		arrayA[3] = 1;
		arrayA[4] = 0;
		for (int i=0; i < 5; i++){
			printf("%d ", arrayA[i]);
		}
		printf("\n");
		arrayA = revrotateA(arrayA, 5);

		for (int i=0; i < 5; i++){
			printf("%d ", arrayA[i]);
		}
	}
	printf("\n\n");
	{
		char *arrayA = (char *)malloc(5 *sizeof(char));
		arrayA[0] = 5;
		arrayA[1] = 20;
		arrayA[2] = 3;
		arrayA[3] = 50;
		arrayA[4] = 1;
		for (int i=0; i < 5; i++){
			printf("%d ", arrayA[i]);
		}
		printf("\n");
		arrayA = revrotateA(arrayA, 5);

		for (int i=0; i < 5; i++){
			printf("%d ", arrayA[i]);
		}
	}
	return (0);
}*/
