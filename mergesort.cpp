/**
Author: Henry Wang
Date: 2021-4-18
mergesort
*/

#include <iostream>
#include <vector>

using namespace std;

/*main algorithm
*/
void mergesort(int* A, int p, int q);
/*Auxiliary algorithm
*/
void merge(int* A, int p, int r, int q);

int main()
{
    int A[] = {5,2,3,4,1,7,6};//create an array
    mergesort(A, 0, sizeof(A)/sizeof(int)-1);//mergesort
    for (int i = 0; i < sizeof(A) / sizeof(int); i++)
    {
        cout << A[i];//show array
    }
    cout << endl;
}

void mergesort(int* A, int p, int q)
{
    if (p < q)
    {
        int r = (p + q) / 2;//the middle index
        mergesort(A, p, r);//the left
        mergesort(A, r + 1, q);//the end
        merge(A, p, r, q);//merge the two parts
    }
}
void merge(int* A, int p, int r, int q)
{
    //create three vectors to store numbers
    vector<int> v1;
    vector<int> v2;
    for (int k = p; k <= r; k++)    
        v1.push_back(*(A + k));//store left    
    for (int k = r + 1; k <= q; k++)   
        v2.push_back(*(A + k));//store right   
    //merge the two parts
    int i = 0, j = 0;
    for (int k = p; k <= q; k++)
    {
        if (i == v1.size())
        {
            *(A + k) = v2[j];
            j++;
        }
        else if (j == v2.size())
        {
            *(A + k) = v1[i];
            i++;
        }
        else
        {
            if (v1[i] < v2[j])
            { 
                *(A + k) = v1[i];
                i++;
            }
            else
            {
                *(A + k) = v2[j];
                j++;
            }                   
        }
    }
}
