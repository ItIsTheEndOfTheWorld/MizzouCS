#include <stdio.h>
#include <stdlib.h>


//lab assignment: week 1
//review loops, arrays, and functions


//function prototypes
int addition(int arr[], int size);


//main function: 
//	create and initialize variables
//	use addition function
//	print result of addition function
//	return 0
int main(void)
{
	int size = 5;
	int array[5] = {5, 10, 8, 2, 13};
	
	int sum = addition(array, size);
	printf("\nSum is: %d\n", sum);
	
	return 0;
}


//addition function:
//	loop through an array of a specified size
//	print the array
//	compute the sum of the array
//	return sum
int addition(int arr[], int size)
{
	int sum = arr[0];
	printf("Array is: %d", arr[0]); //I chose to put the first item in the list outside
	//so I could keep the formatting consistant for the other items, as there are commas.
	int i = 1;
	for (; i < size; i++)
	{
		printf(", %d", arr[i]);
		sum += arr[i];
	}
	
	return sum;
}
