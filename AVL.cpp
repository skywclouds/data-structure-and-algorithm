/*
平衡二叉树
Author: Henry Wang
Date: 2021-9-21
*/

#include <iostream>

#define LH 1
#define EH 0
#define RH -1
using namespace std;

struct node
{
    int val = 0;
    int bf = 0;
    node* left = nullptr;
    node* right = nullptr;

};

/*创建平衡二叉树*/
void insertAVL(node** T, int num, int* taller);
/*平衡左子树*/
void leftBalance(node** T);
/*平衡右子树*/
void rightBalance(node** T);
/*右旋转*/
void R_Rotate(node** T);
/*左旋转*/
void L_Rotate(node** T);
/*遍历树*/
void visit(node* T);

int main()
{
    int arr[] = { 3,2,1,4,5,6,7,10,9,8 };
    node* tree = nullptr;
    int taller = 0;
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
        insertAVL(&tree, arr[i], &taller);
    visit(tree);
    cout << endl;
}

void insertAVL(node** T, int num, int* taller)
{
    if (!(*T))
    {
        *T = new node;
        (*T)->val = num;
        (*T)->bf = EH;
        *taller = 1;
    }
    else
    {
        if (num < (*T)->val)//小于当前节点就向左
        {
            insertAVL(&(*T)->left, num, taller);
            if (*taller)//如果树长高了
            {
                switch ((*T)->bf)
                {
                    case LH://左子树比右子树高
                        leftBalance(T);
                        taller = 0;
                        break;
                    case EH://左右子树等高
                        (*T)->bf = LH;
                        *taller = 1;
                        break;
                    case RH://右子树比左子树高
                        (*T)->bf = EH;
                        taller = 0;
                        break;
                }
            }
        }
        else//大于当前节点就向右
        {
            insertAVL(&(*T)->right, num, taller);
            if (*taller)//如果树长高了
            {
                switch ((*T)->bf)
                {
                    case LH://左子树比右子树高
                        (*T)->bf = EH;
                        *taller = 0;
                        break;
                    case EH://左右子树等高
                        (*T)->bf = RH;
                        *taller = 1;
                        break;
                    case RH://右子树比左子树高
                        rightBalance(T);
                        *taller = 0;
                        break;
                }
            }
        }
    }
}
void leftBalance(node** T)
{
    node* L = (*T)->left;
    node* Lr = L->right;
    switch (L->bf)
    {
        case LH://左子树的左子树比左子树的右子树高，就右旋
            (*T)->bf = EH;
            L->bf = EH;
            R_Rotate(T);
            break;
        case RH://考察左子树的左子树的右子树   
            switch (Lr->bf)
            {
                case LH:
                    (*T)->bf = RH;
                    L->bf = EH;
                    break;
                case EH:
                    (*T)->bf = EH;
                    L->bf = EH;
                    break;
                case RH:
                    (*T)->bf = EH;
                    L->bf = LH;
                    break;
            }
            Lr->bf = EH;
            L_Rotate(&(*T)->left);//把左子树左旋，再右旋
            R_Rotate(T);
            break;
        case EH://左子树的左子树和左子树的右子树一样高，也右旋
            (*T)->bf = LH;
            L->bf = RH;
            R_Rotate(T);
            break;
    }
}
void rightBalance(node** T)
{
    node* R = (*T)->right;
    node* Rl = R->left;
    switch (R->bf)
    {
    case RH:
        (*T)->bf = EH;
        R->bf = EH;
        L_Rotate(T);
        break;
    case LH:
        switch (Rl->bf)
        {
        case RH:
            (*T)->bf = RH;
            R->bf = EH;
            break;
        case EH:
            (*T)->bf = EH;
            R->bf = EH;
            break;
        case LH:
            (*T)->bf = EH;
            R->bf = RH;
            break;
        }
        Rl->bf = EH;
        R_Rotate(&(*T)->right);
        L_Rotate(T);
        break;
    case EH:
        (*T)->bf = RH;
        R->bf = LH;
        L_Rotate(T);
        break;
    }
}
void R_Rotate(node** T)
{
    node* p = (*T)->left;
    (*T)->left = p->right;
    p->right = *T;
    *T = p;
}
void L_Rotate(node** T)
{
    node* p = (*T)->right;
    (*T)->right = p->left;
    p->left = *T;
    *T = p;
}
void visit(node* T)
{
    if (T)
    {
        visit(T->left);
        cout << T->val << " ";
        if (T->left)
            cout << "left is " << T->left->val << " ";
        else
            cout << "no left ";
        if (T->right)
            cout << "right is " << T->right->val << " ";
        else
            cout << "no right ";
        cout << endl;
        visit(T->right);
    }
}