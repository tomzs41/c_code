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

int main()
{
	TestSeqList2();

	return 0;
}