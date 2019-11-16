#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100

typedef int KeyType;
typedef struct	/*元素的定义*/
{
	KeyType key;
}DataType;
typedef struct	/*顺序表的类型定义*/
{
	DataType list[MaxSize];
	int length;
}SSTable;

int SeqSearch(SSTable S, DataType x);
int BinarySearch(SSTable S, DataType x);

void main()
{
	SSTable S1 = { { 265, 55, 15, 67, 9, 64, 88, 50 }, 8 };
	SSTable S2 = { { 20, 28, 37, 40, 46, 55, 64, 76 }, 8 };

	DataType x = { 64 };
	int pos;
	if ((pos = SeqSearch(S1, x)) != 0)
		printf("顺序表的查找：关键字64在主表中的位置是：%2d\n", pos);
	else
		printf("查找失败！\n");
	if ((pos = BinarySearch(S2, x)) != 0)
		printf("折半查找：关键字64在主表中的位置是：%2d\n", pos);
	else
		printf("查找失败！\n");
	
}
int SeqSearch(SSTable S, DataType x)
/*在顺序表中查找关键字为x的元素，如果找到返回该元素在表中的位置，否则返回0*/
{
	int i = 0;
	while (i<S.length&&S.list[i].key != x.key) /*从顺序表的第一个元素开始比较*/
		i++;
	if (S.list[i].key == x.key)
		return i + 1;
	else
		return 0;
}
int BinarySearch(SSTable S, DataType x)
/*在有序顺序表中折半查找关键字为x的元素，如果找到返回该元素在表中的位置，否则返回0*/
{
	int low, high, mid;
	low = 0, high = S.length - 1;			/*设置待查找元素范围的下界和上界*/
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (S.list[mid].key == x.key)	/*如果找到元素，则返回该元素所在的位置*/
			return mid + 1;
		else if (S.list[mid].key<x.key)/*如果mid所指示的元素小于关键字，则修改low指针*/
			low = mid + 1;
		else if (S.list[mid].key>x.key)/*如果mid所指示的元素大于关键字，则修改high指针*/
			high = mid - 1;
	}
	return 0;
}
