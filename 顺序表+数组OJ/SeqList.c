#include "SeqList.h"

void SLPrint(SL* ps)
{
	assert(ps != NULL);
	//assert(ps);

	for (int i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SLInit(SL* ps)
{
	assert(ps != NULL);

	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SLDestory(SL* ps)
{
	assert(ps != NULL);

	if (ps->a)
	{
		free(ps->a);
		ps->a = NULL;
		ps->capacity = ps->size = 0;
	}
}


void SLCheckCapacity(SL* ps)
{
	assert(ps != NULL);

	// 检查容量空间，满了扩容
	if (ps->size == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newCapacity*sizeof(SLDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			//exit(-1);
			return;
		}

		ps->a = tmp;
		ps->capacity = newCapacity;
	}
}

void SLPushBack(SL* ps, SLDataType x)
{
	/*assert(ps != NULL);

	SLCheckCapacity(ps);

	ps->a[ps->size] = x;
	ps->size++;*/

	SLInsert(ps, ps->size, x);
}

void SLPushFront(SL* ps, SLDataType x)
{
	//assert(ps != NULL);

	//SLCheckCapacity(ps);

	//// 挪动数据
	//int end = ps->size - 1;
	//while (end >= 0)
	//{
	//	ps->a[end + 1] = ps->a[end];
	//	--end;
	//}

	//ps->a[0] = x;
	//ps->size++;

	SLInsert(ps, 0, x);
}

void SLPopBack(SL* ps)
{
	//assert(ps != NULL);

	////ps->a[ps->size - 1] = 0;
	//// 温柔检查
	///*if (ps->size == 0)
	//{
	//	printf("SeqList is empty\n");
	//	return;
	//}*/

	//// 暴力检查
	//assert(ps->size > 0);

	//ps->size--;

	SLErase(ps, ps->size - 1);
}

void SLPopFront(SL* ps)
{
	/*assert(ps != NULL);
	assert(ps->size > 0);

	int begin = 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		++begin;
	}

	ps->size--;*/

	SLErase(ps, 0);
}

void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);

	SLCheckCapacity(ps);

	// 挪动数据
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}

	ps->a[pos] = x;
	ps->size++;
}

void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);

	//int begin = pos;
	//while (begin < ps->size-1)
	//{
	//	ps->a[begin] = ps->a[begin + 1];
	//	++begin;
	//}

	int begin = pos + 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		++begin;
	}

	ps->size--;
}

int SLFind(SL* ps, SLDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; ++i)
	{
		if (ps->a[i] == x)
			return i;
	}

	return -1;
}

void SLModify(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);

	ps->a[pos] = x;
}