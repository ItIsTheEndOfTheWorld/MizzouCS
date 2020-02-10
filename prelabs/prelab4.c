#include <stdio.h>
#include <stdlib.h>

//okay so this uses void pointers. void pointers hold addresses of any type and can be typecasted to any type

//prototypes
void* createArray(int size, int dataTypeSize);
void freeArray(void** array);

int main(void)
{
	//try different types of data. each array will have a length of 5.
	int dataTypeSize = sizeof(double);
	int dataTypeSize2 = sizeof(int);
	int dataTypeSize3 = sizeof(char);
	int dataTypeSize4 = sizeof(float);
	int size = 5;
	
	//create arrays of appropriate types.
	//(a void pointer can be cast to any type of data.)
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
	
	//make void pointers of the arrays and pass the pointers to freeArray to free the malloc'ed data
	void* ptr = arr;
	void* ptr2 = arr2;
	void* ptr3 = arr3;
	void* ptr4 = arr4;
	freeArray(&ptr);
	freeArray(&ptr2);
	freeArray(&ptr3);
	freeArray(&ptr4);
	
	//success!
	return 0;
}

//create array of any type. data size should be specified beforehand.
//malloc only needs an integer that specifies how much data should be allotted. specifying that when the function is called
//allows it to be of any type.
void* createArray(int size, int dataTypeSize)
{
	return malloc(size*dataTypeSize);
}

//free the malloc'ed memory. print success message - it makes me feel better to have a visual confirmation of "yes, this did the thing"
void freeArray(void** array)
{
	free(array);
	printf("\nMemory %s freed.\n", "successfully");
}
