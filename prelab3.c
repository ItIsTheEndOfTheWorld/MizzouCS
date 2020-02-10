#include <stdio.h>
#include <stdlib.h>

//prototypes
float* readFloatFileIntoArray(FILE *fptr, int *length);
void freeMemory(float* arr);
void returnArraySize(FILE *fptr, int* length);


int main(void)
{
	//open file. check to see if file exists
	FILE *file = fopen("idunno.txt", "r");
	if (file == NULL)
	{
		printf("\n%s", "Error: file does not exist\n");
		return 0;
	}
	
	
	//read the file
	int *length = malloc(sizeof(int));
	float* arr = readFloatFileIntoArray(file, length);
	
	//check to see if the array exists
	if (*arr == '\0')
	{
		printf("dne%s", "\n");
		return 0;
	}
	
	//loop through each element in the array and print it.
	//(printed here and in the readFloat function to make sure the values are
	//passed back the way they should be.
	printf("\nLength: %d", *length);
	int i = 0;
	for (; i < *length; i++)
	{
		printf("\nElement %d: %f", i+1, *(arr+i));
	}
	printf("%sFreeing memory\n", "\n\n");
	
	//free memory, then check success
	freeMemory(arr);
	printf("%f\n",*arr);
	
	return 1;
}

//should take every value in the file specified in main and add them to an array
//array should be returned
float* readFloatFileIntoArray(FILE *fptr, int *length)
{
	fscanf(fptr, "%d", length);
	int size = *length;
	float* arr = malloc(sizeof(float)*size);
	if (*arr == '\0')
	{
		printf("\nCould not allocate %s\n", "memory!");
		return arr;
	}
	
	//should loop through entire file and save each float given in an array
	//(size of array determined above with malloc)
	//then print each element of the array.
	int i = 0;
	for (; i < size; i++)
	{
		fscanf(fptr, "%f", (arr+i));
		printf("Element %d:\t%f\n", i+1, *(arr+i));
	}
	
	length = &size;
	
	return arr;
}


//free memory of array
void freeMemory(float* arr)
{
	free(arr);
	printf("Memory freed\n");
	arr = '\0';
}