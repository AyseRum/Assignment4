/* This program sorts the data in it in ascending and descending orders.
	Then prints ascending, original, and descending data sets.
*/

#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

// Function Declarations
int* getData		(int* pAry, int arySize);
void ascendingSort	(int* pAry, int* pLast)	;
void descendingSort (int* pAry, int* pLast)	;
void printData 		(int* pAry)				;
int* smallest 		(int* pAry, int* pLast)	;
int* largest 		(int* pAry, int* pLast)	;

int main (void)
{
// Local Declarations
	int ary[SIZE] = {26,14, 57, 33, 41};
	
// Statements 
	printData (ary);
	
	return 0;
}//main

/*============ ascendingSort ==============
 This function sorts the given array in an ascending order
 	Pre		:	Given array, last element of that array.
 	Post	:	Array sorted ascending.
*/
void ascendingSort (int* pAry, int* pLast)
{
//Local Declarations
	int* pWalker;
	int* pSmallest;
	int temp;
	
// Statements
	for(pWalker = pAry; pWalker < pLast; pWalker++)
		{
		pSmallest = smallest (pWalker, pLast);
		temp= *pWalker;
		*pWalker = *pSmallest;
		*pSmallest = temp;
		}//for
	return;
}// ascendingSort

/* ============ descendingSort =============
 This function sorts the given array in an descending order
 	Pre		:	Given array, last element of that array.
 	Post	:	Array sorted descending.
*/
void descendingSort (int* pAry, int* pLast)
{
//Local Declarations
	int* pWalker;
	int* pLargest;
	int temp;
	
// Statements
	for(pWalker = pAry; pWalker < pLast; pWalker++)
		{
		pLargest = largest (pWalker, pLast); 
		temp= *pWalker;
		*pWalker = *pLargest;
		*pLargest = temp;
		}//for
	return;
}

/* ============ smallest =============
 This function returns the smallest data in an array.	
 	Pre		:	Given an array,  and last element of that array.
	Post	:	smallest data returned.
*/
int* smallest (int* pAry, int* pLast)
{
//Local Declarations
	int* pLooker;
	int* pSmallest;
	
// Statements
	for(pSmallest = pAry, pLooker = pAry +1; pLooker <= pLast; pLooker++)
		if(*pLooker < *pSmallest)
			pSmallest = pLooker;
	return pSmallest;
}// smallest

/* ============ largest =============
This function returns the largest data in an array.	
 	Pre		:	Given an array,  and last element of that array.
	Post	:	largest data returned.
*/
int* largest (int* pAry, int* pLast)
{
//Local Declarations
	int* pLooker;
	int* pLargest;
	
// Statements
	for(pLargest = pAry, pLooker = pAry +1; pLooker <= pLast; pLooker++)
		if(*pLooker > *pLargest)
			pLargest = pLooker;
	return pLargest;
}// largest

/* ============ printData ==============
 This function prints the ascending and descending sorted types of an array
 	and array itself.
 	Pre		: Array
 	Post	: Array sorted in ascending and descending order.
 			  Ascending, Original, Descending lists printed.
*/
void printData (int* pAry)
{
// Local declarations
	int *aLast; 
	int *dLast;
	int* pAsc;
	int* pDes;
	
	
// Statements
	pAsc = (int*)malloc(SIZE * sizeof(int) );
	if(pAsc == NULL)
		free(pAsc);
	
	pDes = (int*) malloc(SIZE * sizeof(int) );
	if( pDes == NULL)
		free(pDes);

	for (int i = 0; i< SIZE; i++)
	{
		pAsc[i] = pAry[i];
		pDes[i] = pAry[i];
	}
	aLast = &pAsc[4];
	dLast = &pDes[4];	
	
	ascendingSort (pAsc, aLast);
	descendingSort (pDes, dLast);
	
	printf("\n\tAscending\t\tOriginal\t\tDescending\n");
	
	for(int i = 0; i < SIZE; i++)
	{
		printf("\t%4d\t\t\t%4d\t\t\t%4d\n", pAsc[i], pAry[i], pDes[i]);
	}
	

	return;
}//printData
