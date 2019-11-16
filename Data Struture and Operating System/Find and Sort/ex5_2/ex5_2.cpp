// ex5_2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
char c[30][50];


int Hash(char * cp)
{
	int n, i;
	int sum = 0;
	n = strlen(cp);
	for (i = 0; i < n; i++)
	{
		sum += (int)*cp;
		cp++;
	}
    return (sum % 30); 
}

int find(char * des)
{
	int ini = Hash(des);
	int end = ((ini - 1)%30+30)%30;
	while (ini != end)
	{
		if ((des) == c[ini])
		{
			printf("Search success:");
			return ini + 1;
		}
		ini = (ini + 1)%30;
	}
	printf("Search failed:");
	return FALSE;
}

int main()
{
	int num;
	char name[50];
	printf("Please input the numbers of the students:\n");
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		printf("input:\n");
		scanf("%s", name);
		int ini = Hash(name);
		while (c[ini][0] != '\0')
		{
			ini = (ini + 1) % 30;
		}
		strcpy(c[ini], name);
	}
	printf("input finished.");
	while (1)
	{
		printf("Please input the name you want to find:\n");
		scanf("%s", name);
		printf("%d\n", find(name));
	}
	return 0;

}