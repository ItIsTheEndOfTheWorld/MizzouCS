#include <stdio.h>
#include <stdlib.h>

//read data from a file, manipulate it, mess with pointers

int* readIntAgeIntoArray(FILE* fp, int* totalNumOfEmployee, float* averageAge);
void findMinMax(int* arr, int size, int* minAge, int* maxAge);
void freeIntArray(int** arrPtr);

int main(void)
{
	//set up variables
	FILE* fp = fopen("employeeAge.txt", "r");
	int* arr = '\0';
	int totalNumOfEmployee;
	int minAge;
	int maxAge;
	float avgAge;
	
	//check to see if the file exists
	if (fp == NULL)
	{
		printf("File could not be found.%s", "\n");
		fclose(fp);
		return 1;
	}
	
	arr = readIntAgeIntoArray(fp, &totalNumOfEmployee, &avgAge);
	printf("\nThere are, in total, %d employees; their average age is %.2f.\n", totalNumOfEmployee, avgAge);
	findMinMax(arr, totalNumOfEmployee, &minAge, &maxAge);
	printf("Largest age is %d. Smallest age is %d.\n", maxAge, minAge);
	freeIntArray(&arr);
	
	fclose(fp);
	return 0;
}

//fp: file pointer. totalNumOfEmployee: number of lines (employees). averageAge: avg
// of the sum of all lines.
//create an array, read the data from the file into the array, and find the average
int* readIntAgeIntoArray(FILE* fp, int* totalNumOfEmployee, float* averageAge)
{
	fscanf(fp, "%d\n", totalNumOfEmployee);
	int i = 0;
	int* arr = malloc(sizeof(*totalNumOfEmployee));
	int total = 0;
	
	for (; i < *totalNumOfEmployee; i++)
	{
		int curr = 0;
		fscanf(fp, "%d\n", &curr);
		total += curr;
		arr[i] = curr;
	}
	
	*averageAge = (float)total/(float)*totalNumOfEmployee;
	
	return arr;
}

//find the minumum and maximum ages inside the array
void findMinMax(int* arr, int size, int* minAge, int* maxAge)
{
	int small = 1000;
	int large = -1;
	int i = 0;
	
	for (; i < size; i++)
	{
		if (arr[i] < small)
			small = arr[i];
		if (arr[i] > large)
			large = arr[i];
	}
	
	*minAge = small;
	*maxAge = large;
}

//free the memory used int the array
void freeIntArray(int** arrPtr)
{
	free(arrPtr);
	printf("\nMemory %s freed.\n", "successfully");
}