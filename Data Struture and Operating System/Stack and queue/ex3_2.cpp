// ex3_2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdlib.h>
#include<string.h>

#define N 20
typedef struct
{
	int data[N];
	int front, rear;
}queue_type;

int enqueue(queue_type *q, int x)
{
	if (q->rear >= N)
		return(0);
	else
	{
		q->rear = q->rear + 1;
		q->data[q->rear] = x;
		return(1);
	}
}

int dequeue(queue_type *q)
{
	if (q->rear == q->front)
		return(0);
	else
	{
		q->front = q->front + 1;
		return(q->data[q->front]);
	}
}


void show_queue(queue_type *q)
{
	int i = 0, length;
	if (q->rear >= q->front)
		length = q->rear - (q->front);
	else
	{
		length = N - (q->front) + (q->rear);
	}
	for (; i <= length; i++)
	{
		printf("%d\n", q->data[i]);
	}
}

void aa(queue_type *q)
{
	int x, i, length;
	if (q->rear >= q->front)
		length = (q->rear) - (q->front);
	else
	{
		length = N - (q->front) + (q->rear);
	}
	show_queue(q);
	for (i = 0; i <= length; i++)
	{
		x = dequeue(q);
		if (x > 0)
			enqueue(q, x);
	}

}

int main()
{
	int i = 0;
	queue_type *q;
	q = (queue_type*)malloc(sizeof(queue_type));
	q->front = 0;
	q->rear = 0;
	int a[] = { 2, 3, -4, 6, -5, 8, -9, 7, -10, 20 };
	for (; i < (sizeof(a[i] / a[0])); i++)
	{
		enqueue(q, a[i]);
	}
	show_queue(q);
	aa(q);
	show_queue(q);

}

