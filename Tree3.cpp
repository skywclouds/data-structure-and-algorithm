/*
Author: Henry Wang
Date:2021-7-29
二叉树的建立
*/

#include <iostream>
#include <cstdio>

using namespace std;

/*二叉树的节点*/
struct BiTNode
{
    char data;
    BiTNode *lchild, *rchild;
};

/*创建二叉树*/
BiTNode* createBiTree();

/*前序遍历二叉树*/
void qianxu(BiTNode* T);

int main()
{
    BiTNode b1;
    BiTNode *b = createBiTree();
    qianxu(b);
}

BiTNode* createBiTree()
{
    BiTNode* T;//创建一个节点
    char c;
    scanf_s("%c", &c);
    if (c == '#')
        T = nullptr;//遇到#即终止
    else
    {
        T = (BiTNode *)malloc(sizeof(BiTNode));//给节点分配内存
        T->data = c;
        T->lchild = createBiTree();//初始化左孩子
        T->rchild = createBiTree();//初始化右孩子
    }
    return T;//返回当前节点
}
void qianxu(BiTNode* T)
{
    if (T)
    {
        cout << T->data;
        qianxu(T->lchild);
        qianxu(T->rchild);
    }
}