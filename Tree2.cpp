/*
Author: Henry Wang
Date: 2021-7-29
二叉树和二叉树的遍历
*/

#include <iostream>

using namespace std;

//二叉树中的节点
typedef struct BiTNode
{
    char data;
    BiTNode* lchild, * rchild;
}BiTNode,*BiTree;

/*前序遍历*/
void qianxu(BiTNode *node);
/*中序遍历*/
void zhongxu(BiTNode *node);
/*后序遍历*/
void houxu(BiTNode *node);

int main()
{
    BiTNode b2 = { 'B',nullptr,nullptr };
    BiTNode b3 = { 'C',nullptr,nullptr };
    BiTNode b1 = {'A',&b2,&b3};
    qianxu(&b1);
    cout << endl;
    zhongxu(&b1);
    cout << endl;
    houxu(&b1);
}

void qianxu(BiTNode *node)
{
    if (node)
    {
        cout << node->data;
        qianxu(node->lchild);
        qianxu(node->rchild);
    }
}
void zhongxu(BiTNode *node)
{
    if (node)
    {
        zhongxu(node->lchild);
        cout << node->data;
        zhongxu(node->rchild);
    }
}
void houxu(BiTNode *node)
{
    if (node)
    {
        houxu(node->lchild);
        houxu(node->rchild);
        cout << node->data;
    }
}