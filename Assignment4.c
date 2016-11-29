/*	This program calculates the highest lowest and average of
	student grades from a file.
	Written by: Ayse Rumeysa Ergin
	Date:		11/15/2016
*/

#include<stdio.h>

#define MAX_ROW 40
#define MAX_COL 6

int N;

//Function Declarations

void record (int d[MAX_ROW][MAX_COL]);
void highest(int d[MAX_ROW][MAX_COL]);
void lowest(int d[MAX_ROW][MAX_COL]);
void avr(int d[MAX_ROW][MAX_COL]);

int main (void)
{
	//Local Declarations
	int d[MAX_ROW][MAX_COL];
	
	//Statements
	printf("Student\tQuiz1\tQuiz2\tQuiz3\tQuiz4\tQuiz5\n");
	record(d);
	highest(d);
	lowest (d);
	avr (d);
	return 0;
}

/*============== record ================
	This function records data into array and prints the data.
		Pre		Nothing
		Post	Array is filled, data printed.
*/
void record (int d[MAX_ROW][MAX_COL])
{
	//Local Declarations
	FILE* Gr_Book;
	int data;
	
	//Statements
	Gr_Book = fopen ("ErginAyse-Data4.dat", "r");
	while (fscanf(Gr_Book, "%d %d %d %d %d %d", &d[N][0], &d[N][1], &d[N][2], &d[N][3], &d[N][4], &d[N][5]) != EOF)
		N++;
		
	for (int i = 0; i< N; i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n", d[i][0], d[i][1], d[i][2], d[i][3], d[i][4], d[i][5]);
	}//for
		
	fclose (Gr_Book);
	return;
}//record

/*=============== highest ============
	This function determines the highest score.
		Pre		Nothing
		Post	Highest value printed.
*/
void highest (int d[MAX_ROW][MAX_COL])
{
	int high[6];
	for (int i= 1 ; i< 6; i++)
	{
		high[i]= d[0][i];
		for (int j = 1; j < N; j++)
		{
			if (d[j][i] > high[i])
        		high[i] = d[j][i];
        }//for
	}//for
	printf("\nHighest\t%d\t%d\t%d\t%d\t%d\t", high[1], high[2], high[3], high[4], high[5]);
return;
}//highest

/*=============== lowest ============
	This function determines the lowest score.
		Pre		Nothing
		Post	Lowest value printed.
*/

void lowest (int d[MAX_ROW][MAX_COL])
{
	int low[6];
	for (int n= 1; n< 6; n++)
	{
		low[n] = d[0][n];
		for (int i= 1 ; i< N; i++)
		{
			if(d[i][n] < low[n])
      			low[n] = d[i][n];
		}//for
	}//for
	printf("\nLowest\t%d\t%d\t%d\t%d\t%d\t", low[1], low[2], low[3], low[4], low[5]);
	return;
}//lowest

/*=============== avr ============
	This function determines the lowest score.
		Pre		Nothing
		Post	Average value printed.
*/

void avr (int d[MAX_ROW][MAX_COL])
{
	//Local Declarations
	int sum[6] = {0};
	float ave[6]; 

	//Statements
	for (int x= 1 ; x< 6; x++)
	{
		for (int i = 0 ; i < N; i++)
		{
			sum[x] += d[i][x];
		}//for
		ave[x] = (float)sum[x]/ N;
	}//for
	printf("\nAverage\t%4.1f\t%4.1f\t%4.1f\t%4.1f\t%4.1f", ave[1], ave[2], ave[3], ave[4], ave[5]);
	return ;
}//avr
