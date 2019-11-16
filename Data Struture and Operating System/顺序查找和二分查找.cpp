#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100

typedef int KeyType;
typedef struct	/*Ԫ�صĶ���*/
{
	KeyType key;
}DataType;
typedef struct	/*˳�������Ͷ���*/
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
		printf("˳���Ĳ��ң��ؼ���64�������е�λ���ǣ�%2d\n", pos);
	else
		printf("����ʧ�ܣ�\n");
	if ((pos = BinarySearch(S2, x)) != 0)
		printf("�۰���ң��ؼ���64�������е�λ���ǣ�%2d\n", pos);
	else
		printf("����ʧ�ܣ�\n");
	
}
int SeqSearch(SSTable S, DataType x)
/*��˳����в��ҹؼ���Ϊx��Ԫ�أ�����ҵ����ظ�Ԫ���ڱ��е�λ�ã����򷵻�0*/
{
	int i = 0;
	while (i<S.length&&S.list[i].key != x.key) /*��˳���ĵ�һ��Ԫ�ؿ�ʼ�Ƚ�*/
		i++;
	if (S.list[i].key == x.key)
		return i + 1;
	else
		return 0;
}
int BinarySearch(SSTable S, DataType x)
/*������˳������۰���ҹؼ���Ϊx��Ԫ�أ�����ҵ����ظ�Ԫ���ڱ��е�λ�ã����򷵻�0*/
{
	int low, high, mid;
	low = 0, high = S.length - 1;			/*���ô�����Ԫ�ط�Χ���½���Ͻ�*/
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (S.list[mid].key == x.key)	/*����ҵ�Ԫ�أ��򷵻ظ�Ԫ�����ڵ�λ��*/
			return mid + 1;
		else if (S.list[mid].key<x.key)/*���mid��ָʾ��Ԫ��С�ڹؼ��֣����޸�lowָ��*/
			low = mid + 1;
		else if (S.list[mid].key>x.key)/*���mid��ָʾ��Ԫ�ش��ڹؼ��֣����޸�highָ��*/
			high = mid - 1;
	}
	return 0;
}
