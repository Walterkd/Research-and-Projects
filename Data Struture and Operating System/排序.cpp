#include "stdio.h"
#include "string.h"
#include "stdlib.h"

/*  冒泡排序（The bubble sort）  */
void bubble(char *items, int count)
{
	register int a, b;
	register char t;

	for (a = 1; a<count; ++a)
	{
		for (b = count - 1; b >= a; --b)
		{
			if (items[b - 1]>items[b])		/*exchange elements*/
			{
				t = items[b - 1];
				items[b - 1] = items[b];
				items[b] = t;
			}

		}
		printf("%s\n", items);
	}
}

/*抖动排序（shaker sort）*/
void shaker(char *items, int count)
{
	register int a;
	int exchange;
	char t;

	do
	{
		exchange = 0;
		for (a = count - 1; a>0; --a)
		{
			if (items[a - 1]>items[a])		/*exchange elements*/
			{
				t = items[a - 1];
				items[a - 1] = items[a];
				items[a] = t;
				exchange = 1;
			}

		}
		for (a = 1; a<count; ++a)
		{
			if (items[a - 1]>items[a])		/*exchange elements*/
			{
				t = items[a - 1];
				items[a - 1] = items[a];
				items[a] = t;
				exchange = 1;
			}

		}  printf("%s\n", items);
	} while (exchange);	/*sort until no exchange take place*/
}

/*选择排序（The Selection Sort）*/
void select(char *items, int count)
{
	register int a, b, c;
	int exchange;
	char t;
	for (a = 0; a<count - 1; ++a)
	{
		exchange = 0;
		c = a;
		t = items[a];
		for (b = a + 1; b<count; ++b)
		{
			if (items[b]<t)
			{
				c = b;
				t = items[b];
				exchange = 1;
			}

		}

		if (exchange)
		{
			items[c] = items[a];
			items[a] = t;
		}
		printf("%s\n", items);
	}
}

/*插入排序（The Insertion Sort）*/
void insert(char *items, int count)
{
	register int a, b;
	char t;

	for (a = 1; a<count; ++a)
	{
		t = items[a];
		for (b = a - 1; (b >= 0) && (t<items[b]); b--)
			items[b + 1] = items[b];
		items[b + 1] = t;
		printf("%s\n", items);
	}
}

/*谢尔排序（Shell Sort）*/
void shell(char *items, int count)
{
	register int i, j, gap, k;
	char x, a[5];
	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

	for (k = 0; k<5; k++)
	{
		gap = a[k];
		for (i = gap; i<count; ++i)
		{
			x = items[i];
			for (j = i - gap; (x<items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];

			items[j + gap] = x;
		}
		printf("%s\n", items);
	}
}

int main(void)
{
	char s[255];
	int i;
	printf("                     常用排序算法集合          \n");
	printf("\n");
	printf("                                                                   开发人员：   \n");
	printf("                                                                          2017年  10月10日   \n");

	printf("Please enter a string:");
	gets_s(s);
	printf("\n");
	printf("\nPlease selec the sort:\n");
	printf("  1:The Bubble Sort;\n");
	printf("  2:The Shaker Sort;\n");
	printf("  3:The Selection Sort;\n");
	printf("  4:The Insertion Sort;\n");
	printf("  5:The Shell Sort;\n");
	scanf_s("%d", &i);



	switch (i)
	{
	case 1:
		bubble(s, strlen(s));
		break;
	case 2:
		shaker(s, strlen(s));
		break;
	case 3:
		select(s, strlen(s));
		break;
	case 4:
		insert(s, strlen(s));
		break;
	case 5:
		shell(s, strlen(s));
		break;

	default:break;
	}
	getchar();

}