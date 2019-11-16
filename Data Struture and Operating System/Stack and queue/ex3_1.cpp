// ex3_1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdlib.h>
#include<stdio.h>

#define FALSE 0
#define TRUE 1

typedef struct node
{
	int data;
	struct node *next;
}node_type;


void pushs(node_type** top, int x)
{
	node_type *p;
	p = (node_type*)malloc(sizeof(node_type));
	p->data = x;
	p->next = (*top);
	(*top) = p;
}

int pops(node_type **top)
{
	node_type *p;
	int x;
	if ((*top) == NULL)
	{
		printf("stack is underflow");
		return (NULL);
	}
	x = (*top)->data;
	p = (*top);
	(*top) = (*top)->next;
	free(p);
	return(x);
}


int main()
{
	node_type *top=NULL;
	int x;
	printf("Please input datas(input 0 to end): ");
	while (TRUE)
	{
		scanf("%d", &x);
		if (x == 0) break;
		pushs(&top, x);
	}
	

	node_type *p;
	p = top;
	while (p!= NULL)
	{
		printf("%d", p->data);
		p = p->next;
	}
	return TRUE;
}
