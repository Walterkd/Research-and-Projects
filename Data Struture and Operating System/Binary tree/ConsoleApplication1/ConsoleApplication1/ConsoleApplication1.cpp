// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define true 1
#define false 0

typedef struct bnode
{
	int data;
	struct bnode *lchild, *rchild;

}bnode_type;

typedef struct btree_type
{
	bnode_type *proot;
	int num;
}btree_type;

/*add a new bnode*/
bnode_type *add_bnode(bnode_type *q, int x)
{
	if (q == NULL)
	{
		q = (bnode_type*)malloc(sizeof(bnode_type));
		q->data = x;
		q->lchild = NULL;
		q->rchild = NULL;

	}
	else
	{
		if (q->data > x)
		{
			q->lchild = add_bnode(q->lchild, x);
		}
		else
		{
			q->rchild = add_bnode(q->rchild, x);

		}
	}
	return q;
}

/*Create a btree*/
void Creat_btree(btree_type *mytree)
{
	int i = 0, x = 0;
	printf("\nPlease input the numbers of the btree:\n");
	scanf("%d", &(mytree->num));
	for (; i < mytree->num; i++)
	{
		printf("\nPlease input the %d number:\n", i + 1);
		scanf("%d", &x);
		mytree->proot = add_bnode(mytree->proot, x);
	}
}

/*先序遍历*/
void preorder(bnode_type *p)
{
	if (p == NULL)
		return;
	else
	{
		printf(" %d ", p->data);
		if (p->lchild != NULL) preorder(p->lchild);
		if (p->rchild != NULL) preorder(p->lchild);
	}
}

/*中序遍历*/
void inorder(bnode_type *p)
{
	if (p == NULL)
		return;
	else
	{
		if (p->lchild != NULL) inorder(p->lchild);
		printf(" %d ", p->data);
		if (p->rchild != NULL) inorder(p->rchild);
		printf(" %d ", p->data);

	}
}

/*后序遍历*/
void postorder(bnode_type *p)
{
	if (p == NULL)
	{
		return;
	}
	else
	{
		if (p->lchild != NULL) postorder(p->lchild);
		if (p->rchild != NULL) postorder(p->rchild);
		printf(" %d ", p->data);

	}
}

int depth_btree(bnode_type *p)
{
	int dl = 0;
	int dr = 0;
	if (p == NULL)
	{
		return 0;
	}
	else
	{
		if (p->lchild != NULL)
			dl = depth_btree(p->lchild);
		if (p->rchild != NULL)
			dr = depth_btree(p->rchild);
		return(dl > dr ? dl + 1 : dr + 1);

	}
}

void Irexchange(bnode_type *p)
{
	if (p != NULL)
	{
		bnode_type *temp = NULL;
		temp = p->lchild;
		p->lchild = p->rchild;
		p->rchild = temp;
		Irexchange(p->lchild);
		Irexchange(p->rchild);

	}
}


int main()
{
	int x = 0;
	btree_type mytree;
	(&mytree)->num = 0;
	(&mytree)->proot = NULL;

	printf("\n init btree:\n");
	Creat_btree(&mytree);

	inorder((&mytree)->proot);

	preorder((&mytree)->proot);

	postorder((&mytree)->proot);

	printf("\nPlease input the bnode:\n");
	scanf("%x", &x);
	(&mytree)->proot = add_bnode((&mytree)->proot, x);
	inorder((&mytree)->proot);

	printf("\nThe depth of the tree:%d\n", depth_btree((&mytree)->proot));

	Irexchange((&mytree)->proot);
	printf("\nThe tree after exchanging:\n");
	inorder((&mytree)->proot);




	return(true);
}

