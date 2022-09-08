/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusha.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tytang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 12:37:15 by tytang            #+#    #+#             */
/*   Updated: 2022/08/29 11:34:43 by tytang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
void print_array(char *array, int array_size, char *array_name);

void pushA(char *unsorted_arrayA, char *unsorted_arrayB, int *array_sizeA, int *array_sizeB){
	char *temp_a = (char *)malloc((*array_sizeA) *sizeof(char));
	for (int i = 0; i < *array_sizeA; i++){
		temp_a[i] = unsorted_arrayA[i];
	}
	unsorted_arrayA[0] = unsorted_arrayB[0];
	for (int j = 0; j < *array_sizeA; j++){
		unsorted_arrayA[j+1] = temp_a[j];
	}
	char *temp_b = (char *)malloc((*array_sizeB) *sizeof(char));
	for (int a = 0; a < *array_sizeB; a++){
		temp_b[a] = unsorted_arrayB[a];
	}
	int b = 0;
	for (b = 0; b < *array_sizeB; b++){
		unsorted_arrayB[b] = temp_b[b+1];
	}
	unsorted_arrayB[b] = 0;
	*array_sizeA = *array_sizeA + 1;
	*array_sizeB = *array_sizeB - 1;
}
/*
int main(){
	int array_A = 10;
	int array_B = 10;
	int *array_a_ptr = &array_A;
	int *array_b_ptr = &array_B;
	char *A = (char *)malloc((array_A)*sizeof(char));
	A[0] = 0;
	A[1]= 1;
	A[2] = 2;
	A[3] = 3;
	char *B = (char *)malloc((array_B)*sizeof(char));
	B[0] = 10;
	B[1] = 20;
	B[2] = 30;
	B[3] = 40;
	printf("\n array_A size: %d\n", array_A);
	printf("\n array_B size: %d\n", array_B);
	print_array(A, array_A, "A");
	print_array(B, array_B, "B");
	pushA(A, B, array_a_ptr, array_b_ptr);
	print_array(A, array_A, "A");
	print_array(B, array_B, "B");
	printf("\n array_A size: %d\n", array_A);
	printf("\n array_B size: %d\n", array_B);
	return 0;
}*/
