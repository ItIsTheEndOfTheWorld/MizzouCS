#include <stdio.h>
#include <stdlib.h>

//uh, slides 33-3something are decent resources
//okay so this uses void pointers. void pointers hold addresses of any type and
//can be typecasted to any type

void* createArray(int size, int dataTypeSize);
void freeArray(void** array);

int main(void)
{
	int dataTypeSize = sizeof(double);
	int dataTypeSize2 = sizeof(int);
	int dataTypeSize3 = sizeof(char);
	int dataTypeSize4 = sizeof(float);
	int size = 5;
	
	double* arr = createArray(size, dataTypeSize);
	int* arr2 = createArray(size, dataTypeSize2);
	char* arr3 = createArray(size, dataTypeSize3);
	float* arr4 = createArray(size, dataTypeSize4);
	
	//test arr to see if it works
	arr[0] = 2.3415151616;
	arr[1] = 23.423343334;
	arr[2] = 5.5555555555;
	arr[3] = 0.94743920268;
	arr[4] = 9.23333333333;
	int i = 0;
	printf("\narr\n%s","---\n");
	for (; i < size; i++)
	{
		printf("%d: %f\n", i, arr[i]);
	}
	
	//test arr2
	i = 0;
	printf("\narr2\n%s","----\n");
	for (; i < size; i++)
	{
		arr2[i] = 42+i;
		printf("%d: %d\n", i, arr2[i]);
	}
	
	//test arr3
	i = 0;
	arr3[0] = 'c';
	arr3[1] = 'd';
	arr3[2] = 'e';
	arr3[3] = 'f';
	arr3[4] = 'g';
	printf("\narr3\n%s","----\n");
	for(; i < size; i++)
	{
		printf("%d: %c\n", i, arr3[i]);
	}
	
	//test arr4
	arr4[0] = 3.2415151616;
	arr4[1] = 2.3423343334;
	arr4[2] = 6.5555555555;
	arr4[3] = 1.94743920268;
	arr4[4] = 6.23333333333;
	i = 0;
	printf("\narr4\n%s","----\n");
	for (; i < size; i++)
	{
		printf("%d: %f\n", i, arr4[i]);
	}
	
	void* ptr = arr;
	void* ptr2 = arr2;
	void* ptr3 = arr3;
	void* ptr4 = arr4;
	freeArray(&ptr);
	freeArray(&ptr2);
	freeArray(&ptr3);
	freeArray(&ptr4);
	
	return 0;
}

void* createArray(int size, int dataTypeSize)
{
	return malloc(size*dataTypeSize);
}

void freeArray(void** array)
{
	free(array);
	printf("\nMemory %s freed.\n", "successfully");
}