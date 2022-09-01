#include <stdlib.h> //Standard lib
#include <stdio.h> //Standard input-output
#include <time.h> //Time (Clock)

//Sort
#include "Merge/MergeSort.h" //MergeSort lib
#include "Heap/HeapSort.h" //HeapSort lib
#include "Quick/QuickSort.h" //QuickSort lib

void printVector(int *vector, int vectorSize) //Print vector
{
	int aux;
	for(aux = 0; aux < vectorSize; aux++)
		printf ("%d\n", vector[aux]);
}


int main() {
	int *vector, *vectoraux, inputsize, aux;
	clock_t start_t;
	scanf ("%d", &inputsize); //Get number of numbers to order.
	
	vector = (int *) malloc(inputsize * sizeof(int)); //Dynamic allocation of int vector
	vectoraux = (int *) malloc(inputsize * sizeof(int)); //Dynamic allocation of int aux vector

	for (aux = 0; aux < inputsize; aux++)
	{
		scanf ("%d", &vector[aux]);
		vectoraux[aux] = vector[aux];
	}

	//Execute Merge Sort
	start_t = clock(); //Set start clock.
	mergeSort(vectoraux, 0, inputsize-1);
	printf ("Merge: %f\n", (double)(clock() - start_t)/CLOCKS_PER_SEC);

	for (aux = 0; aux < inputsize; aux++)
		vectoraux[aux] = vector[aux];

	//Execute Heap Sort
	start_t = clock(); //Set start clock.
	heap_sort(vectoraux, inputsize);
	printf ("Heap: %f\n", (double)(clock() - start_t)/CLOCKS_PER_SEC);

	for (aux = 0; aux < inputsize; aux++)
		vectoraux[aux] = vector[aux];

	//Execute Quick Sort
	start_t = clock(); //Set start clock.
	quickSort(vectoraux, 0, inputsize-1);
	printf("Quick: %f\n", (double)(clock() - start_t)/CLOCKS_PER_SEC);

	free(vector);
	free(vectoraux);
}
