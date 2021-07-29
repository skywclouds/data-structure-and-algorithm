/*
Author: Henry Wang
Date:2021-7-28
树的基本知识
*/

#define MAX_TREE_SIZE 100
#include <iostream>

using namespace std;

//孩子节点
typedef struct CTNode
{
    int child;
    struct CTNode* next;
} *ChildPtr;

//节点
typedef struct
{
    char data;
    int parent;
    ChildPtr firstchild;
} CTBox;

//树
typedef struct
{
    CTBox nodes[MAX_TREE_SIZE];//节点数组
    int r, n;//根的位置和节点数
} MyTree;

int main()
{
    MyTree t;
    cout << "helloworld" << endl;
    
}
