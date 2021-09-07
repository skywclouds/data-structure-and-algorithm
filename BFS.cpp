/*
广度优先搜索
Author:Henry Wang
Date: 2021-9-7
*/
#include <iostream>

using namespace std;

int g[5][5];//储存图的矩阵
int b[5];//储存各个节点是否被访问过

struct node//队列
{
    int num{ 0 };
    node* next{ nullptr };
};
node* head = new node;//头节点
/*获取队列的尾节点*/
node* getEnd(node* node);
/*广度优先搜索*/
void BFS(int n);

int main()
{
    g[0][1] = 1; g[1][0] = 1;
    g[1][2] = 1; g[2][1] = 1;
    g[1][4] = 1; g[4][1] = 1;
    g[2][3] = 1; g[3][2] = 1;
    BFS(0);
}

node* getEnd(node* n)
{
    node* no = n;
    while (no->next)
        no = no->next;
    return no;
}
void BFS(int n)
{
    node* no = new node;//将该点加入队列
    no->num = n;
    head->next = no;
    while (head->next)
    {
        node* c = head->next;//取出队列中第一个节点
        b[c->num] = 1;//设置该节点已经访问过
        cout << (char)('A' + c->num);//输出该节点
        //将该节点的所有子节点全部加入队列
        for (int i = 0; i < 5; i++)
        {
            if (g[c->num][i] && b[i] == 0)
            {
                node* temp = new node;
                temp->num = i;
                getEnd(head)->next = temp;
            }
        }
        head->next = c->next;//将队列的首节点删去
    }
    
}
