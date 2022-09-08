#include <stdio.h>
#include <stdlib.h>

void pushA(char *unsorted_arrayA, char *unsorted_arrayB, int *array_sizeA, int *array_sizeB);				//adjust to alter both arrays, and both array sizes
void pushB(char *unsorted_arrayA, char *unsorted_arrayB, int *array_sizeA, int *array_sizeB);				//adjust to alter both arrays, and both array sizes
char *revrotateA(char *unsorted_array, int array_size);
char *rotateA(char *unsorted_array, int array_size);
char *swapA(char *unsorted_arrayA, int array_size);
//void swapB(char *unsorted_arrayB, int array_size);
void print_array(char *array, int array_size, char *array_name);
void print_arrayAB(char *arrayA, int array_sizeA, char *array_nameA, char *arrayB, int array_sizeB, char *array_nameB);
void print_array(char *arrayA, int array_sizeA, char *array_nameA);



char *rev_three_number_sort(char *unsorted_arrayA, int array_size){
	char *new_array = (char *)malloc(array_size*sizeof(char));
	if ((unsorted_arrayA[1] > unsorted_arrayA[2]) && (unsorted_arrayA[0] > unsorted_arrayA[2])){
		new_array = unsorted_arrayA;
		if (new_array[0] >  new_array[1]){
			new_array = swapA(new_array, array_size);
			print_array(unsorted_arrayA, array_size, "swapA");
		}
		return new_array;
	}
	if ((unsorted_arrayA[0] < unsorted_arrayA[1]) && (unsorted_arrayA[0] < unsorted_arrayA[2])){
		new_array = rotateA(unsorted_arrayA, array_size);
		print_array(unsorted_arrayA, array_size, "rotateA");
	}	
	else if((unsorted_arrayA[1] < unsorted_arrayA[0]) && (unsorted_arrayA[1] < unsorted_arrayA[2])){
		new_array = revrotateA(unsorted_arrayA, array_size);
		print_array(unsorted_arrayA, array_size, "revrotateA");
	}
	if (new_array[0] < new_array[1]){
		new_array = swapA(new_array, array_size);
		print_array(unsorted_arrayA, array_size, "swapA");
	}
	return new_array;
}

char *large_small_med(char *unsorted_arrayA, int array_size){
	char *new_array = (char *)malloc(array_size*sizeof(char));
	if ((unsorted_arrayA[0] < unsorted_arrayA[1]) && (unsorted_arrayA[1] < unsorted_arrayA[2]) && (unsorted_arrayA[0] < unsorted_arrayA[2])){
		//1,2,3
		new_array = revrotateA(unsorted_arrayA, array_size);
		print_array(new_array, array_size, "revrotateA");
	}	
	else if((unsorted_arrayA[0] < unsorted_arrayA[1]) && (unsorted_arrayA[1] >  unsorted_arrayA[2]) && (unsorted_arrayA[0] < unsorted_arrayA[2])){
		//1,3,2
		new_array = swapA(unsorted_arrayA, array_size);
		print_array(new_array, array_size, "swapA");
	}
	else if ((unsorted_arrayA[0] > unsorted_arrayA[1]) && (unsorted_arrayA[1] < unsorted_arrayA[2]) && (unsorted_arrayA[0] < unsorted_arrayA[2])){
		//2,1,3
		new_array = swapA(unsorted_arrayA, array_size);
		print_array(new_array, array_size, "swapA");
		new_array = revrotateA(new_array, array_size);
		print_array(new_array, array_size, "revrotateA");
	}
	else if ((unsorted_arrayA[0] < unsorted_arrayA[1]) && (unsorted_arrayA[1] > unsorted_arrayA[2]) && (unsorted_arrayA[0] > unsorted_arrayA[2])){
		//2,3,1
		new_array = swapA(unsorted_arrayA, array_size);
		print_array(new_array, array_size, "swapA");
	}
	/*else if ((unsorted_arrayA[0] < unsorted_arrayA[1]) && (unsorted_arrayA[1] > unsorted_arrayA[2]) && (unsorted_arrayA[0] > unsorted_arrayA[2])){
		//3,1,2
		new_array = unsorted_arrayA;
		print_array(new_array, array_size, "Nothing done");
	}*/
	else if ((unsorted_arrayA[0] > unsorted_arrayA[1]) && (unsorted_arrayA[1] > unsorted_arrayA[2]) && (unsorted_arrayA[0] > unsorted_arrayA[2])){
		//3,2,1
		new_array = revrotateA(unsorted_arrayA, array_size);
		print_array(new_array, array_size, "revrotateA");
		new_array = swapA(new_array, array_size);
		print_array(new_array, array_size, "swapA");
	}
	else{
		new_array = unsorted_arrayA;
		print_array(new_array, array_size, "Nothing done");
	}
	return new_array;
}

