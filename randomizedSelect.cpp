/*
* randomized select
* Author: Henry Wang
* Date: 2021-5-20
*/

#include <iostream>

using namespace std;

/*Auxiliary algorithm
*/
int randomizedPartition(int* A, int p, int r);

/*randomized select key algorithm
*/
int randomizedSelect(int* A, int p, int r, int i);

int main()
{
	
	cout << "Hello World!" << endl;
	int A[10];
	srand(time(NULL));
	for (int i = 0; i < sizeof(A) / sizeof(int); i++)	
		A[i] = rand();
	for (int i = 1; i <= sizeof(A) / sizeof(int); i++)	
		cout << randomizedSelect(A, 0, sizeof(A) / sizeof(int) - 1, i) << " ";	
	cout << endl;
	
}

int randomizedPartition(int* A, int p, int r)
{
	srand(time(NULL));
	int q = (int)((r - p + 1) * ((rand() % 999) / ((double)1000))) + p;
	//exchange random index with the first element
	int temp = *(A + q);
	*(A + q) = *(A + p);
	*(A + p) = temp;
	int index = r;
	//partition
	for (int i = p + 1; i <= index; i++)
	{
		if (*(A + i) > *(A + p))
		{
			temp = *(A + i);
			*(A + i) = *(A + index);
			*(A + index) = temp;
			i--;
			index--;
		}
	}
	//put the first element into its index
	temp = *(A + p);
	*(A + p) = *(A + index);
	*(A + index) = temp;
	return index;
}

int randomizedSelect(int* A, int p, int r, int i)
{
	int q = randomizedPartition(A, p, r);
	int k = q - p + 1;
	if (k == i)		
		return *(A + q);	
	else if (k > i)	
		return randomizedSelect(A, p, q - 1, i);	
	else	
		return randomizedSelect(A, q + 1, r, i - k);	
}