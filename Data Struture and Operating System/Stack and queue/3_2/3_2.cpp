// 3_2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 20

typedef struct
{
	int data[N];
	int front, rear;
}queue_type;

void init_queue(queue_type *q)
{
	int x;
	printf("\nPlease input the datas ended by 0:\n");
	scanf("%d", &x);
	while (x != 0)
	{
		q->data[q->rear] = x;
		q->rear = (q->rear + 1) % N;
		scanf("%d", &x);
	}
}

void show_queue(queue_type *q)
{
	int i = 0;
	for (i = q->front; i != q->rear;)
	{
		printf(" %d ", q->data[i]);
		i = (i + 1) % N;

	}
}

void enqueue(queue_type *q, int x)
{
	if ((q->rear + 1) % N == q->front)
	{
		printf("\nThe queue is full!\n");

	}
	else
	{
		q->data[q->rear] = x;
		q->rear = (q->rear + 1) % N;

	}
}

void dequeue(queue_type *q)
{
	if (q->front == q->rear)
	{
		printf("\nThe queue is empty!\n");

	}
	else
	{
		q->front = (q->front + 1) % N;
	}
}

void aa(queue_type *q)
{
	int i = q->front;
	int j = q->rear;
	while (i != j)
	{
		if (q->data[i]<0)
		{
			dequeue(q);
		}
		else
		{
			enqueue(q, q->data[i]);
			dequeue(q);
		}
		i = (i + 1) % N;
	}
}


int main()
{
	queue_type q;
	(&q)->data[N] = -1;
	(&q)->front = 0;
	(&q)->rear = 0;

	init_queue(&q);
	printf("\nPlease input the datas:\n");
	show_queue(&q);

	printf("\nAfter aa!\n");
	aa(&q);
	show_queue(&q);


    return(true);
}

