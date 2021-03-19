/**
Date: 2021-3-19
Author: Henry wang
*/

#include <iostream>

using namespace std;

int main()
{
    cout << "Welcome!" <<endl;
    /**实现链表的类
    */
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };
    ListNode* l1 = new ListNode();
    ListNode* l2 = new ListNode();
    ListNode* record = l1;//记录链表起始位置的指针
    int n1, n2;
    cin >> n1 >> n2;
    while (n1 != 0)
    {//将数字加入链表
        ListNode* temp = new ListNode(n1 % 10);
        record->next = temp;
        record = record->next;
        n1 = n1 / 10;
    }
    record = l2;
    while (n2 != 0)
    {//将数字加入链表
        ListNode* temp = new ListNode(n2 % 10);
        record->next = temp;
        record = record->next;
        n2 = n2 / 10;
    }
    //由于头指针是不储存值，所以将头指针向后移动一格
    l1 = l1->next;
    l2 = l2->next;
    
    //以上代码用来把数字储存在链表里
    int num1 = 0;
    int num2 = 0;
    int t1 = 0, t2 = 0;
    record = l1;
    for (int i = 0;record!=NULL; i++)
    {//从链表提取数字
        int val = record->val;
        t1 = t1 * 10 + val;
        record = record->next;
    }
    record = l2;
    for (int i = 0; record != NULL; i++)
    {//从链表提取数字
        int val = record->val;
        t2 = t2 * 10 + val;
        record = record->next;
    }
    while (t1 != 0)
    {//反转数字
        num1 = num1 * 10 + t1 % 10;
        t1 = t1 / 10;
    }
    while (t2 != 0)
    {
        num2 = num2 * 10 + t2 % 10;
        t2 = t2 / 10;
    }
    int num = num1 + num2;
    record = l1;
    while (record != NULL)
    {//把结果插入到链表
        record->val = num % 10;
        num = num / 10;
        record = record->next;
    }
    record = l1;
    while (record != NULL)
    {//输出结果
        cout << record->val;
        record = record->next;
    }
    cout << endl;
}

