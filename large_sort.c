#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void pushA(char *unsorted_arrayA, char *unsorted_arrayB, int *array_sizeA, int *array_sizeB);				//adjust to alter both arrays, and both array sizes
void pushB(char *unsorted_arrayA, char *unsorted_arrayB, int *array_sizeA, int *array_sizeB);				//adjust to alter both arrays, and both array sizes
char *revrotateA(char *unsorted_array, int array_size);
char *rotateA(char *unsorted_array, int array_size);
char *swapA(char *unsorted_arrayA, int array_size);
void print_arrayAB(char *arrayA, int array_sizeA, char *array_nameA, char *arrayB, int array_sizeB, char *array_nameB);
void print_array(char *arrayA, int array_sizeA, char *array_nameA);
char *three_number_sort(char *unsorted_arrayA, int array_size);
char *large_small_med(char *unsorted_arrayA, int array_size);


char *ft_bubble_sort(char *unsorted_arrayA, int array_sizeA){
	int temp = 0;
	char *temp_arr = (char *)malloc(array_sizeA*sizeof(char));
	//temp_arr = unsorted_arrayA;
	for (int j = 0; j < array_sizeA; j++){
		temp_arr[j] = unsorted_arrayA[j];
	}
	for (int i = 0; i< array_sizeA - 1; i++){
		for (int j = 0; j< array_sizeA - 1; j++){
			if (temp_arr[j] > temp_arr[j+1]){
				temp = temp_arr[j+1];
				temp_arr[j+1] = temp_arr[j];
				temp_arr[j] = temp;
			}
		}
	}
	//print_array(unsorted_arrayA, array_sizeA, "unsorted A array");
	//print_array(temp_arr, array_sizeA, "temp arr A array");
	return temp_arr;
}


