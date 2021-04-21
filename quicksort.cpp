/*
Author: Henry Wang
Date: 2021-4-21
quick sort
*/

#include <iostream>

using namespace std;

/*quicksort algorithm
*/
void quicksort(int* A,int p,int q);
/*auxiliary algorithm
*/
int partiton(int* A, int p, int q);

int main()
{
    int A[] = {5,4,3,2,1};
    quicksort(A, 0, sizeof(A) / sizeof(int) - 1);
    for (int i = 0; i < sizeof(A) / sizeof(int); i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void quicksort(int* A, int p, int q)
{
    if (p < q)
    {
        int r = partiton(A, p, q);//rearrange the array
        quicksort(A, p, r - 1);//sort the left
        quicksort(A, r + 1, q);//sort the right
    }
}
int partiton(int* A, int p, int q)
{
    int r = q;//the index to return
    for (int i = p + 1; i <= r; i++)
    {
        //compare each element with principal element
        if (*(A + i) > *(A + p))
        {
            //exchange current element and principal element
            int temp = *(A + i);
            *(A + i) = *(A + r);
            *(A + r) = temp;
            r--;
            i--;
        }
    }
    //put the principal element to the proper index
    int temp = *(A + p);
    *(A + p) = *(A + r);
    *(A + r) = temp;
    return r;
}

