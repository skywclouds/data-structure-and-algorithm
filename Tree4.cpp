/*
Author: Henry Wang
Date: 2021-7-30
线索二叉树
*/

#include <iostream>

using namespace std;

/*二叉树的节点*/
struct BiTNode
{
    char data;
    int ltag;
    int rtag;
    BiTNode *lchild;
    BiTNode* rchild;
};

/*当前被遍历到的节点*/
BiTNode* current;

/*中序遍历二叉树*/
void visit(BiTNode* node);

/*将二叉树线索化*/
void InThreading(BiTNode* node);

int main()
{
    BiTNode b1{ 'I',0,0,nullptr,nullptr };
    BiTNode b2{ 'H',0,0,nullptr,nullptr };
    BiTNode b3{ 'G',0,0,nullptr,nullptr };
    BiTNode b4{ 'F',0,0,nullptr,nullptr };
    BiTNode b5{ 'E',0,0,nullptr,nullptr };
    BiTNode b6{ 'D',0,0,&b2,&b1 };
    BiTNode b7{ 'C',0,0,&b4,&b3 };
    BiTNode b8{ 'B',0,0,&b6,&b5 };
    BiTNode b9{ 'A',0,0,&b8,&b7 };
    visit(&b9);//创建一棵树并遍历
    InThreading(&b9);//将二叉树线索化

}

void visit(BiTNode* node)
{
    if (node)
    {
        visit(node->lchild);
        cout << node->data;
        visit(node->rchild);        
    }
}

void InThreading(BiTNode* node)
{
    if (node)
    {
        InThreading(node->lchild);
        node->ltag = node->lchild ? 0 : 1;//有孩子是0，没孩子是1
        node->rtag = node->rchild ? 0 : 1;
        //current是前驱节点，所以若ltag为1，则lchild指向current
        if (node->ltag)
            node->lchild = current;
        //当前节点是current的后继节点，所以若current的rtag为1，则current的rchild指向当前节点
        if (current && current->rtag)
            current->rchild = node;
        //更新current指针
        current = node;
        InThreading(node->rchild);
    }
}