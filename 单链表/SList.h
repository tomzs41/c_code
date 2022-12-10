#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

SLTNode* BuySListNode(SLTDataType x);
void SListPrint(SLTNode* phead);
void SListPushBack(SLTNode** pphead, SLTDataType x);
void SListPushFront(SLTNode** pphead, SLTDataType x);
void SListPopBack(SLTNode** pphead);
void SListPopFront(SLTNode** pphead);
SLTNode* SListFind(SLTNode* phead, SLTDataType x);

// ��posλ��֮ǰ����
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
// ɾ��posλ�õ�ֵ
void SListErase(SLTNode** pphead, SLTNode* pos);


