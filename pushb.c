#include <stdio.h>
#include <stdlib.h>
void print_array(char *array, int array_size, char *array_name);

void pushB(char *unsorted_arrayA, char *unsorted_arrayB, int *array_sizeA, int *array_sizeB){
	char *temp_b = (char *)malloc((*array_sizeB) *sizeof(char));
	for (int i = 0; i < *array_sizeB; i++){
		temp_b[i] = unsorted_arrayB[i];
	}
	unsorted_arrayB[0] = unsorted_arrayA[0];
	for (int j = 0; j < *array_sizeB; j++){
		unsorted_arrayB[j+1] = temp_b[j];
	}
	char *temp_a = (char *)malloc((*array_sizeA) *sizeof(char));
	for (int a = 0; a < *array_sizeA; a++){
		temp_a[a] = unsorted_arrayA[a];
	}
	int a = 0;
	for (a = 0; a < *array_sizeA; a++){
		unsorted_arrayA[a] = temp_a[a+1];
	}
	unsorted_arrayA[a] = 0;
	*array_sizeA = *array_sizeA - 1;
	*array_sizeB = *array_sizeB + 1;
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
	pushB(A, B, array_a_ptr, array_b_ptr);
	print_array(A, array_A, "A");
	print_array(B, array_B, "B");
	printf("\n array_A size: %d\n", array_A);
	printf("\n array_B size: %d\n", array_B);
	return 0;
}*/
