/*
* Author: Henry Wang
* Date: 2021-5-7
* bucket sort
*/

#include <iostream>
#include <vector>

using namespace std;

/*bucket sort
*/
void bucketSort(vector<int> &v, int length);

int main()
{
    vector<int> v;
    for (int i = 0; i < 20; i++)
    {
        v.push_back(20 - i);
    }
    bucketSort(v, v.size());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

}

void bucketSort(vector<int>& v, int length)
{
    int max = v[0];
    for (int i = 1; i < length; i++)
        if (v[i] > max)        
            max = v[i];//find the maximum of the array
    vector<int> arr;
    for (int i = 0; i <= max; i++)
        arr.push_back(0);//create a new array of length 10
    for (int i = 0; i < length; i++)   
        arr[v[i]]++;//count each number
    int index = 0;
    for (int i = 0; i <= max; i++)   
        for (int j = 0; j < arr[i]; j++)
        {
            v[index] = i;
            index++;//sort the array according to the count
        }    
}