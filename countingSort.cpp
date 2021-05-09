/*
Author: Henry Wang
Date: 2021-5-9
counting sort
*/

#include <iostream>
#include <vector>

using namespace std;

/*counting sort
*/
void countingSort(int* A, int length);

int main()
{
    cout << "Hello World!" << endl;
    int arr[] = {5,4,3,2,1};
    countingSort(arr, sizeof(arr) / sizeof(int));
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)    
        cout << arr[i] << " ";    
    cout << endl;
}

void countingSort(int* A, int length)
{
    int max = *(A);
    for (int i = 1; i < length; i++)
        if (max < *(A + i))       
            max = *(A + i);
    //get the maximum of the array
    vector<int> v;
    for (int i = 0; i <= max; i++)    
        v.push_back(0);
    for (int i = 0; i < length; i++)   
        v[*(A + i)]++;
    for (int i = 1; i <= max; i++)    
        v[i] += v[i - 1];
    //the function of this for loop is to get the sum of 
    //the top i element of the array.
    vector<int> arr;
    for (int i = 0; i < length; i++)     
        arr.push_back(0);    
    for (int i = length - 1; i >= 0; i--)
    {
        arr[v[*(A + i)] - 1] = *(A + i);
        v[*(A + i)]--;
        //put elements into proper index
    }
    for (int i = 0; i < length; i++)    
        *(A + i) = arr[i];   
}
