/*ʵ��11.2.4  ���е���ʽ��ʾ��ʵ��*/
#include<stdio.h>
#include<stdlib.h>
#define ElemType int
typedef struct Qnode
{
	ElemType data;
	struct Qnode *next;
}Qnodetype;
typedef struct
{
	Qnodetype *front;
	Qnodetype *rear;
}Lqueue;
void Lappend(Lqueue *q, int x);
/*��ʼ��������������*/
void creat(Lqueue *q)
{
	Qnodetype *h;
	int i, n, x;
	printf("���뽫����������Ԫ�صĸ�����n= ");
	scanf_s("%d", &n);
	h = (Qnodetype*)malloc(sizeof(Qnodetype));
	h->next = NULL;
	q->front = h;
	q->rear = h;
	for (i = 1; i <= n; i++)
	{
		printf("�����е�%d��Ԫ�ص�ֵΪ��", i);
		scanf_s("%d", &x);
		Lappend(q, x);
	}
}
/*��������*/
void Lappend(Lqueue *q, int x)
{
	Qnodetype *s;
	s = (Qnodetype*)malloc(sizeof(Qnodetype));
	s->data = x;
	s->next = NULL;
	q->rear->next = s;
	q->rear = s;
}
/*��������*/
ElemType Ldelete(Lqueue *q)
{
	Qnodetype *p;
	ElemType x;
	if (q->front == q->rear)
	{
		printf("����Ϊ��!\n");
		return 0;
	}
	else
	{
		p = q->front->next;
		q->front->next = p->next;
		if (p->next == NULL)
			q->rear = q->front;
		x = p->data;
		free(p);
	}
	printf("��������Ԫ�أ�%d\n", x); return(x);
}
/*����������*/
void display(Lqueue *q)
{
	Qnodetype *p;
	p = q->front->next;      /*ָ���һ������Ԫ�ؽڵ� */
	if (!p)	printf("����Ϊ��!\n");
	else
	{
		printf("\n������Ԫ������Ϊ��");
		while (p != NULL)
		{
			printf("%d-->", p->data);
			p = p->next;
		}
		printf("\n\n���������н����� \n");
	}
}
void main()
{
	Lqueue *p;
	int x, cord;
	p = (Lqueue *)malloc(sizeof(Lqueue));
	printf("\n*****��һ�β�����ѡ���ʼ�������������У�*****\n ");
	do
	{
		printf("=================���˵� ===================\n");
		printf("      1    ��ʼ��������������     \n");
		printf("      2    ��������               \n");
		printf("      3    ��������               \n");
		printf("      4    ����������             \n");
		printf("      5    ������������           \n");
		printf("==========================================\n");
		scanf_s("%d", &cord);
		switch (cord)
		{
		case 1:
		{	creat(p);
		display(p);
		}break;
		case 2:
		{	printf("���������Ԫ�ص�ֵ��x=");
		scanf_s("%d", &x);
		Lappend(p, x);
		display(p);
		}break;
		case 3:
		{	Ldelete(p);
		display(p);
		}break;
		case 4:
		{display(p); }break;
		case 5:
		{exit(0); }
		}
	} while (cord <= 5);
}

