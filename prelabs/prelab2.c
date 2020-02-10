#include <stdio.h>
#include <stdlib.h>
#define SIZE 12

/*
determine the number of integers in an array of integers that 
	are less than a given integer 
and the number of integers in an array of integers that 
	are greater than a given integer 
*/
void numGreatOrLess(int *p, int *greater, int *lesser, int given, int size);

int main(void)
{
	int p[SIZE] = {1,2,3,4,5,6,7,8,9,4,0,-5};
	int greater = 0;
	int lesser = 0;
	int given = 0;
	int size = SIZE;
	numGreatOrLess(p, &greater, &lesser, given, size);
	printf("\nThe given integer was %d.\nThere were %d numbers greater than %d in the array.\nThere were %d numbers less than %d in the array.\n\n", given, greater, given, lesser, given);
}

void numGreatOrLess(int *p, int *greater, int *lesser, int given, int size)
{
	int i = 0;
	for (; i < size; i++)
	{
		if (p[i] > given)
			*greater += 1;
		else if (p[i] < given)
			*lesser += 1;
	}
}
