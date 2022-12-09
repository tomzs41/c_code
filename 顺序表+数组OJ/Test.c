//#include<stdio.h>
//
//// ����׳˵ݹ�Fac��ʱ�临�Ӷȣ�O��N��
//long long Fac(size_t N)
//{
//	if (0 == N)
//		return 1;
//
//	return Fac(N - 1)*N;
//}
//
//// ����쳲������ݹ�Fib��ʱ�临�Ӷȣ�O(2^N)
//long long Fib(size_t N)
//{
//	if (N < 3)
//		return 1;
//
//	return Fib(N - 1) + Fib(N - 2);
//}
//
//void f1()
//{
//	int a = 0;
//	printf("%p\n", &a);
//}
//
//void f2()
//{
//	int b = 0;
//	printf("%p\n", &b);
//}
//
//int main()
//{
//	//printf("%lld\n", Fac(10000));
//	//printf("%lld\n", Fib(20));
//	f1();
//	f2();
//
//
//	return 0;
//}

/////////////////////////////////////////////////////////////////////////////
#include "SeqList.h"

void TestSeqList1()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPrint(&sl);

	SLPushBack(&sl, 5);
	SLPrint(&sl);

	SLPushBack(&sl, 5);
	SLPushBack(&sl, 5);
	SLPushBack(&sl, 5);
	SLPushBack(&sl, 5);
	SLPrint(&sl);
}

void TestSeqList2()
{
	SL sl;
	SLInit(&sl);
	SLPushFront(&sl, 1);
	SLPushFront(&sl, 2);
	SLPushFront(&sl, 3);
	SLPushFront(&sl, 4);
	SLPushFront(&sl, 5);
	SLPrint(&sl);

	SLPushBack(&sl, 5);
	SLPushBack(&sl, 5);
	SLPrint(&sl);
}

void TestSeqList3()
{
	SL sl;
	SLInit(&sl);
	SLPushFront(&sl, 1);
	SLPushFront(&sl, 2);
	SLPushFront(&sl, 3);
	SLPushFront(&sl, 4);
	SLPushFront(&sl, 5);
	SLPrint(&sl);

	SLPopBack(&sl);
	SLPopBack(&sl);
	SLPopBack(&sl);
	SLPopBack(&sl);
	SLPopBack(&sl);
	//SLPopBack(&sl);
	SLPrint(&sl);

	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPrint(&sl);

	SLDestory(&sl);
}

void TestSeqList4()
{
	SL sl;
	SLInit(&sl);
	//SL* psl = NULL;
	//SLInit(psl);
	SLPushFront(&sl, 1);
	SLPushFront(&sl, 2);
	SLPushFront(&sl, 3);
	SLPushFront(&sl, 4);
	SLPushFront(&sl, 5);
	SLPrint(&sl);

	SLPopFront(&sl);
	SLPrint(&sl);

	SLPopFront(&sl);
	SLPopFront(&sl);
	SLPopFront(&sl);
	SLPopFront(&sl);
	//SLPopFront(&sl);
	SLPrint(&sl);

	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPrint(&sl);

	SLDestory(&sl);
}

void TestSeqList5()
{
	SL sl;
	SLInit(&sl);
	SLPushFront(&sl, 1);
	SLPushFront(&sl, 2);
	SLPushFront(&sl, 3);
	SLPushFront(&sl, 4);
	SLPushFront(&sl, 5);
	SLPrint(&sl);

	SLInsert(&sl, 3, 40);
	SLPrint(&sl);
	SLInsert(&sl, 0, 40);
	SLPrint(&sl);

	SLPushBack(&sl, 1000);
	SLPrint(&sl);

	SLDestory(&sl);
}

void TestSeqList6()
{
	SL sl;
	SLInit(&sl);
	SLPushFront(&sl, 1);
	SLPushFront(&sl, 2);
	SLPushFront(&sl, 3);
	SLPushFront(&sl, 4);
	SLPushFront(&sl, 5);
	SLPrint(&sl);

	SLErase(&sl, 2);
	SLPrint(&sl);
	SLErase(&sl, 0);
	SLPrint(&sl);
	SLErase(&sl, 2);
	SLPrint(&sl);

	SLPopFront(&sl);
	SLPrint(&sl);
	SLPopBack(&sl);
	SLPrint(&sl);
}

void TestSeqList7()
{
	SL sl;
	SLInit(&sl);
	SLPushFront(&sl, 1);
	SLPushFront(&sl, 2);
	SLPushFront(&sl, 2);
	SLPushFront(&sl, 3);
	SLPushFront(&sl, 2);
	SLPushFront(&sl, 4);
	SLPushFront(&sl, 5);
	SLPrint(&sl);

	//int x = 0;
	//printf("��������Ҫɾ����ֵ:");
	//scanf("%d", &x);
	//int pos = SLFind(&sl, x);
	//if (pos != -1)
	//{
	//	SLErase(&sl, pos);
	//}
	//else
	//{
	//	printf("û�ҵ�:%d\n", x);
	//}
	//SLPrint(&sl);

	int x = 0;
	printf("��������Ҫɾ����ֵ:");
	scanf("%d", &x);
	int pos = SLFind(&sl, x);
	while (pos != -1)
	{
		SLErase(&sl, pos);

		pos = SLFind(&sl, x);
	}
	SLPrint(&sl);

	int y, z;
	printf("��������Ҫ�޸ĵ�ֵ���޸ĺ��ֵ:");
	scanf("%d%d", &y, &z);
	pos = SLFind(&sl, y);
	if (pos != -1)
	{
		SLModify(&sl, pos, z);
	}
	else
	{
		printf("û�ҵ�:%d\n", y);
	}
	SLPrint(&sl);
}

//int main()
//{
//	 TestSeqList7();
//
//	// Խ���ǲ�һ�������
//	// ϵͳ��Խ��ļ�飬��ڳ�顣
//	//int a[10];
//	//a[0] = 0;
//	////a[10] = 1;
//	////a[11] = 1;
//	//a[12] = 1;
//	//a[15] = 1;
//
//	return 0;
//}

void menu()
{
	printf("****************************************\n");
	printf("1��β�� 2��ͷ��\n");
	printf("5������ 6��ɾ��\n");
	printf("7���޸� 8����ӡ\n");
	printf("-1���˳�\n");
	printf("****************************************\n");
}

int main()
{
	SL sl;
	SLInit(&sl);

	int option = -1;
	do
	{
		menu();
		if (scanf("%d", &option) == EOF)
		{
			printf("scanf�������\n");
			break;
		}

		int val, pos;
		int y, z;
		switch (option)
		{
		case 1:
			printf("������������Ҫβ������ݣ���0����:>");
			scanf("%d", &val);
			while (val != 0)
			{
				SLPushBack(&sl, val);
				scanf("%d", &val);
			}
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			printf("��������Ҫ�޸ĵ�ֵ���޸ĺ��ֵ:");
			scanf("%d%d", &y, &z);
			pos = SLFind(&sl, y);
			if (pos != -1)
			{
				SLModify(&sl, pos, z);
			}
			else
			{
				printf("û�ҵ�:%d\n", y);
			}
			break;
		case 8:
			SLPrint(&sl);
			break;
		default:
			printf("�������,����������\n");
			break;
		}
	} while (option != -1);

	SLDestory(&sl);

	return 0;
}