void big_sort(char *unsorted_arrayA, char *unsorted_arrayB, int array_sizeA, int array_sizeB){
	//print_array(unsorted_arrayA, array_sizeA, "original A array");
	char *bubble_sort = (char *)malloc(array_sizeA*sizeof(char));
	bubble_sort = ft_bubble_sort(unsorted_arrayA, array_sizeA);
	/*printf("\nbubble sort\n");
	for (int i =0; i< array_sizeA; i++){
		printf("%d ", bubble_sort[i]);
	}*/
	char *new_array = (char *)malloc(array_sizeA*sizeof(char));
	int *ptr_to_arrayA = &array_sizeA;
	int *ptr_to_arrayB = &array_sizeB;
	//print_array(unsorted_arrayA, array_sizeA, "original A array");
	//print_array(bubble_sort, array_sizeA, "bubble sort");
	if ((array_sizeA == 2) && (unsorted_arrayA[0] > unsorted_arrayA[1])){
		new_array = rotateA(unsorted_arrayA, array_sizeA);
		for (int i = 0; i< array_sizeA; i++){
			unsorted_arrayA[i] = new_array[i];
		}
		print_arrayAB(unsorted_arrayA, array_sizeA, "2) swapa arrayA", unsorted_arrayB, array_sizeB, "2) swapa arrayB");
		printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
	}
	//print_array(unsorted_arrayA, array_sizeA, "original A array");
	else if (array_sizeA == 3){
		new_array = three_number_sort(unsorted_arrayA, array_sizeA);
		for (int i = 0; i <3; i++){
			unsorted_arrayA[i] = new_array[i];
		}
	}
	//print_array(unsorted_arrayA, array_sizeA, "original A array");
	if (array_sizeA == 4){
		int i = 0;
		while (unsorted_arrayA[i] != bubble_sort[0]){
			i++;
		}
		i++;
		if (i > 1){
			for (int a = 0 ; a < 5-i; a++){
				unsorted_arrayA = revrotateA(unsorted_arrayA, array_sizeA);
			}
		}
		pushB(unsorted_arrayA, unsorted_arrayB, ptr_to_arrayA, ptr_to_arrayB);
		print_arrayAB(unsorted_arrayA, array_sizeA, "1) unsorted_arrayA", unsorted_arrayB, array_sizeB, "1) arrayB");
		new_array = three_number_sort(unsorted_arrayA, array_sizeA);
		print_arrayAB(new_array, array_sizeA, "2) new_array", unsorted_arrayB, array_sizeB, "2) arrayB");
		pushA(new_array, unsorted_arrayB, ptr_to_arrayA, ptr_to_arrayB);
		print_arrayAB(new_array, array_sizeA, "2) new_array", unsorted_arrayB, array_sizeB, "2) arrayB");
		for (int i = 0 ; i< array_sizeA; i++){
			unsorted_arrayA[i] = new_array[i];
		}
		print_arrayAB(unsorted_arrayA, array_sizeA, "2) new_array", unsorted_arrayB, array_sizeB, "2) arrayB");
	}
	//print_array(unsorted_arrayA, array_sizeA, "original A array");
	if (array_sizeA == 5){
		for (int a = 0; a< 2; a++){
			int  i = 0;
			//print_array(unsorted_arrayA, array_sizeA, "original A array");
			while (unsorted_arrayA[i] != bubble_sort[a]){
				i++;
			}
			if (i > 2){
				for (int ctr = i; ctr <= 5; ctr++){
					unsorted_arrayA = rotateA(unsorted_arrayA, array_sizeA);
					print_arrayAB(unsorted_arrayA, array_sizeA, "3a) unsorted_arrayA", unsorted_arrayB, array_sizeB, "3a) arrayB");
				}
			}
			else if (i <= 2){
				for (int ctr1 = i; ctr1 >= 0; ctr1--){
					unsorted_arrayA = revrotateA(unsorted_arrayA, array_sizeA);
					print_arrayAB(unsorted_arrayA, array_sizeA, "3b) unsorted_arrayA", unsorted_arrayB, array_sizeB, "3b) arrayB");
				}
			}	
			pushB(unsorted_arrayA, unsorted_arrayB, ptr_to_arrayA, ptr_to_arrayB);
			print_arrayAB(unsorted_arrayA, array_sizeA, "4) unsorted_arrayA", unsorted_arrayB, array_sizeB, "4) arrayB");
		}
		new_array = three_number_sort(unsorted_arrayA, array_sizeA);
		print_arrayAB(new_array, array_sizeA, "5) 3nbr srt unsorted_arrayA", unsorted_arrayB, array_sizeB, "5 ) three nb srt arrayB");
		for (int b = 0;b < 2; b++){
			pushA(new_array, unsorted_arrayB, ptr_to_arrayA, ptr_to_arrayB);
			print_arrayAB(new_array, array_sizeA, "5) unsorted_arrayA", unsorted_arrayB, array_sizeB, "5) arrayB");
		}
		for (int c= 0; c < array_sizeA; c++){
			unsorted_arrayA[c] = new_array[c];
		}
		print_arrayAB(unsorted_arrayA, array_sizeA, "5) unsorted_arrayA", unsorted_arrayB, array_sizeB, "5) arrayB");
	}
	int original_sizeA = array_sizeA;
	if (array_sizeA >= 6 && array_sizeA <= 10){
		for (int a = 0; a< original_sizeA - 3; a++){
			int  i = 0;
			//print_array(unsorted_arrayA, array_sizeA, "original A array");
			while (unsorted_arrayA[i] != bubble_sort[a]){
				i++;
			}
			if (i > array_sizeA/2){
				for (int ctr = 0; ctr < array_sizeA - i; ctr++){
					unsorted_arrayA = revrotateA(unsorted_arrayA, array_sizeA);
					print_arrayAB(unsorted_arrayA, array_sizeA, "3a) unsorted_arrayA", unsorted_arrayB, array_sizeB, "3a) arrayB");
				}
			}
			else if (i<= array_sizeA/2){
				for (int ctr1 = 0; ctr1 < i; ctr1++){
					unsorted_arrayA = rotateA(unsorted_arrayA, array_sizeA);
					print_arrayAB(unsorted_arrayA, array_sizeA, "3b) unsorted_arrayA", unsorted_arrayB, array_sizeB, "3b) arrayB");
				}
			}	
			pushB(unsorted_arrayA, unsorted_arrayB, ptr_to_arrayA, ptr_to_arrayB);
			print_arrayAB(unsorted_arrayA, array_sizeA, "4) unsorted_arrayA", unsorted_arrayB, array_sizeB, "4) arrayB");
		}
		unsorted_arrayA = three_number_sort(unsorted_arrayA, array_sizeA);
		print_arrayAB(unsorted_arrayA, array_sizeA, "5) 3nbr srt unsorted_arrayA", unsorted_arrayB, array_sizeB, "5 ) three nb srt arrayB");
		for (int b = 0;b < (original_sizeA - 3); b++){
			pushA(unsorted_arrayA, unsorted_arrayB, ptr_to_arrayA, ptr_to_arrayB);
		}
		print_arrayAB(unsorted_arrayA, array_sizeA, "5) unsorted_arrayA", unsorted_arrayB, array_sizeB, "5) arrayB");
	}
	/*if (array_sizeA > 10){
		//sorting using groups of 10
		//making groups
		int group_number = (array_sizeA / 10) + 1;
		int stage = 0;
	*/
}

int main(){
	srand(time(NULL));
	int A_len = 5;
	int B_len = 5;
	/*{
		char *A = (char *)malloc(A_len*sizeof(char));
		char *B = (char *)malloc(B_len*sizeof(char));
		A[0] = 63;
		A[1] = 86;
		A[2] = 36;
		A[3] = -27;
		A[4] = 30;
		printf("array A\n");
		for (int i = 0; i < A_len; i++){
			printf("%d ", A[i]);
		}
		big_sort(A, B, A_len, B_len);
		print_arrayAB(A, A_len, "2) newA", B, B_len, "2) newB");
	}*/
	
	{
		char *A = (char *)malloc(A_len*sizeof(char));
		char *B = (char *)malloc(B_len*sizeof(char));
		printf("unsorted A: ");
		for (int i=0; i<A_len; i++){
			A[i] = rand();
			printf("%d ", A[i]);
		}
		printf("\n\n\n\n\n\n");
		big_sort(A, B, A_len, B_len);
		//print_arrayAB(A, A_len, "2) newA", B, B_len, "2) newB");
	}
	return 0;
}
		

