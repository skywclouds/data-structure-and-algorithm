/*
Author: Henry Wang
Date: 2021-4-22
heapsort
*/
#include <iostream>

using namespace std;

/*build max heap for index i
*/
void maxHeapify(int* A, int i, int heapSize);
/*build the whole array to max heap
*/
void buildMaxHeap(int* A, int heapSize);
/*heapsort algorithm
*/
void heapSort(int* A, int heapSize);

int main()
{
    int A[] = { 7,6,5,4,3,2,1 };
    int heapSize = sizeof(A) / sizeof(int);
    heapSort(A, heapSize);
    for (int i = 0; i < heapSize; i++)
        cout << A[i] << " ";
    cout << endl;
}

void buildMaxHeap(int* A, int heapSize)
{
    for (int i = heapSize / 2; i >= 0; i--)
        maxHeapify(A, i, heapSize);
    //from heapSize/2 to 0 build every index to max heap
}
void maxHeapify(int* A, int i, int heapSize)
{
    int l = (i + 1) * 2 - 1;//left child
    int r = (i + 1) * 2;//right child
    int largest;//the index of largest value
    if (l < heapSize && *(A + l) > *(A + i))  
        largest = l;    
    else    
        largest = i;  
    if (r < heapSize && *(A + r) > *(A + largest))
        largest = r;
    //code above is to find the index of max value
    if (largest != i)
    {
        int temp = *(A + i);
        *(A + i) = *(A + largest);
        *(A + largest) = temp;//exchange i and largest
        maxHeapify(A, largest, heapSize);
    }
}
void heapSort(int* A, int heapSize)
{
    if (heapSize > 1)
    {        
        buildMaxHeap(A, heapSize);
        int temp = *A;
        *A = *(A + heapSize - 1);
        *(A + heapSize - 1) = temp;
        //build max heap and 
        //put the first element(also the max) to the last
        heapSort(A, heapSize - 1);
    }    
}

