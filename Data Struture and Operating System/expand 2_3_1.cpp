// expand 2_3_1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdlib.h>
#include<stdio.h>

typedef struct Node
{
	int data;
	struct Node *next;
}Node;

typedef struct Link_list
{
	int length;
	Node *head;
}List;

void main()
{
	int i;
	int a[] = { 1, -4, -5, 14, -8, 55, -66, 78, 99, -111 };
	List *p;
	p = (List*)malloc(sizeof(List));
	Node *h, *m, *n;
	h = (Node*)malloc(sizeof(Node));
	n = (Node*)malloc(sizeof(Node));
	m = (Node*)malloc(sizeof(Node));
	p->head = (Node*)malloc(sizeof(Node));
	p->head->next = NULL;
	h = p->head;
	m = h->next;

	for (i = 0; i <= sizeof(a) / sizeof(a[0]); i++)
	{
		m = (Node*)malloc(sizeof(Node));
		m->data = a[i];
		m = m->next;
	}
	while (h->next != NULL)
	{
		if (h->next->data < 0)
		{
			h->next = h->next->next;
			n = h->next;
			free(n);
		}
		h = h->next;
	}
}

			

