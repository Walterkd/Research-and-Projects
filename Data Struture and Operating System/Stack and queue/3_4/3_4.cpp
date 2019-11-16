// 3_4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXNUM 5
#define true 1
#define false 0

typedef struct ExtQueue
{
	int flag;
	int front;
	int rear;
	int data[MAXNUM];

}queue_type;

void en_queue(queue_type *q, int x)
{
	if (q->flag == 0)
	{
		if (((q->rear) + 1) % MAXNUM != q->front)
		{
			q->data[q->rear] = x;
			q->rear = (q->rear + 1) % MAXNUM;
		}
		else if (((q->rear) + 1) % MAXNUM == q->front)
		{
			q->data[q->rear] = x;
			q->rear = (q->rear + 1) % MAXNUM;
			q->flag = 1;

		}
		else
			return;
	}
	else if (q->flag == 1)
		printf("\nThe list is full!\n");
}

void init_queue(queue_type *q)
{
	int x = 0;
	printf("\nPlease input the number you want to input:\n");
	scanf("%d", &x);
	while (x != -1)
	{
		en_queue(q, x);
		if (q->flag == 1)
		{
			printf("\nThis list is full!\n");
			break;
		}
		scanf("%d", &x);
	}
}

void pop_queue(queue_type *q)
{
	if (q->flag == 0)
	{
		if (q->front == q->rear)
		{
			printf("\nThis queue is empty!\n");

		}
		else
		{
			printf("\n %d is poped out of the queue!\n", q->data[q->front]);
			q->front = (q->front + 1) % MAXNUM;

		}
	}
	else if (q->flag == 1)
	{
		printf("\n %d is poped out of the queue!\n", q->data[q->front]);
		q->front = (q->front + 1) % MAXNUM;
		q->flag = 0;
	}
}


int main()
{
	int x = 0;
	queue_type q;
	(&q)->rear = 0;
	(&q)->front = 0;
	(&q)->flag = 0;

	init_queue(&q);

	printf("\nPlease input the number you want to input:\n");
	scanf("%d", &x);
	en_queue(&q,x);

	pop_queue(&q);
	pop_queue(&q);
	pop_queue(&q);

	printf("\nPlease input the number you want to input:\n");
	scanf("%d", &x);
	en_queue(&q, x);
	printf("\nPlease input the number you want to input:\n");
	scanf("%d", &x);
	en_queue(&q, x);
	printf("\nPlease input the number you want to input:\n");
	scanf("%d", &x);
	en_queue(&q, x);
	printf("\nPlease input the number you want to input:\n");
	scanf("%d", &x);
	en_queue(&q, x);

	pop_queue(&q);
	pop_queue(&q);
	pop_queue(&q);
	pop_queue(&q);
	pop_queue(&q);
	pop_queue(&q);
	pop_queue(&q);

	printf("\nPlease input the number you want to input:\n");
	scanf("%d", &x);
	en_queue(&q, x);
	printf("\nPlease input the number you want to input:\n");
	scanf("%d", &x);
	en_queue(&q, x);

    return(true);
}

