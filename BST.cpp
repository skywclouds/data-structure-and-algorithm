/*
二叉排序树
AuthorL Henry Wang
Date: 2021-9-17
*/

#include <iostream>

using namespace std;

struct node
{
	int val = 0;
	node* left = nullptr;
	node* right = nullptr;
};

/*创建二叉排序树*/
node* createBST(int* arr, int length);
/*查找二叉排序树中的元素*/
node* searchBST(node* BST, int num, node* last);
/*向二叉排序树中插入元素*/
void insertBST(node* BST, int num);
/*删除二叉排序树中的元素*/
void deleteBST(node** BST, int num);
/*deleteBST函数的辅助函数*/
void del(node** BST);
/*遍历二叉排序树*/
void visit(node* BST);

int main()
{
	int arr[] = { 70,105,115,104,67,46,99,111,109 };//创建一个数组
	node* tree = createBST(arr, sizeof(arr) / sizeof(int));//生成二叉排序树
	visit(tree);//遍历树
	cout << endl;
	node* find = searchBST(tree, 103, nullptr);//查找树中的元素
	cout << find->val << endl;
	insertBST(tree, 103);//向树中插入元素
	visit(tree);
	cout << endl;
	deleteBST(&tree, 103);//删除树中的元素
	visit(tree);
}

node* createBST(int* arr, int length)
{
	node* T = new node;
	node* head = T;
	T->val = *(arr);
	for (int i = 1; i < length; i++)//使用迭代的方法创建树
	{
		while (1)//不停地寻找可以加进去地的位置
		{
			if (*(arr + i) < T->val)//比当前节点小
			{
				if (T->left == nullptr)//如果当前节点的左节点为空，就加进去
				{
					node* temp = new node;
					temp->val = *(arr + i);
					T->left = temp;
					T = head;
					break;
				}
				else//如果非空，就继续向左
				{
					T = T->left;
				}
			}
			else//比当前节点大
			{
				if (T->right == nullptr)//如果当前节点的右节点为空，就加进去
				{
					node* temp = new node;
					temp->val = *(arr + i);
					T->right = temp;
					T = head;
					break;
				}
				else//如果非空，就继续向右
				{
					T = T->right;
				}
			}					
		}
	}
	return head;
}
void visit(node* BST)
{//中序遍历
	if (BST)
	{
		visit(BST->left);
		cout << BST->val << " ";
		visit(BST->right);
	}
}
node* searchBST(node* BST, int num, node* last)
{
	if (BST)
	{
		if (num == BST->val)
			return BST;//找到即返回
		else if (num < BST->val)//比当前元素小，向左找
			return searchBST(BST->left, num, BST);
		else//比当前元素大，向右找
			return searchBST(BST->right, num, BST);
	}
	else//找不到，就返回上一次访问的节点
	{
		return last;
	}
}
void insertBST(node* BST, int num)
{
	node* p = new node;
	p->val = num;
	node* t = searchBST(BST, num, nullptr);
	if (num < t->val)
		t->left = p;
	else if(num > t->val)
		t->right = p;
}
void deleteBST(node** BST, int num)
{
	if (num == (*BST)->val)	
		del(BST);	
	else if (num < (*BST)->val)
		deleteBST(&((*BST)->left), num);
	else
		deleteBST(&((*BST)->right), num);
	
}
void del(node** BST)
{
	if (!(*BST)->right)//如果要删的节点没有右子树，就把左子树接上
	{		
		(*BST) = (*BST)->left;	
	}
	else if (!(*BST)->left)//如果要删的节点没有左子树，就把右子树接上
	{
		(*BST) = (*BST)->right;
	}
	else//否则，找到左子树的最右节点
	{
		node* q = *BST;//左子树的最右节点的双亲节点
		node* r = (*BST)->left;//左子树的最右节点
		while (r->right)
		{
			q = r;
			r = r->right;
		}
		if (q == *BST)//如果左子树没有右节点，就把左子树的左节点接上
		{
			*(BST) = r;
		}
		else//否则就把左子树的最右节点接上
		{
			q->right = r->left;
			*(BST) = r;
		}
	}
		
}