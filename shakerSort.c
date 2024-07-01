#include <stdio.h>
#include <stdlib.h>

//function prototypes
void swap(int*, int*);
void printListHeader(int);
void printList(int*, int);
int shakerSort(int *, int);


int main()
{
	int nums[] = { 9,1,10,4 };

	// determine number of entries
	int size = sizeof(nums);
	int count = size / sizeof(int);

	// show original list order
	printListHeader(count);
	printList(&nums[0], count);

	// selection sort list, return number of swaps
	int numOfSwaps = shakerSort(&nums[0], count);

	// show list after sorted
	printList(&nums[0], count);

	// show number of Swaps performed
	printf("number of swaps: %d", numOfSwaps);

	//return 0 to Operating System (OS)
	exit(0);
}

int shakerSort(int *arr, int size)
{
	int numberOfSwaps = 0;
	int p, i;
	for (p = 1; p < size / 2; p++)
	{

		for (i = p - 1; i < size - p; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(&arr[i], &arr[i + 1]);
				numberOfSwaps++;
				printList(&arr[0], size);
			}
		}

		for (i = size - p - 1; i >= p; i--)
		{
			if (arr[i] < arr[i - 1])
			{
				swap(&arr[i], &arr[i - 1]);
				numberOfSwaps++;
				printList(&arr[0], size);
			}
		}
	}

	return numberOfSwaps;

}

void swap(int* n1, int* n2)
{
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

void printListHeader(int size)
{
	for (int k = 0; k < size; k++)
	{
		
		printf("%3d ", k);
	}
	printf("\n");
}

void printList(int* arr, int size)
{

	for (int k = 0; k < size; k++)
	{
		printf("%3d ", arr[k]);
	}
	printf("\n");
}

