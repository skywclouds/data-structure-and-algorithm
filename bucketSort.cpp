/*
* Author: Henry Wang
* Date: 2021-5-11
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
    for (int i = 1; i < v.size(); i++)    
        if (v[i] > max)        
            max = v[i];//find the maximum              
    struct list
    {
        int val;
        list* next;
        list() : val(0), next(nullptr) {}
        list(int x) : val(x), next(nullptr) {}
        list(int x, list* n) : val(x), next(nullptr) {}
    };
    vector<list*> arr;
    for (int i = 0; i <= max/5; i++)    
        arr.push_back(new list());   
    for (int i = 0; i < v.size(); i++)
    {
        int index = v[i] / 5;        
        list* temp = arr[index];
        while (temp->next != nullptr)
        {
            if (temp->next->val > v[i])
            {                
                list* l = temp->next;
                temp->next = new list(v[i]);
                temp->next->next = l;
                break;
            }
            temp = temp->next;   
        }
        if (temp->next == nullptr)                   
            temp->next = new list(v[i]);       
        //put value into buckets by insertion sort
    }
    v.clear();
    for (int i = 0; i < arr.size(); i++)
    {
        list* temp = arr[i];
        while (temp->next != nullptr)
        {            
            v.push_back(temp->next->val);
            temp = temp->next;
        }
    }
}