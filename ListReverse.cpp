/**
Date: 2021-3-18
Author: henry wang
*/

#include <iostream>

using namespace std;

/**main函数
*/
int main()
{
    cout << "Welcome!" << endl;
    /**实现单链表的struct
    */
    struct ListNode
    {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };
    ListNode l[20];//创建一个单链表
    for (int i = 0; i < 19; i++)
    {
        l[i].val = i + 1;
        l[i].next = &l[i + 1];

    }
    l[19].val = 20;
    //l[19].next = NULL;
    ListNode* p = l;//获取头部指针
    cout << endl;
    cout << "please input:" << endl;
    int left, right;//反转的区间
    cin >> left >> right;
    if (left != right) //若左端点等于右端点，则什么都不用做
    {
        //若左端点恰好是是第一个元素，那么会非常麻烦，所以
        //这里在最前面加上一个新的元素就可以解决这个问题
        ListNode s;
        ListNode* start = &s;
        start->next = p;
        left++; right++;//加入新的元素后，左右端点均需加一
        ListNode* preleftp = start;//左端点前驱元素的指针
        for (int i = 1; i < left - 1; i++)
        {
            preleftp = preleftp->next;
        }
        ListNode* leftp = preleftp->next;//左端点指针
        ListNode* rightp = leftp;//右端点指针
        for (int i = left; i < right; i++)
        {
            rightp = rightp->next;
        }
        //进行反转操作时，需要三个指针，分别为：
        //当前正在操作的元素，该元素的前驱元素和后继元素的指针
        ListNode* pre = leftp;
        ListNode* index = leftp->next;
        ListNode* succ = index->next;
        while (index != rightp)//执行反转操作，直到达到右端点
        {
            index->next = pre;
            pre = index;
            index = succ;
            succ = succ->next;
        }
        //最后一次反转操作在while循环里未能执行
        index->next = pre;
        //将左端点的后继元素设置为原来右端点的后继元素
        //若右端点为最后一个元素，则其值自然为null
        leftp->next = succ;
        //将左端点的前驱元素的后继元素设置为原来的右端点
        preleftp->next = index;
        //将最前端加上去的元素删除
        p = start->next;

    }
    while (p != NULL)//输出单链表中元素
    {
        cout << p->val << " ";
        p = p->next;
    }
}