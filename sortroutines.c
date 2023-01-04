#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

void printChoices();
void printArray(int array[], int size);
void insertionSort(int array[], int size);          // O(n^2)
void selectionSort(int array[], int size);          // O(n^2)
void bubbleSort(int array[], int size);             // O(n^2)
void mergeSort(int array[], int size);              // O(n.lg(n))
void sortSubArray(int array[], int low, int high);
void merge(int array[], int left, int middle1, int middle2, int right);

int main()
{
        
	int array1[SIZE];
	int array2[SIZE];
	int array3[SIZE];
	int array4[SIZE];
	int i = 0;
	int input = 0;

	srand(time(NULL));
	      
        for(i=0;i<SIZE;i++)
	     array1[i] = rand()%30 + 1;
	
        for(i=0;i<SIZE;i++){
	     array2[i] = array1[i];
             array3[i] = array1[i];
             array4[i] = array1[i];
        }

        clock_t start;
	
        while(1)
	{
		//printArray(array, SIZE);
		printf("\n");
		printChoices();
		printf("Enter choice: ");
		scanf("%d",&input);
		switch(input)
		{
		case 1:
			start = clock();
			insertionSort(array1, SIZE);
			start = clock() - start;
			printf("Time it took to calc %f\n", ((float)start/CLOCKS_PER_SEC));
			break;
		case 2:
			start = clock();
			selectionSort(array2, SIZE);
			start = clock() - start;
			printf("Time it took to calc %f\n", ((float)start/CLOCKS_PER_SEC));
			break;
		case 3:
			start = clock();
			bubbleSort(array3, SIZE);
			start = clock() - start;
			printf("Time it took to calc %f\n", ((float)start/CLOCKS_PER_SEC));
			break;
		case 4:
			start = clock();
			mergeSort(array4, SIZE);
			start = clock() - start;
			printf("Time it took to calc %f\n", ((float)start/CLOCKS_PER_SEC));
			break;
		case 5:
			printf("exiting\n");
			return 0;
		default:
			printf("invalid entry\n");
			break;
		}
	}	
  return 0;
}

void printChoices()
{
	printf("1: Insertion sort\n2: Selection sort\n3: bubble sort"
		"\n4: Merge sort\n5: exit\n");
}
void printArray(int array[], int size)
{
	int i;
	printf("current array: ");
	for(i=0;i<size;i++)
		printf("%d ",array[i]);
	printf("\n\n");
}
void insertionSort(int array[], int size)
{
	int temp;
	int i;
	for(i = 1; i < size; i++)
	{
		int moveItem = i;
		temp = array[i];
		while(moveItem > 0 && array[moveItem-1] > temp)
		{
			array[moveItem] = array[moveItem - 1];
			--moveItem;
		}
		array[moveItem] = temp;
	}
}
void selectionSort(int array[], int size)
{
	int smallest;
	int i, j;

	for(i = 0; i < size-1;i++)
	{
		smallest = i;
		for(j = i+1;j<size;j++)
			if(array[j] < array[smallest])
				smallest = j;
		int temp;
		temp = array[i];
		array[i] = array[smallest];
		array[smallest] = temp;
	}
}
void bubbleSort(int array[], int size)
{
	int i,j;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size-i-1;j++)
		{
			if(array[j] > array[j+1])
			{
				int temp  = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}	
	}
}
void mergeSort(int array[], int size)
{
	sortSubArray(array, 0, size-1);
}
void sortSubArray(int array[], int low, int high)
{
	int middle1, middle2;
	if((high - low)>=1)
	{
		middle1 = (low+high)/2;
		middle2 = middle1+1;

		sortSubArray(array, low, middle1);
		sortSubArray(array, middle2, high);

		merge(array, low, middle1, middle2, high);
	}

}
void merge(int array[], int left, int middle1, int middle2, int right)
{
	int leftIndex = left;
	int rightIndex = middle2;
	int combinedIndex = left;
	int tempArray[SIZE];
	int i;

	while(leftIndex <= middle1 && rightIndex <= right)
	{
		if(array[leftIndex] <= array[rightIndex])
			tempArray[combinedIndex++] = array[leftIndex++];
		else
			tempArray[combinedIndex++] = array[rightIndex++];
	}
	if(leftIndex == middle2)
	{
		while(rightIndex <= right)
			tempArray[combinedIndex++] = array[rightIndex++];
	}
	else
	{
		while(leftIndex <= middle1)
			tempArray[combinedIndex++] = array[leftIndex++];
	}

	for(i = left; i<=right;i++)
		array[i] = tempArray[i];

}
