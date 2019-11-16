// expand 2_2_2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
}Listnode;
typedef struct List {
	Node *head;
	int length;
}listtype;

void create_List()
{
	int x;
	listtype *p;
	Node *h;
	h = p->head;
	p->head = (Node*)malloc(sizeof(Node));
	p->head->next = NULL;
	scanf("%d", &x);
	while (x)
	{
		scanf("%d", &x);
		h->next = (Node*)malloc(sizeof(Node));
		h->next->data = x;
		h = h->next;

	}


}

void show_list(Node *h, listtype *p)
{
	h = p->head->next;
	while (1)
	{
		printf(" %d ", h->data);
		if (h->next == NULL) break;
			h = h->next;
	}

}
void recreate_list(Node *h, listtype *p)
{
	Node *m;
	h = p->head->next;
	int x;
	scanf("%d", &x);
	while (x != h->next->data&&h->next != NULL)
	{
		h = h->next;
	}
	if (x == h->next->data)
	{
		show_list(h, p);
		m = h->next;
		h->next = h->next->next;
		free(m);
		show_list(h, p);
	}
	else
	{
		show_list(h, p);
		h->next = (Node*)malloc(sizeof(Node*));
		h->next->data = x;
		show_list(h, p);
	}
	




}
