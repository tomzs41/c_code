#include "SeqList.h"

void SLPrint(SL* ps)
{
	for (int i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SLInit(SL* ps)
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SLCheckCapacity(SL* ps)
{
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
	SLCheckCapacity(ps);

	ps->a[ps->size] = x;
	ps->size++;
}

void SLPushFront(SL* ps, SLDataType x)
{
	SLCheckCapacity(ps);

	// 挪动数据
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}

	ps->a[0] = x;
	ps->size++;
}