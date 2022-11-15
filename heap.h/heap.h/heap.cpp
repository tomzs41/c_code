//#include<heap.h>
// С��
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int size_t;
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	size_t size;
	size_t capacity;
}HP;
void HeapInit(HP* php) {
	assert(php);
	php->a = NULL;
	php->size = php->capacity = 0;
}
void HeapDestory(HP* php) {
	assert(php);
	free(php->a);
	php->a = NULL;
	php->size = php->capacity = 0;
}
void swap(HPDataType* pa, HPDataType* pb) {
	HPDataType* tmp = *pa;
	*pa = *pb;
	*pb = *tmp;
}
void heapprint(HP* php) {
	assert(php);
	for(size_t i = 0; i < php->size; ++i) {
		printf("%d", php->a[i]);
	}
	printf("\n");
}
void AdjustUp(HPDataType* a, size_t child) {
	size_t parent = (child - 1) / 2;
	while (child > 0) {
		if (a[child] < a[parent]) {
			swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else break;
	}
}
void HeapPush(HP* php, HPDataType x) {
	assert(php);
	if (php->size == php->capacity) {
		size_t newCapacity = php->capacity == 0 ? 4: php->capacity * 2;
		HPDataType* tmp = realloc(php->a, sizeof(HPDataType) * newCapacity);
		if (tmp == NULL) {
			if (tmp == NULL) {
				printf("realloc failed");
				exit(-1);
			}
			php->a = tmp;
			php->capacity = newCapacity;
		}
	}
	php->a[php->size] = x;
	++php->size;
	AdjustUp(php->a, php->size - 1);
}




void AdjustDown(HPDataType* a, size_t size, size_t root)
{
	size_t parent = root;
	size_t child = parent * 2 + 1;
	while (child < size)
	{
		// 1��ѡ�����Һ�����С���Ǹ�
		if (child + 1 < size && a[child + 1] < a[child])
		{
			++child;
		}

		// 2���������С�ڸ��ף��򽻻������������µ���
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

// ɾ���Ѷ������ݡ�(��С/���)
void HeapPop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	Swap(&php->a[0], &php->a[php->size - 1]);
	--php->size;

	AdjustDown(php->a, php->size, 0);
}

bool HeapEmpty(HP* php)
{
	assert(php);

	return php->size == 0;
}

size_t HeapSize(HP* php)
{
	assert(php);

	return php->size;
}

HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	return php->a[0];
}



void Swap(HPDataType* pa, HPDataType* pb);
void HeapInit(HP* php);
void HeapDestroy(HP* php);
void HeapPrint(HP* php);

// ����x�Ժ󣬱�����������(��/С)��
void HeapPush(HP* php, HPDataType x);

// ɾ���Ѷ������ݡ�(��С/���)
void HeapPop(HP* php);
bool HeapEmpty(HP* php);
size_t HeapSize(HP* php);
HPDataType HeapTop(HP* php);


// ����ָ�����Ķ�
//#define N 5
//struct TreeNode
//{
//	int data;
//	struct TreeNode* subs[N];  // ָ������
//};

// ��֪�����Ķ�
//struct TreeNode
//{
//	int data;
//	// ˳���溢�ӵ�ָ��
//	//SeqList _sl; // SLDateType -> struct TreeNode*
//	// vector<struct TreeNode*> _subs; C++
//};

//// �����ֵܱ�ʾ��
//typedef int DataType;
//struct TreeNode
//{
//	struct TreeNode* firstChild;    // ��һ�����ӽ��
//	struct TreeNode* pNextBrother;  // ָ������һ���ֵܽ��
//	DataType data;                  // ����е�������
//};

void TestHeap()
{
	HP hp;
	HeapInit(&hp);
	HeapPush(&hp, 1);
	HeapPush(&hp, 5);
	HeapPush(&hp, 0);
	HeapPush(&hp, 8);
	HeapPush(&hp, 3);
	HeapPush(&hp, 9);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	HeapDestroy(&hp);
}

// ���� O(N*logN)   1000*10    100w*20
//      O(N*N)      1000*1000  100w*100w
// O(N)�ռ临�Ӷȣ�����Ҫ���Ż�--�½ڿ���������
void HeapSort(int* a, int size)
{
	HP hp;
	HeapInit(&hp);
	for (int i = 0; i < size; ++i)
	{
		HeapPush(&hp, a[i]);
	}

	size_t j = 0;
	while (!HeapEmpty(&hp))
	{
		a[j] = HeapTop(&hp);
		j++;
		HeapPop(&hp);
	}

	HeapDestroy(&hp);
}

int main()
{
	//TestHeap();
	int a[] = { 4, 2, 7, 8, 5, 1, 0, 6 };
	HeapSort(a, sizeof(a) / sizeof(int));

	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}