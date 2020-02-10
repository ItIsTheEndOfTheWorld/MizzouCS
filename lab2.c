#include <stdio.h>
#include <stdlib.h>

/*Student grades: given an integer list, determine how many are within each grade range,
	pass those values to the main function by reference, and print the output.*/

//function prototype
void countGrades(int arr[], int size, int BBoundary, int CBoundary, int* NoOfAs, int* NoOfBs, int* NoOfCs);


int main(void)
{    
	//Values given by the Starter Code
	int array[30] = {57,99,53,58,46,46,92,72,43,82,42,90,70,65,88,53,59,75,43,45,66,69,63,93,77,98,99,40,88,49};    
	int size = sizeof(array)/sizeof(array[0]);    
	int BBoundary = 80, CBoundary = 60;
	
	//Number of each type of grade, initialized to 0.
	int numOfAs = 0;
	int numOfBs = 0;
	int numOfCs = 0;
	
	//Determine the number of each type of grade. Pass numOfAs, numOfBs, and numOfCs by reference.
	countGrades(array, size, BBoundary, CBoundary, &numOfAs, &numOfBs, &numOfCs);
	
	//Print the results.
	printf("\n%d students got an A, %d students got a B, and %d students got a C.\n\n", numOfAs, numOfBs, numOfCs);
	
	return 0;
}


//Determine what sort of grade each item is (i.e. A, B, C).
//Pass the number of each type of grade back to main.
/*Variable definitions:
	arr: input integer array of grades
	size: integer - size of the input array
	BBoundary: integer representing the lowest possible value for an A grade
	CBoundary: integer representing the lowest possible value for a B grade
	NoOfAs: pointer to an integer representing the number of A grades in the input array
	NoOfBs: pointer to an integer representing the number of B grades in the input array
	NoOfCs: pointer to an integer representing the number of C grades in the input array
*/
void countGrades(int arr[], int size, int BBoundary, int CBoundary, int* NoOfAs, int* NoOfBs, int* NoOfCs)
{
	int i = 0;
	for (; i < size; i++)
	{		
		//Item is an A when it is at least the BBoundary
		if (arr[i] >= BBoundary)
		{
			*NoOfAs += 1;
		}
		
		//Item is a B when it is at least the CBoundary
		else if (arr[i] >= CBoundary)
		{
			*NoOfBs += 1;
		}
		
		//Item is a C when it's below the CBoundary
		else
		{
			*NoOfCs += 1;
		}
	}
}