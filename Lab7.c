/*
COP 3502 Sec 0028 Lab 7
3/7/2024 Giorgio Torregrosa
*/

/*
READ ME
THERE SEEMS TO BE A DIFFERENCE IN OPINION WHEN TWO ELEMENTS ARE SWAPPED. ACCORDING TO LEVENT, (TA @ UCF), WHEN TWO ELEMENTS ARE SWAPPED THEY BOTH INCREMENT THEIR RESPECTIVE SWAP VALUES.
ACCORDING TO BINAY, WHEN TWO ELEMENTS ARE SWAPPED, ONLY THE ELEMENT THAT CAUSED THE SWAP INCREMENTS IT'S RESPECTIVE SWAP VALUE.
THE LAB DIRECTIONS STATE THAT THE TOTAL NUMBER OF SWAPS SHOULD NOT EQUAL THE SUM OF EACH INDIVIDUAL'S SWAP VALUE. THEREFORE IN THIS PROGRAM I WILL USE LEVENT'S METHOD INSTEAD OF BINAY.
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 9

int main(int argc, char* argv[]) {

	/*
	PART ONE BUBBLESORT
	*/

	//given arrays
	int array1[] = { 97, 16, 45, 63, 13, 22, 7, 58, 72 };
	int array2[] = { 90, 80, 70, 60, 50, 40, 30, 20, 10 };
	//frequency arrays to count swaps
	int freqArray1[SIZE][2] = { {97, 0}, {16, 0}, {45, 0}, {63, 0}, {13, 0}, {22, 0}, {7, 0}, {58, 0}, {72, 0} };
	int freqArray2[SIZE][2] = { {90, 0}, {80, 0}, {70, 0}, {60, 0}, {50, 0}, {40, 0}, {30, 0}, {20, 0}, {10, 0} };
	//total swap variables
	int totalBubbleswaps = 0;
	int totalSelectionswaps = 0;

	//array1
	printf("Array1 before bubble sort: ");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", array1[i]);
	}
	printf("\n");

	//Bubble Sort on Array 1
	int temp = 0;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE - 1; j++) {
			if (array1[j] > array1[j + 1]) {
				temp = array1[j];
				array1[j] = array1[j + 1];
				array1[j + 1] = temp;
				totalBubbleswaps++;
				for (int k = 0; k < SIZE; k++) {
					if (array1[j + 1] == freqArray1[k][0]) {//frequency calculation on the element that initiated the swap.
						freqArray1[k][1]++;
					}
					if (array1[j] == freqArray1[k][0]) {//frequency calculation on the element that initiated the swap.
						freqArray1[k][1]++;
					}
				}
			}
		}
	}

	//proof of sorting array1
	printf("Array1 after bubble sort: ");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", array1[i]);
	}

	//number of times each element was swapped in array1
	printf("\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%d was swapped %d times\n", freqArray1[i][0], freqArray1[i][1]);
	}
	printf("Total swaps: %d\n", totalBubbleswaps);
	printf("\n");

	//array2
	printf("Array2 before bubble sort: ");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", array2[i]);
	}
	printf("\n");

	//Bubble Sort on Array 2
	totalBubbleswaps = 0;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE - 1; j++) {
			if (array2[j] > array2[j + 1]) {
				totalBubbleswaps++;
				temp = array2[j];
				array2[j] = array2[j + 1];
				array2[j + 1] = temp;
				for (int k = 0; k < SIZE; k++) {
					if (array2[j + 1] == freqArray2[k][0]) {//frequency calculation on the element that initiated the swap.
						freqArray2[k][1]++;
					}
					if (array2[j] == freqArray2[k][0]) {//frequency calculation on the element that initiated the swap.
						freqArray2[k][1]++;
					}
				}
			}
		}
	}

	//proof of sorting array2
	printf("Array2 after bubble sort: ");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", array2[i]);
	}

	//number of times each element was swapped in array2
	printf("\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%d was swapped %d times\n", freqArray2[i][0], freqArray2[i][1]);
	}
	printf("Total swaps: %d", totalBubbleswaps);
	printf("\n\n");

	/*
	PART TWO SELECTION SORT
	*/

	int array3[] = { 97, 16, 45, 63, 13, 22, 7, 58, 72 };
	int array4[] = { 90, 80, 70, 60, 50, 40, 30, 20, 10 };
	int freqArray3[SIZE][2] = { {97, 0}, {16, 0}, {45, 0}, {63, 0}, {13, 0}, {22, 0}, {7, 0}, {58, 0}, {72, 0} };
	int freqArray4[SIZE][2] = { {90, 0}, {80, 0}, {70, 0}, {60, 0}, {50, 0}, {40, 0}, {30, 0}, {20, 0}, {10, 0} };
	temp = 0;
	int min = 0;

	//proof of sorting array1
	printf("Array1 after selection sort: ");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", array3[i]);
	}

	//SELECTION SORT ARRAY1
	for (int i = 0; i < SIZE - 1; i++) {
		min = i;
		for (int j = i + 1; j < SIZE; j++) {
			if (array3[j] < array3[min]) {
				min = j;
			}
		}
		if (min != i) {
			temp = array3[i];
			array3[i] = array3[min];
			array3[min] = temp;

			totalSelectionswaps++;

			for (int k = 0; k < SIZE; k++) {
				if (array3[i] == freqArray3[k][0]) {
					freqArray3[k][1]++;
				}
				if (temp == freqArray3[k][0]) {
					freqArray3[k][1]++;
				}
			}
		}
	}

	printf("\n");
	//proof of sorting array1
	printf("Array1 after selection sort: ");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", array3[i]);
	}
	//number of times each element was swapped in array1
	printf("\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%d was swapped %d times\n", freqArray3[i][0], freqArray3[i][1]);
	}
	printf("Total swaps: %d\n", totalSelectionswaps);
	printf("\n");
	totalSelectionswaps = 0;

	//array2
	printf("Array1 after selection sort: ");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", array4[i]);
	}

	//SELECTION SORT ARRAY2
	for (int i = 0; i < SIZE - 1; i++) {
		min = i;
		for (int j = i + 1; j < SIZE; j++) {
			if (array4[j] < array4[min]) {
				min = j;
			}
		}
		if (min != i) {
			temp = array4[i];
			array4[i] = array4[min];
			array4[min] = temp;

			totalSelectionswaps++;

			for (int k = 0; k < SIZE; k++) {
				if (array4[i] == freqArray4[k][0]) {
					freqArray4[k][1]++;
				}
				if (temp == freqArray4[k][0]) {
					freqArray4[k][1]++;
				}
			}
		}
	}

	printf("\n");
	//proof of sorting array2
	printf("Array1 after selection sort: ");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", array4[i]);
	}
	//number of times each element was swapped in array2
	printf("\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%d was swapped %d times\n", freqArray4[i][0], freqArray4[i][1]);
	}
	printf("Total swaps: %d\n", totalSelectionswaps);

}//end main
