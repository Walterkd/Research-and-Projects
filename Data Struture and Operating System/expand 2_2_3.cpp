// expand 2_2_3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node *next;
}Node;

typedef struct Link_list
{
	int length;
	Node *head;
}Link_list;

void main()
{
	int i;
	int x = 66;
	int a[] = { 1, 3, 5, 6, 9, 14, 19, 24, 28, 36, 56, 78, 89 };
	Link_list *p;
	p = (Link_list*)malloc(sizeof(Link_list*));
	p->head =(Node*)malloc(sizeof(Node*));
	p->head->next = NULL;
	Node *h, *m, *n;
	h = p->head;
	m = p->head;
	for (i = 0; i <= sizeof(a) / sizeof(a[0]); i++)
	{
		h->next = (Node*)malloc(sizeof(Node*));
		h->next->data = a[i];
		h = h->next;
	}
	while (x >= m->next->data&&m->next != NULL)
	{
		m = m->next;
	}
	n = (Node*)malloc(sizeof(Node*));
	n->data = x;
	if (x < (m->next->data))
	{
		n->next = m ->next;
		m->next = n;
	}
	if (m->next == NULL)
	{
		m->next = n;
	}

}