char *three_number_sort(char *unsorted_arrayA, int array_size){
	char *new_array = (char *)malloc(array_size*sizeof(char));
	if ((unsorted_arrayA[0] > unsorted_arrayA[1]) && (unsorted_arrayA[0] > unsorted_arrayA[2])){
		new_array = rotateA(unsorted_arrayA, array_size);
		print_array(unsorted_arrayA, array_size, "rotateA");
	}	
	else if((unsorted_arrayA[1] > unsorted_arrayA[0]) && (unsorted_arrayA[1] > unsorted_arrayA[2])){
		new_array = revrotateA(unsorted_arrayA, array_size);
		print_array(unsorted_arrayA, array_size, "revrotateA");
	}
	else if((unsorted_arrayA[1] > unsorted_arrayA[0]) && (unsorted_arrayA[1] < unsorted_arrayA[2])){
		new_array = swapA(unsorted_arrayA, array_size);
		print_array(unsorted_arrayA, array_size, "swapA");
	}
	else if ((unsorted_arrayA[0] > unsorted_arrayA[1]) && (unsorted_arrayA[1] < unsorted_arrayA[2]) && (unsorted_arrayA[0] < unsorted_arrayA[2])){
		new_array = swapA(unsorted_arrayA, array_size);
		print_array(unsorted_arrayA, array_size, "swapA");
	}
	else if((unsorted_arrayA[0] < unsorted_arrayA[1]) && (unsorted_arrayA[1] < unsorted_arrayA[2]) && (unsorted_arrayA[0] < unsorted_arrayA[2])){
		return unsorted_arrayA;
	}



	if (new_array[0] > new_array[1]){
		new_array = swapA(new_array, array_size);
		print_array(unsorted_arrayA, array_size, "swapA");
	}
	return new_array;
}
/*
int main(){
	{
		printf("\n------------------------------------------------------------------------------\n");
		char *A = (char *)malloc(3*sizeof(char));
		A[0] = 30;
		A[1] = 94;
		A[2] = 82;
		A = three_number_sort(A, 3);
		printf("\n");
		for (int i =0; i < 3; i++){
			printf("%d ", A[i]);
		}
		printf("\n------------------------------------------------------------------------------\n");

	}
	{
		printf("\n------------------------------------------------------------------------------\n");

		char *A = (char *)malloc(3*sizeof(char));
		A[0] = -53;
		A[1] = 98;
		A[2] = 18;
		A = three_number_sort(A, 3);
		printf("\n");
		for (int i = 0; i < 3; i++){
			printf("%d ", A[i]);
		}
		printf("\n------------------------------------------------------------------------------\n");

	}
	{
		printf("\n------------------------------------------------------------------------------\n");

		char *A = (char *)malloc(3*sizeof(char));
		A[0] = 8;
		A[1] = 15;
		A[2] = -40;
		A = three_number_sort(A, 3);
		printf("\n");
		for (int i =0; i < 3; i++){
			printf("%d ", A[i]);
		}
		printf("\n------------------------------------------------------------------------------\n");

	}
	{
		printf("\n------------------------------------------------------------------------------\n");

		char *A = (char *)malloc(3*sizeof(char));
		A[0] = 57;
		A[1] = -60;
		A[2] = -58;
		A = three_number_sort(A, 3);
		printf("\n");
		for (int i =0; i < 3; i++){
			printf("%d ", A[i]);
		}
		printf("\n------------------------------------------------------------------------------\n");

	}
	return (0);
}*/
