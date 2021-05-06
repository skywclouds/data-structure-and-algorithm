/*
Author: Henry Wang
Date: 2021-5-6
mergeKLists
*/
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

/*merge the lists
*/
ListNode* mergeKLists(vector<ListNode*>& lists);

int main()
{
    ListNode* l11 = new ListNode(1);
    ListNode* l12 = new ListNode(4);
    ListNode* l13 = new ListNode(5);
    l11->next = l12;
    l13->next = l13;
    ListNode* l21 = new ListNode(1);
    ListNode* l22 = new ListNode(3);
    ListNode* l23 = new ListNode(4);
    l21->next = l22;
    l22->next = l23;
    ListNode* l31 = new ListNode(2);
    ListNode* l32 = new ListNode(6);
    l31->next = l32;
    vector<ListNode*> lists;
    lists.push_back(l11);
    lists.push_back(l21);
    lists.push_back(l31);
    ListNode* head = mergeKLists(lists);
    while (head != nullptr)
    {
        cout << head->val <<" ";
        head = head->next;
    }
    cout << endl;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* head = new ListNode();//the head pointer 
    ListNode* end = head;//end pointer of the list
    while(true) 
    {
        int index = -1;
        //find the first non-null pointer
        for (int i = 0; i < lists.size(); i++)       
            if (lists[i] != nullptr)
            {
                index = i;
                break;
            }
        //if all pointers are null,exit
        if (index == -1)
            break;
        //find the minimum of the vector
        for (int i = index + 1; i < lists.size(); i++)
            if(lists[i] != nullptr)
                if (lists[i]->val < lists[index]->val)                
                    index = i;                                            
        //lengthen the list
        end->next = lists[index];
        end = end->next;
        lists[index] = lists[index]->next;
    }
    return head->next;
}

