/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:23:42 by tytang            #+#    #+#             */
/*   Updated: 2022/09/05 11:03:54 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char *swapA(char *unsorted_arrayA, int array_size)
{
	//printf("\n\n\n\narrayA size: %d\n\n\n", array_size);
	
	if (array_size > 1)
	{
		char *output_array = (char *)malloc(array_size*(sizeof(char)));
		output_array[0] = unsorted_arrayA[1];
		output_array[1] = unsorted_arrayA[0];
		int output_array_ctr = 2;
		while(output_array_ctr < array_size)
		{
			output_array[output_array_ctr] = unsorted_arrayA[output_array_ctr];
			output_array_ctr++;	
		}
		/*for (int i=0; i < array_size; i++){
			printf("%d ", output_array[i]);
		}*/
		return (output_array);
	}
	else 
	{
		printf("not enough arguements");
	}
	return (unsorted_arrayA);
}
/*
int main(){
	{
		char *A = (char *)malloc(3*sizeof(char));
		A[0] = 30;
		A[1] = 94;
		A[2] = 82;
		A= swapA(A, 3);
		for (int i =0; i < 3; i++){
			printf("%d ", A[i]);
		}
		//printf("\n working\n");
	}
	printf("\n");
	{
		char *A = (char *)malloc(3*sizeof(char));
		A[0] = 41;
		A[1] = 91;
		A[2] = 90;
		A= swapA(A, 3);
		for (int i =0; i < 3; i++){
			printf("%d ", A[i]);
		}
		//printf("\n working\n");
	}
	printf("\n");
	{
		char *A = (char *)malloc(3*sizeof(char));
		A[0] = 24;
		A[1] = -40;
		A[2] = -6;
		A= swapA(A, 3);
		for (int i =0; i < 3; i++){
			printf("%d ", A[i]);
		}
		//printf("\n working\n");
	}
	printf("\n");
	return (0);
}*/
