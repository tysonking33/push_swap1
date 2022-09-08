#include <stdio.h>
#include <stdlib.h>

void print_arrayAB(char *arrayA, int array_sizeA, char *array_nameA, char *arrayB, int array_sizeB, char *array_nameB){
	printf("\n-------------------------------------------------------------------------------\n");
	printf("\narray name: %s\n", array_nameA);
	for (int i=0; i< array_sizeA; i++){
		printf("%d ", arrayA[i]);
	}
	printf("\narray name: %s\n", array_nameB);
	for (int j=0; j< array_sizeB; j++){
		printf("%d ", arrayB[j]);
	}
	printf("\n-------------------------------------------------------------------------------\n");
}

void print_array(char *arrayA, int array_sizeA, char *array_nameA){
	printf("\n-------------------------------------------------------------------------------\n");
	printf("\narray name: %s\n", array_nameA);
	for (int i=0; i< array_sizeA; i++){
		printf("%d ", arrayA[i]);
	}
	printf("\n-------------------------------------------------------------------------------\n");
}
/*
int main(){
	char *A = (char *)malloc(5*sizeof(char));
	A[0] = -3;
	A[1] = -79;
	A[2] = 19;
	A[3] = -7;
	A[4] = -42;
	print_array(A, 5, "A");
	return 0;
}*/
